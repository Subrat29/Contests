#include <bits/stdc++.h>
using namespace std;

using ll = signed long long int;

// Note: Array contains only 1 and 2 as element
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int count_1s = count(arr.begin(), arr.end(), 1);
    int count_2s = count(arr.begin(), arr.end(), 2);

    if (count_1s == n || count_2s % 8 == 0)
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