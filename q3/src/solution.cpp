#include <solution.hpp>
#include <fstream>
#include <set>
using namespace std;
int maxn[28 * 28];
bool Solution::init_maxn = false;
Solution::Solution(arr array, mat matrix)
{
    if (!init_maxn)
    {
        maxn_init();
        init_maxn = true;
    }
    this->Array = array;
    this->Matrix = matrix;
}
Solution::Solution(const string &filename)
{
    if (!init_maxn)
    {
        maxn_init();
        init_maxn = true;
    }
    ifstream fin(filename);
    for (int i = 0; i < 28; i++)
        fin >> Array[i];
    for (int i = 0; i < 28 * 28; i++)
        fin >> Matrix[i];
    fin.close();
    if (!Acceptable())
        throw "Not Acceptable";
}
Solution::Solution(const Solution &solution)
{
    if (!init_maxn)
    {
        maxn_init();
        init_maxn = true;
    }
    this->Array = solution.Array;
    this->Matrix = solution.Matrix;
}
Solution::~Solution()
{
}
bool Solution::Acceptable()
{
    set<int> s;
    for (int i = 0; i < 28; i++)
        s.insert(Array[i]);
    if (s.size() != 28)
        return false;
    for (int i = 0; i < 28 * 28; i++)
        if (Matrix[i] > maxn[i] || Matrix[i] < 0)
            return false;
    return true;
}

void Solution::maxn_init()
{
    ifstream fin("../data/maxn.txt");
    for (int i = 0; i < 28 * 28; i++)
        fin >> maxn[i];
    fin.close();
}

double Solution::GetFitness() const
{
    double fitness = 0;
    for (int i = 0; i < 28; i++)
        for (int j = 0; j < 28; j++)
            fitness += Matrix.get_value(i, j) * Array.get_cost(i, j);
    return fitness;
}
