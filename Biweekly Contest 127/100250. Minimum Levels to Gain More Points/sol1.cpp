#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int minimumSubarrayLength(vector<int> &nums, int k)
{
    int minLen = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        int OR = 0;
        for (int j = i + 1; j < nums.size(); j++)
        {
            OR = OR | nums[j];
            if (OR >= k)
                minLen = min(j - i + 1, minLen);
        }
    }
    if (minLen != INT_MAX)
        return minLen;
    return -1;
}

int main()
{
    return 0;
}