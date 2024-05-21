#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// sc: 10*10
// tc: n*10
// max digit: 10

unordered_map<int, unordered_map<char, long long>> mp;

void compute(int n)
{
    string num = to_string(n);
    for (int i = 0; i < num.size(); i++)
        mp[i][num[i]]++;
}

long long sumDigitDifferences(vector<int> &nums)
{
    for (auto &&num : nums)
        compute(num);
    
    long long ans = 0;
    for (auto &&num : nums)
    {
        string s = to_string(num);
        for (int i = 0; i < s.size(); i++)
        {
            ans += nums.size() - mp[i][s[i]];
        }
    }
    return ans/2;
}

int main()
{
    return 0;
}