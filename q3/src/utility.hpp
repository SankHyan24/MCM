// C++风格生成随机数
#pragma once
#include <algorithm>
#include <cmath>
#include <random>
#include <vector>

class RandomUtils
{
public:
    static int32_t Randomint(int32_t low, int32_t high)
    {
        return rand() % (high - low + 1) + low;
    }
    static double Randomfloat(double low, double high)
    {
        double r = low + static_cast<double>(rand()) / static_cast<double>(RAND_MAX / (high - low));
        return r;
    }
};
