#include <iostream>
#include <ctime>
#include <cstdlib>
#include <SimuAneal.hpp>
#include <chrono>
int main()
{
    using timer = std::chrono::high_resolution_clock;
    // srand(time(NULL));
    int seed = time(NULL);
    srand(seed);
    Solution s("../data/initn.txt");
    Simuanneal sa(s.GetArray(), s.GetMatrix(), 80000000, 1000.0, 1e-20, 0.99999);
    auto start = timer::now();
    sa.run();
    auto end = timer::now();
    cout << "done" << endl;
    cout << "time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << endl;
    cout << "seed:" << seed << endl;
    system("pause");
    return 0;
}