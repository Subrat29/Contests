#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

string lastNonEmptyString(string s)
{
    unordered_map<char, int> mp;
    int maxFreq = 0;
    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
        maxFreq = max(maxFreq, mp[s[i]]);
    }

    string ans = "";
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (mp[s[i]] == maxFreq)
            ans.push_back(s[i]);
        mp[s[i]]--;
    }
    return ans;
}

int main()
{
    return 0;
}