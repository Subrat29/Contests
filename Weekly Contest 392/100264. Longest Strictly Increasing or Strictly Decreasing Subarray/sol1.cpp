#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestMonotonicSubarray(vector<int> &nums)
{
    int maxLen = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size() - 1; j++)
        {
            if (nums[j + 1] > nums[j])
                maxLen = max(maxLen, j - i + 2);
            else
                break;
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size() - 1; j++)
        {
            if (nums[j + 1] < nums[j])
                maxLen = max(maxLen, j - i + 2);
            else
                break;
        }
    }
    return maxLen;
}

int main()
{
    return 0;
}