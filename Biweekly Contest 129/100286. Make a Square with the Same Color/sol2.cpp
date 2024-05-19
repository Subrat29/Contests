#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// sc: O(1)
// tc: O(n^2)

bool canMakeSquare(vector<vector<char>> &grid)
{
    int w, b;
    int n = grid.size();
    for (int i = 0; i <= n - 2; i++)
    {
        w = 0, b = 0;
        for (int j = 0; j <= n - 2; j++)
        {
            grid[i][j] == 'B' ? b++ : w++;
            grid[i][j + 1] == 'B' ? b++ : w++;
            grid[i + 1][j] == 'B' ? b++ : w++;
            grid[i + 1][j + 1] == 'B' ? b++ : w++;

            if (b >= 3 || w >= 3)
                return true;
        }
    }
    return false;
}

int main()
{
    return 0;
}