#include <iostream>
#include <fstream>
#include <vector>
#include <utility.hpp>
using namespace std;

vector<string> words;
void read_recipe()
{
    ifstream in("../data/word_refined.txt");
    string word;
    while (in >> word)
        words.push_back(word);
}

int main()
{
    read_recipe();
    cout << (1 << 28) << endl;
}