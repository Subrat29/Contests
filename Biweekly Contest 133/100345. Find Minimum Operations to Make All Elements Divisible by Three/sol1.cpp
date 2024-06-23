#include <bits/stdc++.h>
using namespace std;

// sc:
// tc:

int minimumOperations(vector<int> &nums)
{
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % 3 != 0)
            cnt++;
    }
    return cnt;
}

int main()
{
    return 0;
}