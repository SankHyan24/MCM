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
    cout << "input 0 to optimize the default solution." << endl;
    cout << "input 1 to optimize the solution solved by LINGO" << endl;
    bool is_default = false;
    cin >> is_default;
    string file_name = is_default ? "../data/bestn.txt" : "../data/initn.txt";
    Solution s(file_name);
    int max_iter = 80000000; // 最大迭代次数
    ld init_temp = 1000.0;   // 初始温度
    ld final_temp = 1e-20;   // 最终温度
    ld alpha = 0.99999;      // 降温系数
    Simuanneal sa(s.GetArray(), s.GetMatrix(), max_iter, init_temp, final_temp, alpha);
    auto start = timer::now();
    sa.run();
    auto end = timer::now();
    cout << "done" << endl;
    cout << "time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << endl;
    cout << "seed:" << seed << endl;
    cout << "The init cost is " << s.GetFitness() << endl;
    system("pause");
    return 0;
}