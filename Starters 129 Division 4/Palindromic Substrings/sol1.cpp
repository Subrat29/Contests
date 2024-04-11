#include <bits/stdc++.h>
using namespace std;

using ll = signed long long int;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n == 1)
    {
        cout << "Bob" << endl;
    }
    else
    {

        int count_0s = 0;
        int count_1s = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
                count_0s++;
            else
                count_1s++;
        }
        if (n % 2 == 0)
        {
            if (abs(count_0s - count_1s) >= 2)
                cout << "alice" << endl;
            else
                cout << "bob" << endl;
        }
        else
        {
            if (abs(count_0s - count_1s) >= 2)
                cout << "bob" << endl;
            else
                cout << "alice" << endl;
        }
    }
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