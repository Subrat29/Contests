#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> resultGrid(vector<vector<int>> &image, int threshold)
{
    int n = image.size();
    int m = image[0].size();
    vector<vector<int>> ans(n, vector<int>(m, -1));
    vector<vector<int>> check(n, vector<int>(m, 0));
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = 0; j < m - 2; j++)
        {
            int x = i;
            int y = j;
            // check thresold
            bool isValidRegion = true;
            long long int sum = 0;
            for (int p = 0; p < 3; p++)
            {
                if (abs(image[x + p][y + 1] - image[x + p][y + 0]) > threshold || abs(image[x + p][y + 2] - image[x + p][y + 1]) > threshold)
                {
                    isValidRegion = false;
                    break;
                }
                if (abs(image[x + 1][y + p] - image[x + 0][y + p]) > threshold || abs(image[x + 2][y + p] - image[x + 1][y + p]) > threshold)
                {
                    isValidRegion = false;
                    break;
                }
                sum += image[p + x][y + 0] + image[p + x][y + 1] + image[p + x][y + 2];
            }
            if (!isValidRegion)
            {
                continue;
            }
            sum = sum / 9;
            for (int p = 0; p < 3; p++)
            {
                for (int q = 0; q < 3; q++)
                {
                    if (ans[p + x][q + y] == -1)
                    {
                        ans[p + x][q + y] = sum;
                    }
                    else
                    {
                        ans[p + x][q + y] = (ans[p + x][q + y] + sum);
                    }
                    check[p + x][q + y]++;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ans[i][j] == -1)
            {
                ans[i][j] = image[i][j];
            }
            else
            {
                ans[i][j] = ans[i][j] / check[i][j];
            }
        }
    }
    return ans;
}

int main()
{
    return 0;
}