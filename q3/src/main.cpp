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
    Simuanneal sa(s.GetArray(), s.GetMatrix(), 80000000, 1000.0, 1e-20, 0.99999);
    // cout << "The init cost is " << s.GetFitness() << endl;
    auto start = timer::now();
    sa.run();
    auto end = timer::now();
    cout << "done" << endl;
    cout << "time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << endl;
    cout << "seed:" << seed << endl;
    system("pause");
    return 0;
}