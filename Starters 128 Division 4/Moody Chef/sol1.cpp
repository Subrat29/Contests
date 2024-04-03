#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, l, r;
        cin >> n >> l >> r;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int mini = 0, maxi = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= l && arr[i] <= r)
                ans++;
            else
                ans--;
            mini = min(mini, ans);
            maxi = max(maxi, ans);
        }
        cout << maxi << " " << mini << endl;
    }
    return 0;
}
// 2
// 4 1 3
// 4 3 2 1
// 2 5 5
// 1 4