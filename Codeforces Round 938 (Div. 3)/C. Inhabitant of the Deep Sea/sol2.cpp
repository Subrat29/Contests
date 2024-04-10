#include <bits/stdc++.h>
using namespace std;

// #define all(x) (x).begin(), (x).end()

using ll = signed long long int;

void solve()
{
    int n;
    ll k;
    cin >> n >> k;

    deque<ll> dq(n);
    for (int i = 0; i < n; i++)
        cin >> dq[i];

    while (dq.size() > 1 && k)
    {
        int mini = min(dq.front(), dq.back());
        if (k < 2 * mini)
        {
            dq.front() -= k / 2 + k % 2;
            dq.back() -= k / 2;
            k = 0;
        }
        else
        {
            dq.front() -= mini;
            dq.back() -= mini;
            k -= 2 * mini;
        }
        if (dq.front() == 0)
            dq.pop_front();
        if (dq.back() == 0)
            dq.pop_back();
    }
    ll ans = n - dq.size() + (dq.size() && dq.front() <= k);
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