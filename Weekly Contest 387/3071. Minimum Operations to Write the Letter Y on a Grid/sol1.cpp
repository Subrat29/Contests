#include <iostream>
#include <cmath>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

int minimumOperationsToWriteY(vector<vector<int>> &grid)
{
    int n = grid.size() - 1;
    unordered_map<int, int> Y;
    unordered_map<int, int> notY;
    vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));

    for (int i = 0; i <= n; i++)
    {
        if (i <= n / 2)
        {
            Y[grid[i][i]]++;
            visited[i][i] = true;
            if (i != n / 2)
            {
                Y[grid[i][n - i]]++;
                visited[i][n - i] = true;
            }
        }
        else
        {
            Y[grid[i][n / 2]]++;
            visited[i][n / 2] = true;
        }

        for (int j = 0; j <= n; j++)
        {
            if (visited[i][j] == false)
                notY[grid[i][j]]++;
        }
    }

    double m = (n + 1) / 2;
    int yCnt = floor(m) * 2 + ceil(m);
    int nonYCnt = (n + 1) * (n + 1) - yCnt;

    int ans = INT_MAX;
    for (int i = 0; i < 3; i++)
    {
        int y = yCnt - Y[i];
        int nonY = INT_MAX;
        for (int j = 0; j < 3; j++)
        {
            if (i != j)
                nonY = min(nonY, (nonYCnt - notY[j]));
        }
        ans = min(ans, y + nonY);
    }
    return ans;

    return 0;
}

int main()
{
    // vector<vector<int>> grid = {
    //     {1, 2, 2},
    //     {1, 1, 0},
    //     {0, 1, 0},
    // };
    // vector<vector<int>> grid = {
    //     {2, 1, 1},
    //     {2, 0, 0},
    //     {2, 2, 1},
    // };
    vector<vector<int>> grid = {
        {0, 1, 0, 1, 0},
        {2, 1, 0, 1, 2},
        {2, 2, 2, 0, 1},
        {2, 2, 2, 2, 2},
        {2, 1, 2, 2, 2}};

    cout << "Ans: " << minimumOperationsToWriteY(grid);
    return 0;
}

// int Y_0s = 0;
// int Y_1s = 0;
// int Y_2s = 0;

// int notY_0s = 0;
// int notY_1s = 0;
// int notY_2s = 0;

//     cout << "maxNumInY: " << maxNumInY << endl;
//     cout << "occurmaxNumInY: " << occurmaxNumInY << endl;
//     cout << "maxNumNotInY: " << maxNumNotInY << endl;
//     cout << "occurmaxNumNotInY: " << occurmaxNumNotInY << endl;