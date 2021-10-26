#include "../optimizer.hpp"

using namespace std;
using namespace optimization;
using namespace optimization::testFunction;

int main()
{
    srand(time(0));

    const size_t vecSpace = size_t(2);
    double *minFuncRange = new double[vecSpace];
    double *maxFuncRange = new double[vecSpace];

    for (size_t i = 0; i < vecSpace; ++i)
    {
        minFuncRange[i] = -10.0;
        maxFuncRange[i] = 10.0;
    }

    PSOTestFunction func(vecSpace, minFuncRange, maxFuncRange);

    // array of variables needed to be optimized.
    double *iterate = func.GetInitialPoint();

    PSO optimizer(100, 25, 1.0, 0.99, 1.5, 1.5);
    double cost = optimizer.Optimize(func, iterate);

    cout << "\nminimum value : \n [ ";
    for (size_t j = 0; j < vecSpace; j++)
    {
        cout << iterate[j] << " ,";
    }
    cout << "]\n final cost : " << cost;

    return 0;
}
