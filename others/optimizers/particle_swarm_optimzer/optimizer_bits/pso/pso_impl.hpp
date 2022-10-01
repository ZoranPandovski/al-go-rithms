
#ifndef OPTIMIZER_BITS_PSO_PSO_IMPL_HPP
#define OPTIMIZER_BITS_PSO_PSO_IMPL_HPP

namespace optimization
{

PSO::PSO(const size_t maxIter,
         const size_t swarmSize,
         double inertia,
         const double inertiaDrop,
         const double c1,
         const double c2) : maxIter(maxIter),
                            swarmSize(swarmSize),
                            inertia(inertia),
                            inertiaDrop(inertiaDrop),
                            c1(c1),
                            c2(c2)
{
    /* Nothing to do here. */
}

double PSO::Optimize(PSOTestFunction function,
                     double *iterate)
{
    static const size_t vecSpace = function.getVecSpace();

    struct globalBest
    {
        double *position = new double[vecSpace];
        double cost = INFINITY;
    } gBest;

    struct personalBest
    {
        double *position = new double[vecSpace];
        double cost = INFINITY;
    };

    struct Particle
    {
        double *position = new double[vecSpace];
        double *velocity = new double[vecSpace];
        double cost;
        personalBest pBest;
    };

    Particle swarm[swarmSize];

    const double *minVal = function.getMinFuncRange();
    const double *maxVal = function.getMaxFuncRange();

    for (size_t i = 0; i < swarmSize; ++i)
    {
        for (size_t j = 0; j < vecSpace; j++)
        {
            // Random position in range [varMin, varMax].
            swarm[i].position[j] = minVal[j] +
                                   static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (maxVal[j] - minVal[j])));
            swarm[i].velocity[j] = 0.0;
        }

        swarm[i].cost = function.Evaluate(swarm[i].position);

        // Update the personal best.
        for (size_t j = 0; j < vecSpace; j++)
        {
            swarm[i].pBest.position[j] = swarm[i].position[j];
        }

        swarm[i].pBest.cost = swarm[i].cost;

        // Update global best.
        if (swarm[i].pBest.cost < gBest.cost)
        {
            gBest.cost = swarm[i].pBest.cost;

            for (size_t j = 0; j < vecSpace; j++)
            {
                gBest.position[j] = swarm[i].pBest.position[j];
            }
        }
    }

    for (size_t itr = 0; itr < maxIter; ++itr)
    {
        for (size_t i = 0; i < swarmSize; ++i)
        {
            for (size_t j = 0; j < vecSpace; ++j)
            {
                // r1 and r2 lie in [0, 1].
                double r1 = ((double)rand() / (RAND_MAX));
                double r2 = ((double)rand() / (RAND_MAX));

                swarm[i].velocity[j] = (inertia * swarm[i].velocity[j]) +
                                       (r1 * c1 * (swarm[i].pBest.position[j] - swarm[i].position[j])) +
                                       (r2 * c2 * (gBest.position[j] - swarm[i].position[j]));

                swarm[i].position[j] += swarm[i].velocity[j];
            }

            swarm[i].cost = function.Evaluate(swarm[i].position);

            // Update personal best.
            if (swarm[i].cost < swarm[i].pBest.cost)
            {
                swarm[i].pBest.cost = swarm[i].cost;

                for (size_t j = 0; j < vecSpace; j++)
                {
                    swarm[i].pBest.position[j] = swarm[i].position[j];
                }

                // Update global best.
                if (swarm[i].pBest.cost < gBest.cost)
                {
                    gBest.cost = swarm[i].pBest.cost;

                    for (size_t j = 0; j < vecSpace; j++)
                    {
                        gBest.position[j] = swarm[i].pBest.position[j];
                    }
                }
            }
        }

        inertia *= inertiaDrop;
    }

    for (size_t j = 0; j < vecSpace; j++)
    {
        iterate[j] = gBest.position[j];
    }

    return gBest.cost;
}

} // namespace optimization

#endif // OPTIMIZER_BITS_PSO_PSO_IMPL_HPP