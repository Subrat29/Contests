#include <bits/stdc++.h>
using namespace std;
using ll = signed long long int;
const int MOD = 1e9 + 7;

void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    ll ans = 0;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        ll v1 = arr[i].first;
        ll s1 = arr[i].second;
        for (int j = i + 1; j < arr.size(); j++)
        {
            ll v2 = arr[j].first;
            ll s2 = arr[j].second;
            if (s1 * v2 + v1 * s2 > ans)
            {
                ans = s1 * v2 + v1 * s2;
            }
        }
    }
    cout << ans << endl;
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