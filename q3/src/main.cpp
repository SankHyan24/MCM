#include <iostream>
#include <ctime>
#include <SimuAneal.hpp>
#include <chrono>
int main()
{
    // srand(time(NULL));
    srand(0);
    std::cout << "Hello World!" << std::endl;
    Solution s("../data/initn.txt");
    s.print();
    Simuanneal sa(s.GetArray(), s.GetMatrix(), 100000, 10000, 0.01, 0.9999);
    sa.run();
    cout << "done" << endl;
    return 0;
}