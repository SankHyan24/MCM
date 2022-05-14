#include <tsp.hpp>
#include <cstring> // for memset

int ssize{};
int M; // = 1 << (MAX_RECIPE_LEN - 1)
int cost[MAX_RECIPE_LEN][MAX_RECIPE_LEN];
int dp[MAX_RECIPE_LEN][1 << (MAX_RECIPE_LEN - 1)];
bool visited[MAX_RECIPE_LEN];
vector<int> path;

inline bool isVisited()
{
    for (int i = 1; i < ssize; i++)
        if (visited[i] == false)
            return false;
    return true;
}
void solve_recipe()
{
    // clear the data in the cost array
    memset(cost, 0, sizeof(cost));
    ssize = recipe.size();
    M = 1 << (ssize - 1);
    // calculate the cost of each medicine
    for (int i = 0; i < ssize; i++)
        for (int j = i + 1; j < ssize; j++)
        {
            cost[i][j] = dist(medmap[recipe[i]], medmap[recipe[j]]);
            cost[j][i] = cost[i][j];
        }
    // initialize the dp array
    for (int i = 0; i < ssize; i++)
        dp[i][0] = cost[i][0];
    //  solve dp array
    for (int j = 1; j < M; j++)
        for (int i = 0; i < ssize; i++)
        {
            dp[i][j] = INFINITY;
            if (((j >> (i - 1)) & 1) == 1)
                continue;
            for (int k = 1; k < ssize; k++)
            {
                if (((j >> (k - 1)) & 1) == 0)
                    continue;
                if (dp[i][j] > cost[i][k] + dp[k][j ^ (1 << (k - 1))])
                    dp[i][j] = cost[i][k] + dp[k][j ^ (1 << (k - 1))];
            }
        }
    cout << "min cost is" << dp[0][M - 1] << endl;
    // find the path
    int pioneer = 0, min = INFINITY, S = M - 1, temp;
    path.push_back(0);
    while (!isVisited())
    {
        for (int i = 1; i < ssize; i++)
            if (visited[i] == false && (S & (1 << (i - 1))) != 0)
                if (min > cost[i][pioneer] + dp[i][(S ^ (1 << (i - 1)))])
                {
                    min = cost[i][pioneer] + dp[i][(S ^ (1 << (i - 1)))];
                    temp = i;
                }
        pioneer = temp;
        path.push_back(pioneer);
        visited[pioneer] = true;
        S = S ^ (1 << (pioneer - 1));
        min = INFINITY;
    }
    // print path
    cout << "min path:" << endl;
    for (auto i : path)
        cout << recipe[i] << " ";
    cout << endl;
}