#include <bits/stdc++.h>
using namespace std;

int minimumAddedInteger(vector<int> &nums1, vector<int> &nums2)
{
    map<int, map<int, int>> mp;
    for (auto &&i : nums2)
    {
        map<int, int> temp;
        for (auto &&j : nums1)
        {
            temp[i - j] = true;
        }
        mp[i] = temp;
    }

    int ans = 0;
    for (auto &&i : mp[nums2[0]])
    {
        bool flag = true;
        int x = i.first;
        for (auto &&j : mp)
        {
            if (j.second.find(x) == j.second.end())
            {
                break;
                flag = false;
            }
        }
        if (flag)
            ans = x;
    }
    return ans;
}

int main()
{
    return 0;
}