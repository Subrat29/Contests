#include <bits/stdc++.h>
using namespace std;

// sc: 1
// tc: n^2

int minimumArea(vector<vector<int>> &grid)
{
    pair<int, int> begin = {INT_MAX, INT_MAX};
    pair<int, int> end = {0, 0};

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                begin.first = min(begin.first, i);
                begin.second = min(begin.second, j);
                end.first = max(end.first, i);
                end.second = max(end.second, j);
            }
        }
    }
    int x = abs(begin.first - end.first) + 1;
    int y = abs(begin.second - end.second) + 1;
    return x * y;
}

int main()
{
    return 0;
}