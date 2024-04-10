#include <bits/stdc++.h>
using namespace std;

//tle
using ll = signed long long int;

void solve()
{
    ll n, k;
    cin >> n >> k;

    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll first = 0;
    ll last = n - 1;
    ll sunkenShips = 0;
    for (int i = 1; i <= k && first <= last; i++)
    {
        if (i % 2 != 0)
        {
            a[first]--;
            if (a[first] == 0)
            {
                first++;
                sunkenShips++;
            }
        }
        else
        {
            a[last]--;
            if (a[last] == 0)
            {
                last--;
                sunkenShips++;
            }
        }
    }
    cout << sunkenShips << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}