// Simulate Annealing
#pragma once
#include <solution.hpp>
using namespace RandomUtils;
using namespace std;
class Simuanneal
{
public:
    Simuanneal(arr Arr, mat Mat, int max_iter, double temp_init, double temp_final, double alpha);
    ~Simuanneal();
    void run();

private:
    Solution *RandomNeighbor(const Solution &solution);
    Solution GenRandomSolution();
    bool Acceptable(const Solution &solution_neighbor);
    void PrintState() const;
    void PrintResult() const;

    Solution *solution;
    int max_iteration_num;
    int now_iteration_num{0};
    double temperature;
    double init_temperature;
    double final_temperature;
    double alpha; // cooling rate
};