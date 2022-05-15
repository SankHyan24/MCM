#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility.hpp>
#include <assert.h>
using namespace std;

vector<string> words;
int freq[28][28];
int letter[28];

void read_recipe()
{
    ifstream fin("../data/word_refined.txt");
    string word;
    while (fin >> word)
        words.push_back(word);
    fin.close();
    cout << "Read " << words.size() << " words." << endl;

    for (int i = 0; i < 28; i++)
        for (int j = 0; j < 28; j++)
            freq[i][j] = 0;
    //统计字母组合
    // for (auto &word : words)
    // {
    //     for (int i = 0; i < word.size(); ++i)
    //     {
    //         for (int j = i + 1; j < word.size(); ++j)
    //         {
    //             freq[word[i] - 'a'][word[j] - 'a']++;
    //             freq[word[j] - 'a'][word[i] - 'a']++;
    //         }
    //         freq[word[i] - 'a'][26]++;
    //         freq[26][word[i] - 'a']++;
    //     }
    // }

    // 统计字频
    // for (auto &word : words)
    // {
    //     for (int i = 0; i < word.size(); ++i)
    //     {
    //         letter[word[i] - 'a']++;
    //     }
    //     letter[26]++;
    // }

    // // 统计单方向的相邻字母组合
    // for (auto &word : words)
    // {
    //     freq[26][word[0] - 'a']++;
    //     for (int i = 0; i < word.size() - 1; ++i)
    //         freq[word[i] - 'a'][word[i + 1] - 'a']++;
    //     freq[word[word.size() - 1] - 'a'][26]++;
    // }

    // ofstream fout("../data/newn.txt");
    // for (int i = 0; i < 28; ++i)
    // {
    //     for (int j = 0; j < 28; ++j)
    //         fout << setw(6) << freq[i][j] << ',';
    //     fout << endl;
    //     // fout << setw(6) << letter[i] << ',';
    // }

    // // newn check
    // for (int i = 0; i < 28; ++i)
    // {
    //     int sum = 0;
    //     for (int j = 0; j < 28; ++j)
    //         sum += freq[i][j];
    //     int sum_ = 0;
    //     for (int j = 0; j < 28; ++j)
    //         sum_ += freq[j][i];
    //     assert(sum == sum_);
    // }
}
inline int myabs(int x)
{
    return x < 0 ? -x : x;
}

int main()
{
    read_recipe();
}