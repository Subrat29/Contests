#include <bits/stdc++.h>
using namespace std;

using ll = signed long long int;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int cnt = 0;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == s[i - 1])
            cnt++;
    }
    cout << cnt << endl;
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