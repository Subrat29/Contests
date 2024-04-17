#include <bits/stdc++.h>
using namespace std;

using ll = signed long long int;

void solve()
{
    int m1, m2;
    cin >> m1 >> m2;

    int rev1 = 0, rev2 = 0;
    rev1 += (m1 % 10) * 10 + (m1 / 10);
    rev2 += (m2 % 10) * 10 + (m2 / 10);

    if (m1 > m2)
        cout << "yes" << endl;
    else if (rev1 > rev2)
        cout << "yes" << endl;
    else if (m1 > rev2)
        cout << "yes" << endl;
    else if (rev1 > m2)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
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