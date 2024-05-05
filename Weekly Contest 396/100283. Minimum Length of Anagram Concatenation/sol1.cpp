#include <bits/stdc++.h>
using namespace std;

int minAnagramLength(string s)
{
    unordered_map<char, int> mp;
    if (s.length() % 2 != 0)
    {
        for (auto &&i : s)
            mp[i]++;
        if (mp.size() == 1)
            return 1;
        else
            return s.length();
    }
    int n = s.length() / 2;
    for (int i = 0; i < n; i++)
    {
        mp[i]++;
    }

    unordered_map<char, int> mp2;
    for (int i = n; i < s.length(); i++)
    {
        mp2[i]++;
    }

    if(mp.size() == mp2.size())
    {
        for (auto &&i : s)
        {
            if(mp[i] == mp2[i]);

        }
        
    }
    
}

int main()
{
    int ans = minAnagramLength("xxe");
    cout << ans;
    return 0;
}

// Input:
// "xxe"
// Output:
// 2
// Expected:
// 3