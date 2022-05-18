// Simulate Annealing
#pragma once
#include <solution.hpp>
typedef long double ld;
using namespace std;
class Simuanneal
{
public:
    Simuanneal(arr Arr, mat Mat, int max_iter, ld temp_init, ld temp_final, ld alpha);
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
    int converse_num{0};
    int reheat_limit{0}; // if the converse num is bigger than this limit, then reheat
    int reheat_flag{0};  // the count of reheat 如果连续reheat_repeat_max次加热没有改变，则停止
    const int reheat_repeat_max{3};
    ld temperature;
    ld init_temperature;
    ld final_temperature;
    ld alpha; // cooling rate

    double best_fitness{__DBL_MAX__};
    double current_fitness{__DBL_MAX__};
    mat best_mat;
    arr best_arr;
};
// 如果converse_num大于reheat_limit，则重新加热
// 如果连续3次加热最小值没有改变，则停止