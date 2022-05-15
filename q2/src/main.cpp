#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility.hpp>
using namespace std;

vector<string> words;
vector<char> letters;
int freq[28][28];

void read_recipe()
{
    ifstream fin("../data/letters.txt");
    char tmp;
    while (fin >> tmp)
        letters.push_back(tmp);
    cout << letters.size();
    fin.close();
    for (int i = 0; i < 28; i++)
        for (int j = 0; j < 28; j++)
            freq[i][j] = 0;
    for (auto i = letters.begin(); (i + 1) != letters.end(); i++)
    {
        auto j = i + 1;
        freq[*i - 'a'][*j - 'a']++;
    }
    cout << "reading done" << endl;
    ofstream fout("../data/freq.txt");
    for (int i = 0; i < 28; i++)
    {
        for (int j = 0; j < 28; j++)
            fout << setw(5) << freq[i][j] << ",";
        fout << endl;
    }
}
inline int myabs(int x)
{
    return x < 0 ? -x : x;
}

int main()
{
    // read_recipe();
    for (int i = 0; i < 28; i++)
        for (int j = 0; j < 28; j++)
            freq[i][j] = myabs((i - j) / 7 + (i - j) % 7);
    ofstream fout("../data/dist.txt");
    for (int i = 0; i < 28; i++)
    {
        for (int j = 0; j < 28; j++)
            fout << setw(5) << freq[i][j] << ",";
        fout << endl;
    }
}