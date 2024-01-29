#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Tle
long long flowerGame(int n, int m)
{
    if (n == 1 && m == 1)
        return 0;

    long long ans = (n * m) / 2;
    return ans;
}

int main()
{
    return 0;
}