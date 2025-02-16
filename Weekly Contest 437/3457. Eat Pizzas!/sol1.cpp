#include <bits/stdc++.h>
using namespace std;

// tc: nlogn
// sc: n

long long maxWeight(vector<int> &pizzas)
{
    sort(pizzas.begin(), pizzas.end());
    int n = pizzas.size();
    int day = n / 4;
    int idx = n - 1;
    long long ans = 0;

    // for odd numbered days
    for (int i = 1; i <= day; i += 2)
    {
        ans += pizzas[idx];
        idx = idx - 1;
    }

    idx--;

    // for even numbered days
    for (int i = 2; i <= day; i += 2)
    {
        ans += pizzas[idx];
        idx = idx - 2;
    }
    return ans;
}

int main()
{
    return 0;
}