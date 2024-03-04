#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countSubmatrices(vector<vector<int>> &grid, int k)
{
    int n = grid.size();
    int m = grid[0].size();
    int sum = 0;
    int cnt = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    bool f1 = true;
    bool f2 = true;

    for (int i = 0; i < n; i++)
    {
        if (f1 == true)
            for (int j = i; j < m; j++)
            {
                if (visited[i][j] == false)
                {
                    if (sum + grid[i][j] < k)
                    {
                        sum += grid[i][j];
                        visited[i][j] = true;
                        cnt++;
                    }
                    else
                        f1 = false;
                }
            }

        if (f2 == true)
            for (int k = i; k < m; k++)
            {
                if ((visited[k][i] == false) && (sum + grid[k][i] < k))
                {
                    sum += grid[k][i];
                    visited[k][i] = true;
                    cnt++;
                }
                else
                    f2 = false;
            }
    }
    return cnt;
}

int main()
{
    vector<vector<int>> grid = {{7, 6, 3}, {6, 6, 1}};
    int k = 18;

    cout << " Ans: " << countSubmatrices(grid, k);
    return 0;
}