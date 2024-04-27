#include <bits/stdc++.h>
using namespace std;

using ll = signed long long int;

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ll minCoins = 0;
    for (int i = 0; i < n; i++)
    {
        ll coin = arr[i] * x;
        if (coin < y)
            minCoins += coin;
        else
            minCoins += y;
    }
    cout << minCoins << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}