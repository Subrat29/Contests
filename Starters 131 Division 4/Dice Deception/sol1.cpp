#include <bits/stdc++.h>
using namespace std;

using ll = signed long long int;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());
    ll sum = 0;
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 4)
            sum += 7 - arr[i];
        else
            sum += arr[i];
    }

    for (int i = k; i < n; i++)
    {
        sum += arr[i];
    }
    cout << sum << endl;
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