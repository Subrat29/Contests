#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool isPossibleToSplit(vector<int> &nums)
{
    unordered_map<int, int> mp;
    for (auto &&i : nums)
    {
        mp[i]++;
    }

    for (auto &&i : mp)
    {
        if (i.second > 2)
            return false;
    }
    return true;
}

int main()
{
    return 0;
}