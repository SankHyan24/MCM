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
    // read from file
    ifstream fin(filename);
    for (int i = 0; i < 28; i++)
        Array[i] = i;
    for (int i = 0; i < 28 * 28; i++)
        fin >> Matrix[i];
    fin.close();
    cout << "read from file" << endl;
    if (Acceptable())
        cout << "Acceptable" << endl;
    else
        cout << "Not Acceptable" << endl;
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
    {
        // cout << "Error: duplicate array" << endl;
        return false;
    }
    for (int i = 0; i < 28 * 28; i++)
        if (Matrix[i] > maxn[i])
        {
            // cout << "Error: matrix value overflow at" << i / 28 << " row " << i % 28 << " column" << endl;
            // cout << "maxn:" << maxn[i] << endl;
            // cout << "Matrix:" << Matrix[i] << endl;
            return false;
        }
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
