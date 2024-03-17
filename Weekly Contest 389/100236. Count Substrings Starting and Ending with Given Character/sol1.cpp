#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long countSubstrings(string s, char c)
{
    int n = s.length();
    long long cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == c)
            cnt++;
    }
    long long ans = (cnt * (cnt + 1)) / 2;
    return ans;
}

int main()
{
    return 0;
}