#include <bits/stdc++.h>
using namespace std;

// sc: n
// tc: n

vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
{
    vector<bool> ans;
    vector<int> parity(1, 0);
    for (int i = 1, j = 0; i < nums.size(); i++)
    {
        if (nums[i - 1] % 2 == nums[i] % 2)
            j++;
        parity.push_back(j);
    }

    for (int i = 0; i < queries.size(); i++)
    {
        int from = queries[i][0];
        int to = queries[i][1];
        ans.push_back(parity[from] == parity[to]);
    }
    return ans;
}

int main()
{
    cout << "3 % 2 : " << 3 % 2 << endl;
    cout << "25 % 2 : " << 25 % 2 << endl;

    cout << "Hello World" << endl;
    return 0;
}