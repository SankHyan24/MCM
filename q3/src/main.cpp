#include <iostream>
#include <ctime>
#include <SimuAneal.hpp>
#include <chrono>
int main()
{
    using timer = std::chrono::high_resolution_clock;
    // srand(time(NULL));
    srand(0);
    Solution s("../data/initn.txt");
    Simuanneal sa(s.GetArray(), s.GetMatrix(), 800000, 10000.0, 1e-20, 0.99999);
    auto start = timer::now();
    sa.run();
    auto end = timer::now();
    cout << "done" << endl;
    cout << "time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << endl;
    return 0;
}