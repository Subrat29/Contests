#include <bits/stdc++.h>
using namespace std;

using ll = signed long long int;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (arr[0] == arr[n - 1])
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