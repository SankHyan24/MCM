#pragma once
#include <iostream>

inline int my_abs(int num)
{
    if (num < 0)
        return -num;
    else
        return num;
}

class Locate
{
public:
    Locate() = default;
    Locate(const Locate &) = default;
    Locate(int x, int y, int z)
    {
        if (x < 0 || x > 14) // 4bit
            throw "X must be between 0 and 14";
        if (y < 0 || y > 7) // 3bit
            throw "Y must be between 0 and 7";
        if (z < 0 || z > 2) // 2bit
            throw "Z must be between 0 and 2";
        locate_ = (x << 5) + (y << 2) + z;
    }
    ~Locate() = default;

    inline void setX(int x)
    {
        if (x < 0 || x > 14) // 4bit
            throw "X must be between 0 and 14";
        locate_ = (locate_ & 0x01F) + (x << 5);
    }
    inline void setY(int y)
    {
        if (y < 0 || y > 7) // 3bit
            throw "Y must be between 0 and 7";
        locate_ = (locate_ & 0xFE3) + (y << 2);
    }
    inline void setZ(int z)
    {
        if (z < 0 || z > 2) // 2bit
            throw "Z must be between 0 and 2";
        locate_ = (locate_ & 0xFFD) + z;
    }
    inline void setLocate(int x, int y, int z)
    {
        if (x < 0 || x > 14) // 4bit
            throw "X must be between 0 and 14";
        if (y < 0 || y > 7) // 3bit
            throw "Y must be between 0 and 7";
        if (z < 0 || z > 2) // 2bit
            throw "Z must be between 0 and 2";
        locate_ = (x << 5) + (y << 2) + z;
    }
    inline int getX() const { return (locate_ >> 5); }
    inline int getY() const { return ((locate_ & 31) >> 2); }
    inline int getZ() const { return (locate_ & 3); }
    // out stream
    friend std::ostream &operator<<(std::ostream &os, const Locate &locate)
    {
        os << "(" << locate.getX() << "," << locate.getY() << "," << locate.getZ() << ")";
        return os;
    }

private:
    int locate_;
};

/***
 * calculate the distance between two medicine
 * Parameters:
 * @param locate1  medicine a
 * @param locate2  medicine b
 * @return : distance between medicine a and b for robot
 */
inline int dist(const Locate &locate1, const Locate &locate2)
{
    int xLength = 20 * my_abs(locate1.getX() - locate2.getX());
    int yLength = 25 * my_abs(locate1.getY() - locate2.getY());
    int zLength = (xLength == 0 && yLength == 0) ? 20 * my_abs(locate1.getZ() - locate2.getZ()) : 20 * (1 + locate1.getZ() + locate2.getZ());
    return xLength + yLength + zLength;
}
