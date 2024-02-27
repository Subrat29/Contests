#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long largestSquareArea(vector<vector<int>> &bottomLeft, vector<vector<int>> &topRight)
{
    int n = bottomLeft.size();
    long long maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            long long min_x = max(bottomLeft[i][0], bottomLeft[j][0]);
            long long max_x = min(topRight[i][0], topRight[j][0]);
            long long min_y = max(bottomLeft[i][1], bottomLeft[j][1]);
            long long max_y = min(topRight[i][1], topRight[j][1]);

            if (max_x > min_x && max_y > min_y)
            {
                long long s = min(max_x - min_x, max_y - min_y);
                maxArea = max(maxArea, s * s);
            }
        }
    }
    return maxArea;
}

int main()
{
    return 0;
}