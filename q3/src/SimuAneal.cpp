#include <SimuAneal.hpp>
#include <set>
inline int cast_from_double_to_int(double s, double e, double t)
{
    // cout << "number is " << std::floor((tmp > 1.0 ? 1.0 : tmp) * 26) + 1;
    return rand() % 5;
}
Simuanneal::Simuanneal(arr Arr, mat Mat, int max_iter, double temp_init, double temp_final, double alpha)
{
    this->solution = solution;
    this->max_iteration_num = max_iter;
    this->temperature = temp_init;
    this->init_temperature = temp_init;
    this->final_temperature = temp_final;
    this->alpha = alpha;
    solution = new Solution(Arr, Mat);
}
Simuanneal::~Simuanneal()
{
}
Solution *Simuanneal::RandomNeighbor(const Solution &solution)
{
    Solution *solution_neighbor = nullptr;
    // Solution *solution_neighbor = new Solution(solution.GetArray(), solution.GetMatrix());
    bool accept = false, road_choose = RandomUtils::Randomint(0, 27) > 20;
    if (!road_choose)
    {
        arr tmp_arr = solution.GetArray();
        tmp_arr.RandOneStep();
        solution_neighbor = new Solution(tmp_arr, solution.GetMatrix());
    }
    else
        while (!accept)
        {
            delete solution_neighbor;
            mat tmp_mat = solution.GetMatrix();
            for (int i = 0; i < cast_from_double_to_int(init_temperature, final_temperature, temperature); i++)
                tmp_mat.RandOneStep();
            solution_neighbor = new Solution(solution.GetArray(), tmp_mat);
            accept = solution_neighbor->Acceptable();
        }
    return solution_neighbor;
}

void Simuanneal::run()
{
    now_iteration_num = 0;
    temperature = init_temperature;
    Solution *solution_neighbor = nullptr;
    while (now_iteration_num < max_iteration_num && temperature > final_temperature)
    {
        solution_neighbor = RandomNeighbor(*solution);
        if (Acceptable(*solution_neighbor))
        {
            delete solution;
            solution = solution_neighbor;
        }
        else
        {
            delete solution_neighbor;
        }
        temperature *= alpha;
        PrintState();
        now_iteration_num++;
    }
    delete solution_neighbor;
    cout << "Running done" << endl;
    PrintResult();
}

bool Simuanneal::Acceptable(const Solution &solution_neighbor)
{
    if (solution_neighbor.GetFitness() < solution->GetFitness())
        return true;
    else
    {
        double p = RandomUtils::RandomFloat(0.0, 1.0);
        if (p < std::exp((solution->GetFitness() - solution_neighbor.GetFitness()) / temperature))
            return true;
        else
            return false;
    }
}

void Simuanneal::PrintResult() const
{
    std::cout << "The best solution is: " << std::endl;
    solution->print();
    std::cout << "The best fitness is: " << solution->GetFitness() << std::endl;
}

void Simuanneal::PrintState() const
{
    std::cout << "Iteration: " << now_iteration_num << std::endl;
    std::cout << "Temperature: " << temperature << std::endl;
    // std::cout << "The best solution is: " << std::endl;
    // solution->print();
    std::cout << "The best fitness is: " << solution->GetFitness() << std::endl
              << std::endl;
}