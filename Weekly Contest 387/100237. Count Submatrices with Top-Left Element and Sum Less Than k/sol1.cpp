#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Learned Prefix sum

int countSubmatrices(vector<vector<int>> &grid, int k)
{
    int cnt = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (i - 1 >= 0)
                grid[i][j] += grid[i - 1][j];
            if (j - 1 >= 0)
                grid[i][j] += grid[i][j - 1];
            if (i - 1 >= 0 && j - 1 >= 0)
                grid[i][j] -= grid[i - 1][j - 1];
            if (grid[i][j] <= k)
                cnt++;
            else
                break;
        }
    }
    return cnt;
}

int main()
{
    return 0;
}