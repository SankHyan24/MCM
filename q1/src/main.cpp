#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>

#include <medicine.hpp>
using namespace std;
unordered_map<string, Locate> medicine_map;
void read_file()
{
    ifstream inFile;
    inFile.open("../data/xm");
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
            medicine_map[word] = Locate(x, y, z);
        }
    }
    inFile.close();
}
int main()
{
    read_file();
    for (auto i : medicine_map)
        cout << i.first << " " << i.second << endl;
}