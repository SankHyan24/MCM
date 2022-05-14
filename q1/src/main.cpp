#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <medicine.hpp>
using namespace std;
unordered_map<string, Locate> medmap; // medicine map from name to Locate
vector<string> medlist;               // medicine name list
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
            medmap[word] = Locate(x, y, z);
            medlist.push_back(word);
        }
    }
    inFile.close();
}
int main()
{
    read_file();
    for (auto i : medmap)
        cout << i.first << " " << i.second << endl;
    cout << dist(medmap[medlist[0]], medmap[medlist[2]]) << endl;
    cout << medmap[medlist[0]] << endl;
    cout << medmap[medlist[2]] << endl;
}