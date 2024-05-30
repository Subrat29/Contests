#include <bits/stdc++.h>
using namespace std;

// sc: n
// tc: 10^5 * sqrt(10^6) = 10^8

long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k)
{
    unordered_map<int, int> factor;

    // step1: find all factors
    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = 1; j <= sqrt(nums1[i]); j++)
        {
            if (nums1[i] % j == 0)
            {
                factor[j]++;
                if (j != nums1[i] / j)
                    factor[nums1[i] / j]++;
            }
        }
    }

    // step2: iterate over nums2 and find the match
    long long ans = 0;
    for (auto &&i : nums2)
    {
        if (factor[i * k])
            ans += factor[i * k];
    }
    return ans;
}

int main()
{
    return 0;
}