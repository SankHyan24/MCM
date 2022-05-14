#pragma once
typedef char locate;
#define LOCATE_NUM 28
#define MAX_LEN 12

inline int my_abs(int num)
{
    return num < 0 ? -num : num;
}

inline int dist(const locate &a, const locate &b)
{
    return my_abs(a - b) / 7 + my_abs(a - b) % 7;
}

inline int ComNum(int x)
{
    // Number of combinations
    if (x == 0)
        return 1;
    x = ((28 - x) > x) ? x : (28 - x);
    int res = 1;
    for (int i = 28; i > 28 - x; --i)
    {
        res *= i;
        res /= 28 - i + 1;
    }
    return res;
}