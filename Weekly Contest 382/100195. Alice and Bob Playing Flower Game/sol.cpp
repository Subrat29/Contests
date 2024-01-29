#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Tle
long long flowerGame(int n, int m)
{
    if (n == 1 && m == 1)
        return 0;

    long long cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if ((i + j) % 2 != 0)
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    return 0;
}