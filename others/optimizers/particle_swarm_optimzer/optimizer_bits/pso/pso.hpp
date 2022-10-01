
#ifndef OPTIMIZER_BITS_PSO_PSO_HPP
#define OPTIMIZER_BITS_PSO_PSO_HPP

#include "test_function/pso_test_function.hpp"
#define INFINITY 100000.0

using namespace optimization::testFunction;

namespace optimization
{

class PSO
{
public:
  /**
    * Constructs the PSO optimizer. The defaults here are not
    * necessarily good for the given problem, so it is
    * suggested that the values used be tailored to the task at hand.
    * 
    * @param maxIter Maximum no of iterations.
    * @param swarmSize Swarm population size.
    * @param inertia Inertia Coefficient.
    * @param inertiaDrop Damping ratio of inertia coefficient.
    * @param c1 Personal acceleration coeff.
    * @param c2 Global acceleration coeff.
    */
  PSO(const size_t maxIter = 1000,
      const size_t swarmSize = 50,
      double inertia = 1.0,
      const double inertiaDrop = 0.95,
      const double c1 = 2.0,
      const double c2 = 2.0);

  /**
    * Optimize function optimizes the given function.
    * 
    * @ function Function to optimize
    * @ iterate Iterate contains the optimized values for
    *           the function.
    */
  double Optimize(PSOTestFunction function,
                  double *iterate);

  // Get maximum no of iterations.
  size_t getMaxIter() const { return maxIter; }

  // Modify maximum no of iterations.
  size_t getMaxIter() { return maxIter; }

  // Get swarm population size.
  size_t getSwarmSize() const { return swarmSize; }

  // Modify swarm population size.
  size_t getSwarmSize() { return swarmSize; }

  // Get inertia coeff.
  double getInertia() const { return inertia; }

  // Modify inertia coeff.
  double getInertia() { return inertia; }

  // Get damping ratio of inertia coeff.
  double getInertiaDrop() const { return inertiaDrop; }

  // Modify damping ratio of inertia coeff.
  double getInertiaDrop() { return inertiaDrop; }

  // Get personal acceleration coeff.
  double getC1() const { return c1; }

  // Modify personal acceleration coeff.
  double getC1() { return c1; }

  // Get global acceleration coeff.
  double getC2() const { return c2; }

  // Modify global acceleration coeff.
  double getC2() { return c2; }

private:
  // maximum no of iterations.
  size_t maxIter;

  // Swarm population size.
  size_t swarmSize;

  // Inertia coeff.
  double inertia;

  // Damping ratio of inertia coeff.
  double inertiaDrop;

  // Personal acceleration coeff.
  double c1;

  // Global acceleration coeff.
  double c2;
}; //class PSO

} // namespace optimization

#include "pso_impl.hpp"

#endif // OPTIMIZER_BITS_PSO_PSO_HPP