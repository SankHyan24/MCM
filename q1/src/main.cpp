#include <tsp.hpp>
#include <chrono>  // for timer
#include <fstream> // for file read
#include <sstream> // for stringstream

vector<string> medlist;               // medicine name list
vector<string> recipe;                // medicin recipe list
unordered_map<string, Locate> medmap; // medicine map from name to Locate
/**
 * Get the location like this:
 *  you have the index of medicine A and B as a and b
 * First get the name of the medicine:
 *  medlist[a],medlist[b] or recipe[a],recipe[b]
 * Then get the location:
 *  medmap[medlist[a]], medmap[medlist[b]]
 *
 * The distance between a and b:
 *  dist(medmap[medlist[a]],medmap[medlist[b]])
 */

void read_file()
{
    ifstream inFile;
    inFile.open("../data/medmap");
    if (!inFile)
        throw "File not found";
    string line;
    for (int i = 0; i < 24; i++)
    {
        getline(inFile, line);
        stringstream ss(line);
        string word;
        int y = (23 - i) / 3;
        int z = (23 - i) % 3;
        for (int x = 0; x < 15; x++)
        {
            ss >> word;
            medmap[word] = Locate(x, y, z);
            medlist.push_back(word);
        }
    }
    inFile.close();
}

void read_recipe()
{
    using timer = std::chrono::high_resolution_clock;
    ifstream inFile;
    inFile.open("../data/recipe");
    if (!inFile)
        throw "File not found";
    string line;
    int num = 0;
    while (getline(inFile, line))
    {
        recipe.clear(), num++;
        recipe.push_back(medlist[0]);
        stringstream ss(line);
        string word;
        while (ss >> word)
            if (word != medlist[0])
                recipe.push_back(word);
        cout << "solve recipe: " << num << endl;
        timer::time_point start_time = timer::now();
        solve_recipe();
        timer::time_point end_time = timer::now();
        cout << "time cost: " << std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << " ms" << endl;
        cout << endl;
    }
}

int main()
{
    read_file();
    read_recipe();
}