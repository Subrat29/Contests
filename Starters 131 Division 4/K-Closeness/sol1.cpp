#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v;
    ll maxi = INT_MIN, mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        temp = temp % k;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());
    ll ans = v[n - 1] - v[0];
    for (int i = 0; i < n - 1; i++)
    {
        ans = min(ans, v[i] + k - v[i + 1]);
    }
    cout << ans << endl;
}

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
