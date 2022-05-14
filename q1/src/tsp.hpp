#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include <medicine.hpp>
using namespace std;
#define MAX_RECIPE_LEN 22
#define INFINITY INT32_MAX
// int ssize{};
// int M; // = 1 << (MAX_RECIPE_LEN - 1)
// int cost[MAX_RECIPE_LEN][MAX_RECIPE_LEN];
// int dp[MAX_RECIPE_LEN][1 << (MAX_RECIPE_LEN - 1)];
// bool visited[MAX_RECIPE_LEN];
// vector<int> path;
// vector<string> medlist;               // medicine name list
// vector<string> recipe;                // medicin recipe list
// unordered_map<string, Locate> medmap; // medicine map from name to Locate
extern int ssize;
extern int M; // = 1 << (MAX_RECIPE_LEN - 1)
extern int cost[MAX_RECIPE_LEN][MAX_RECIPE_LEN];
extern int dp[MAX_RECIPE_LEN][1 << (MAX_RECIPE_LEN - 1)];
extern bool visited[MAX_RECIPE_LEN];
extern vector<int> path;
extern vector<string> medlist;               // medicine name list
extern vector<string> recipe;                // medicin recipe list
extern unordered_map<string, Locate> medmap; // medicine map from name to Locate

void read_file();
void solve_recipe();
void read_recipe();