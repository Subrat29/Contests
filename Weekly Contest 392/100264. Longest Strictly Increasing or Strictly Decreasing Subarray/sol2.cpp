#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestMonotonicSubarray(vector<int> &nums)
{
    int maxLen = 1;
    int inc = 1;
    int dec = 1;

    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            dec++;
            inc = 1;
        }
        else if (nums[i] < nums[i + 1])
        {
            inc++;
            dec = 1;
        }
        else
        {
            inc = 1;
            dec = 1;
        }
        maxLen = max(maxLen, max(inc, dec));
    }
    return maxLen;
}

int main()
{
    return 0;
}