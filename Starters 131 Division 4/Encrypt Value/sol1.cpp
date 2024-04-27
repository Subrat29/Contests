#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
using ll = signed long long int;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    ll sum = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (sum == 0 || sum == 1 || arr[i] == 1 || arr[i] == 0)
            sum = (sum + arr[i]) % MOD;
        else
            sum = (sum * arr[i]) % MOD;
    }
    cout << sum << endl;
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