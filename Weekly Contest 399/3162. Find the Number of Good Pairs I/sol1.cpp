#include <bits/stdc++.h>
using namespace std;

// sc: 1
// tc: n^2

int numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k)
{
    int cnt = 0;
    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = 0; j < nums2.size(); j++)
        {
            if (nums1[i] % (nums2[j] * k) == 0)
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    return 0;
}