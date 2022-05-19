#include <SimuAneal.hpp>
#include <set>
inline int cast_from_double_to_int(double s, double e, double t)
{
    return rand() % 10;
}
Simuanneal::Simuanneal(arr Arr, mat Mat, int max_iter, ld temp_init, ld temp_final, ld alpha)
{
    this->solution = solution;
    this->max_iteration_num = max_iter;
    this->temperature = temp_init;
    this->init_temperature = temp_init;
    this->final_temperature = temp_final;
    this->alpha = alpha;
    this->reheat_limit = max_iter / 100;
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
    converse_num = 0;
    temperature = init_temperature;
    Solution *solution_neighbor = nullptr;
    while (now_iteration_num < max_iteration_num && temperature > final_temperature && reheat_flag < reheat_repeat_max)
    {
        if (converse_num > reheat_limit)
        {
            reheat_flag++;
            converse_num = 0;
            temperature = init_temperature / 10;
        }
        solution_neighbor = RandomNeighbor(*solution);
        if (Acceptable(*solution_neighbor))
        {
            delete solution;
            solution = solution_neighbor;
            temperature *= alpha;
            PrintState();
            now_iteration_num++;
        }
        else
            delete solution_neighbor;
    }
    delete solution_neighbor;
    cout << "Running done" << endl;
    PrintResult();
}

bool Simuanneal::Acceptable(const Solution &solution_neighbor)
{
    double fitness = solution->GetFitness();
    double n_fitness = solution_neighbor.GetFitness();
    current_fitness = fitness;
    if (n_fitness < best_fitness)
    {
        best_fitness = n_fitness;
        best_mat = solution_neighbor.GetMatrix();
        best_arr = solution_neighbor.GetArray();
        converse_num = 0;
        reheat_flag = 0;
    }
    else
        converse_num++;
    if (n_fitness < fitness)
        return true;
    else
    {
        double p = RandomUtils::Randomfloat(0.0, 1.0);
        if (p < std::exp((fitness - n_fitness) / temperature))
            return true;
        else
            return false;
    }
}

void Simuanneal::PrintResult() const
{
    std::cout << "The best fitness is: " << best_fitness << std::endl;
    std::cout << "The best solution is: " << std::endl;
    cout << "Array:" << endl;
    best_arr.print();
    cout << "Matrix:" << endl;
    best_mat.print();
}

void Simuanneal::PrintState() const
{
    std::cout << "\033[2J\033[0;0H";
    std::cout << "Iteration: " << now_iteration_num << std::endl;
    std::cout << "Temperature: " << temperature << std::endl;
    std::cout << "The current fitness is: " << current_fitness << std::endl;
    std::cout << "The best fitness is: " << best_fitness << std::endl;
}