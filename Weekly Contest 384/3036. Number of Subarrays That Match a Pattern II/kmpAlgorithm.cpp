#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Use Knuth-Morris-Pratt or Z-Function algorithms.

int countMatchingSubarrays(vector<int> &nums, vector<int> &pat)
{
    int n = nums.size();
    int m = pat.size();

    // KMP preprocessing
    vector<int> lps(m, 0);
    int len = 0;
    for (int i = 1; i < m; ++i)
    {
        while (len > 0 && pat[i] != pat[len])
        {
            len = lps[len - 1];
        }
        if (pat[i] == pat[len])
        {
            ++len;
        }
        lps[i] = len;
    }

    int count = 0;
    int j = 0;
    // Start the loop from i = 1
    for (int i = 1; i < n; ++i)
    {
        while (j > 0 && (pat[j] == 1 && nums[i] <= nums[i - 1] || pat[j] == 0 && nums[i] != nums[i - 1] || pat[j] == -1 && nums[i] >= nums[i - 1]))
        {
            j = lps[j - 1];
        }
        if ((pat[j] == 1 && nums[i] > nums[i - 1] || pat[j] == 0 && nums[i] == nums[i - 1] || pat[j] == -1 && nums[i] < nums[i - 1]))
        {
            ++j;
        }
        if (j == m)
        {
            ++count;
            j = lps[j - 1];
        }
    }

    return count;
}

int main()
{
    return 0;
}