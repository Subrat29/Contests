#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// If i initialize ans vector to 0 then gives wrong answer on test case 684/810

vector<vector<int>> resultGrid(vector<vector<int>> &image, int threshold)
{
    int m = image.size();
    int n = image[0].size();
    vector<vector<int>> ans(m, vector<int>(n, 0));
    vector<vector<int>> noOfRegion(m, vector<int>(n, 0));

    for (int i = 0; i < m - 2; i++)
    {
        for (int j = 0; j < n - 2; j++)
        {
            bool isValidRegion = true;
            long long int sum = 0;

            for (int p = 0; p < 3; p++)
            {
                if (abs(image[i + p][j + 1] - image[i + p][j + 0]) > threshold || abs(image[i + p][j + 2] - image[i + p][j + 1]) > threshold)
                {
                    isValidRegion = false;
                    break;
                }
                if (abs(image[i + 1][j + p] - image[i + 0][j + p]) > threshold || abs(image[i + 2][j + p] - image[i + 1][j + p]) > threshold)
                {
                    isValidRegion = false;
                    break;
                }
                sum += image[i + p][j + 0] + image[i + p][j + 1] + image[i + p][j + 2];
            }

            if (!isValidRegion)
                continue;

            sum = sum / 9;
            for (int x = i; x < i + 3; x++)
            {
                for (int y = j; y < j + 3; y++)
                {
                    ans[x][y] += sum;
                    noOfRegion[x][y]++;
                }
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ans[i][j] == 0)
                ans[i][j] = image[i][j];

            ans[i][j] = ans[i][j] / noOfRegion[i][j];
        }
    }
    return ans;
}

int main()
{
    return 0;
}