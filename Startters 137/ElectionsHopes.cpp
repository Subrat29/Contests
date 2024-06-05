#include <bits/stdc++.h>
using namespace std;
using ll = signed long long int;
const int MOD = 1e9 + 7;

void solve()
{
    ll x, y;
    cin >> x;
    cin >> y;

    if (x >= 2 * y)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    solve();
}