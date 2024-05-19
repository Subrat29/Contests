#include <bits/stdc++.h>
using namespace std;

// sc:
// tc:

bool checkParity(int a, int b)
{
    if (a % 2 == 0 && b % 2 == 0)
        return false;
    else if (a % 2 != 0 && b % 2 != 0)
        return false;
    return true;
}

vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
{
    int n = nums.size();
    vector<bool> parity(n, true);

    for (int i = 1; i < n; i++)
    {
        parity[i] = checkParity(nums[i - 1], nums[i]) && parity[i - 1];
    }

    n = queries.size();
    vector<bool> ans(n);

    for (int j = 0; j < n; j++)
    {
        int from = queries[j][0];
        int to = queries[j][1];

        if (from == to)
            ans[j] = false;
        else
            ans[j] = parity[to];
    }
    return ans;
}

int main()
{
    return 0;
}