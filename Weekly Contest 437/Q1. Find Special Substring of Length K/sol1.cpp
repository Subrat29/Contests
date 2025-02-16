#include <bits/stdc++.h>
using namespace std;

// tc: O(n-k+1)*O(k) ~ nk
// sc: k

bool isCond1(string ss)
{
    for (int i = 1; i < ss.size(); i++)
    {
        if (ss[0] != ss[i])
            return false;
    }
    return true;
}

bool hasSpecialSubstring(string s, int k)
{
    int n = s.size();
    for (int i = 0; i <= n - k; i++)
    {
        string ss = s.substr(i, k);

        if (isCond1(ss))
        {
            if ((i == 0) || (s[i - 1] != s[i]))
            {
                if ((i + k == n) || (s[i + k - 1] != s[i + k]))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    return 0;
}