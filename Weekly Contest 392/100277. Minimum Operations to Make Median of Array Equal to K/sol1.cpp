#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long minOperationsToMakeMedianK(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    long long cnt = 0;
    int l = nums.size();

    int mid = l / 2;
    for (int i = mid; i >= 0; i--)
    {
        if (nums[i] > k)
            cnt += abs(k - nums[i]);
    }

    for (int i = mid; i < l; i++)
    {
        if (nums[i] < k)
            cnt += abs(k - nums[i]);
    }
    return cnt;
}

int main()
{
    return 0;
}