// C++风格生成随机数
#pragma once
#include <algorithm>
#include <cmath>
#include <random>
#include <vector>

namespace RandomUtils
{
    static void RandomString(char *buf, size_t len)
    {
        std::random_device r;
        std::default_random_engine rng(r());
        std::uniform_int_distribution<char> uniform_dist(0);
        for (size_t i = 0; i < len; i++)
        {
            buf[i] = uniform_dist(rng);
        }
    }

    static int32_t RandomInt(int32_t low, int32_t high)
    {
        std::random_device r;
        std::default_random_engine rng(r());
        std::uniform_int_distribution<int32_t> uniform_dist(low, high);
        return uniform_dist(rng);
    }

    static int32_t Randomint(int32_t low, int32_t high)
    {
        return rand() % (high - low + 1) + low;
    }

    static float_t RandomFloat(float_t low, float_t high)
    {
        std::random_device r;
        std::default_random_engine rng(r());
        std::uniform_real_distribution<float_t> uniform_dist(low, high);
        return uniform_dist(rng);
    }
};
