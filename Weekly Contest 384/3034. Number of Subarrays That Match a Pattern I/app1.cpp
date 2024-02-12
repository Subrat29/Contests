#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countMatchingSubarrays(vector<int> &nums, vector<int> &pattern)
{
    int numsSize = nums.size();
    int patternSize = pattern.size();
    int len = numsSize - patternSize;
    int cnt = 0;

    for (int i = 0; i < len; i++)
    {
        bool flag = true;
        for (int j = 0; j < patternSize; j++)
        {
            if (pattern[j] == 1 && nums[i + j] >= nums[i + j + 1])
            {
                flag = false;
                break;
            }
            else if (pattern[j] == 0 && nums[i + j] != nums[i + j + 1])
            {
                flag = false;
                break;
            }
            else if (pattern[j] == -1 && nums[i + j] <= nums[i + j + 1])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cnt++;
    }
    return cnt;
}

int main()
{
    return 0;
}