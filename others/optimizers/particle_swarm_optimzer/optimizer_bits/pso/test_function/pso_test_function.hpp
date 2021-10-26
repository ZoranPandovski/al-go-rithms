
#ifndef OPTIMIZER_BITS_PSO_TEST_FUNCTION_PSO_TEST_FUNCTION_HPP
#define OPTIMIZER_BITS_PSO_TEST_FUNCTION_PSO_TEST_FUNCTION_HPP

namespace optimization
{

namespace testFunction
{

class PSOTestFunction
{
public:
  /**
    * PSOTestFunction is the function which we will optimize.
    * 
    * @param vecSpace Vector space of the function.
    * @param minFuncRange Minimum range of function in every dimension
    *                     of it's vector space.
    * @param maxFuncRange Maximum range of function in every dimension
    *                     of it's vector space.
    */
  PSOTestFunction(const size_t vecSpace,
                  double *minFuncRange,
                  double *maxFuncRange) : vecSpace(vecSpace),
                                          minFuncRange(minFuncRange),
                                          maxFuncRange(maxFuncRange)
  {
    /* Nothing to do here*/
  }

  /**
    * Evalute function calculate and returns the function value 
    * at given position.
    * 
    * @param position Current position of the particle.
    * @return Value of the function at the current position.
    */
  double Evaluate(double *position)
  {
    double eval = 0.0;

    for (size_t i = 0; i < vecSpace; i++)
    {
      eval += position[i] * position[i];
    }

    return eval;
  }

  //! Return1 1 (the number of functions).
  size_t NumFunctions() const { return 1; }

  //! Get the starting point.
  double *GetInitialPoint() const
  {
    double *initialPoint = new double[vecSpace];

    for (size_t j = 0; j < vecSpace; ++j)
    {
      initialPoint[j] = minFuncRange[j] +
                        static_cast<double>(rand()) /
                            (static_cast<double>(RAND_MAX / (maxFuncRange[j] - minFuncRange[j])));
    }

    return initialPoint;
  }

  // Get vector space of function.
  size_t getVecSpace() const { return vecSpace; }

  // Modify vector space of function.
  size_t getVecSpace() { return vecSpace; }

  // Get minimum range of function in every dimension
  // of it's vector space.
  double *getMinFuncRange() const { return minFuncRange; }

  // Modify minimum range of function in every dimension
  // of it's vector space.
  double *getMinFuncRange() { return minFuncRange; }

  // Get maximum range of function in every dimension
  // of it's vector space.
  double *getMaxFuncRange() const { return maxFuncRange; }

  // Modify maximum range of function in every dimension
  // of it's vector space.
  double *getMaxFuncRange() { return maxFuncRange; }

private:
  // vector space of function.
  size_t vecSpace;

  // Minimum range of function in every dimension
  // of it's vector space.
  double *minFuncRange;

  // Maximum range of function in every dimension
  // of it's vector space.
  double *maxFuncRange;
};

} // namespace testFunction
} // namespace optimization

#endif // OPTIMIZER_BITS_PSO_TEST_FUNCTION_PSO_TEST_FUNCTION_HPP