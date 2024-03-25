#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>
using namespace std;

int maximumLengthSubstring(string s)
{
    int ans = INT_MIN;
    for (int i = 0; i < s.length(); i++)
    {
        int cnt = 0;
        map<char, int> mp;
        for (int j = i; j < s.length(); j++)
        {
            mp[s[j]]++;
            if (mp[s[j]] > 2)
                break;
            cnt++;
        }
        ans = max(ans, cnt);
    }
    return ans;
}

int main()
{
    string s = "bcbbbcba";
    cout << "Ans: " << maximumLengthSubstring(s);
    return 0;
}