#include <bits/stdc++.h>
using namespace std;

// sc:
// tc:

bool isArraySpecial(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        int a = nums[i - 1];
        int b = nums[i];

        if (a % 2 == 0 && b % 2 == 0)
            return false;
        else if (a % 2 != 0 && b % 2 != 0)
            return false;
    }
    return true;
}

int main()
{
    return 0;
}