#include <bits/stdc++.h>
using namespace std;

// sc: N
// tc: N*K

int valueAfterKSeconds(int n, int k)
{
    const int MOD = 1e9 + 7;

    vector<long long> v(n, 1);
    for (int i = 0; i < k; i++)
    {
        for (int j = 1; j < n; j++)
        {
            v[j] += v[j - 1] % MOD;
        }
    }
    return v[n - 1] % MOD;
}

int main()
{
    return 0;
}