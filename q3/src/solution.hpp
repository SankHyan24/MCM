#pragma once
#include <iostream>
#include <set>
#include <utility.hpp>
using namespace std;

const int CASE_NUM = 28;
const double ROAD_RATE = 1.0 / 28; // 这里需要重新估算
extern int maxn[28 * 28];
struct arr
{
    int a[28];
    int &operator[](int i) { return a[i]; }
    void RandOneStep()
    {
        int chx[2], cnt = 0, tmp;
        set<int> s;
        while (s.size() != 2)
            s.insert(RandomUtils::Randomint(0, 27));
        for (auto i : s)
            chx[cnt++] = i;
        tmp = a[chx[0]];
        a[chx[0]] = a[chx[1]];
        a[chx[1]] = tmp;
    }
    int get_cost(int x, int y) const
    {
        int dis = (a[x] - a[y]) < 0 ? a[y] - a[x] : a[x] - a[y];
        return dis / 7 + dis % 7;
    }
    void print() const
    {
        for (int i = 0; i < CASE_NUM; i++)
            cout << a[i] << " ";
        cout << endl;
    }
};

struct mat
{
    int m[28 * 28];
    int &operator[](int i) { return m[i]; }
    void RandOneStep()
    {
        int chx[6], cnt = 0;
        set<int> rand6_set;
        while (rand6_set.size() != 6)
        {
            if (rand6_set.size() <= 2)
            {
                int tmp = RandomUtils::Randomint(0, 26);
                rand6_set.insert(tmp);
            }
            else
            {
                int tmp = RandomUtils::Randomint(0, 27);
                rand6_set.insert(tmp);
            }
        }
        for (auto i : rand6_set)
            chx[cnt++] = i;
        m[chx[0] * 28 + chx[1]]--;
        m[chx[0] * 28 + chx[4]]++;
        m[chx[1] * 28 + chx[2]]--;
        m[chx[1] * 28 + chx[5]]++;
        m[chx[3] * 28 + chx[4]]--;
        m[chx[3] * 28 + chx[1]]++;
        m[chx[4] * 28 + chx[5]]--;
        m[chx[4] * 28 + chx[2]]++;
    }
    int get_value(int x, int y) const
    {
        return m[x * 28 + y];
    }
    void print() const
    {
        for (int i = 0; i < 28; i++)
        {
            for (int j = 0; j < 28; j++)
                cout << m[i * 28 + j] << " ";
            cout << endl;
        }
    }
};

class Solution
{
    // a solution of the problem
public:
    Solution(arr, mat);
    Solution(const string &);
    Solution(const Solution &);
    ~Solution();
    void maxn_init();
    bool Acceptable();
    const arr &GetArray() const { return Array; }
    const mat &GetMatrix() const { return Matrix; }
    double GetFitness() const;
    void print() const
    {
        cout << "Array:" << endl;
        Array.print();
        cout << "Matrix:" << endl;
        Matrix.print();
    }

private:
    static bool init_maxn;
    arr Array;
    mat Matrix;
};