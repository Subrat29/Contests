#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int minOperations(int k)
{
    int ans = INT_MAX;
    for (int i = 1; i < k; i++)
    {
        if (k % i == 0)
            ans = min(ans, i + (k / i) - 2); // for non-prime numbers
        else
            ans = min(ans, i + (k / i) - 1); // for prime numbers
    }

    if (ans != INT_MAX)
        return ans;
    else
        return 0;
}

int main()
{
    return 0;
}