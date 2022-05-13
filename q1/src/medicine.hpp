#pragma once
#include <iostream>

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
        locate_ = x * 32 + y * 4 + z;
    }
    ~Locate() = default;

    inline void setX(int x)
    {
        if (x < 0 || x > 14) // 4bit
            throw "X must be between 0 and 14";
        locate_ = x * 32 + getY() * 4 + getZ();
    }
    inline void setY(int y)
    {
        if (y < 0 || y > 7) // 3bit
            throw "Y must be between 0 and 7";
        locate_ = getX() * 32 + y * 4 + getZ();
    }
    inline void setZ(int z)
    {
        if (z < 0 || z > 2) // 2bit
            throw "Z must be between 0 and 2";
    }
    inline void setLocate(int x, int y, int z)
    {
        if (x < 0 || x > 14) // 4bit
            throw "X must be between 0 and 14";
        if (y < 0 || y > 7) // 3bit
            throw "Y must be between 0 and 7";
        if (z < 0 || z > 2) // 2bit
            throw "Z must be between 0 and 2";
        locate_ = x * 32 + y * 4 + z;
    }
    inline int getX() const { return locate_ / 32; }
    inline int getY() const { return (locate_ % 32) / 4; }
    inline int getZ() const { return locate_ % 4; }
    // out stream
    friend std::ostream &operator<<(std::ostream &os, const Locate &locate)
    {
        os << "(" << locate.getX() << "," << locate.getY() << "," << locate.getZ() << ")";
        return os;
    }

private:
    int locate_;
};

// class Medicine
// {
// public:
//     Medicine() = default;
//     Medicine(const Medicine &) = default;
//     Medicine(std::string name_, int x, int y, int z)
//     {
//         if (x < 0 || x > 14) // 4bit
//             throw "X must be between 0 and 14";
//         if (y < 0 || y > 7) // 3bit
//             throw "Y must be between 0 and 7";
//         if (z < 0 || z > 2) // 2bit
//             throw "Z must be between 0 and 2";
//         locate = x * 32 + y * 4 + z;
//         name = name_;
//     }
//     ~Medicine() = default;

//     inline void setX(int x)
//     {
//         if (x < 0 || x > 14) // 4bit
//             throw "X must be between 0 and 14";
//         locate = x * 32 + getY() * 4 + getZ();
//     }
//     inline void setY(int y)
//     {
//         if (y < 0 || y > 7) // 3bit
//             throw "Y must be between 0 and 7";
//         locate = getX() * 32 + y * 4 + getZ();
//     }
//     inline void setZ(int z)
//     {
//         if (z < 0 || z > 2) // 2bit
//             throw "Z must be between 0 and 2";
//     }
//     inline void setLocate(int x, int y, int z)
//     {
//         if (x < 0 || x > 14) // 4bit
//             throw "X must be between 0 and 14";
//         if (y < 0 || y > 7) // 3bit
//             throw "Y must be between 0 and 7";
//         if (z < 0 || z > 2) // 2bit
//             throw "Z must be between 0 and 2";
//         locate = x * 32 + y * 4 + z;
//     }
//     inline void setName(std::string name_) { name = name_; }
//     inline int getX() { return locate / 32; }
//     inline int getY() { return (locate % 32) / 4; }
//     inline int getZ() { return locate % 4; }
//     inline std::string getName() { return name; }

// private:
//     std::string name;
//     int locate;
// };