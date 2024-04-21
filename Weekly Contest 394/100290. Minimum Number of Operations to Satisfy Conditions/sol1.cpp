#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimumOperations(vector<vector<int>> &grid)
{
    int minOper = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (i + 1 < grid.size() && j + 1 < grid[0].size() && i - 1 > 0 && j - 1 > 0)
            {
                if(grid[i][j] != grid[i+1][j])
                grid[i]
            }
        }
    }
}

int main()
{
    return 0;
}