#include <bits/stdc++.h>
using namespace std;

// m = message length
// n = bannedWords length

// tc: m + n
// sc: n

bool reportSpam(vector<string> &message, vector<string> &bannedWords)
{
    unordered_set<string> st(bannedWords.begin(), bannedWords.end());

    int cnt = 0;
    for (auto &&i : message)
    {
        if (st.find(i) != st.end())
            cnt++;
    }
    if (cnt >= 2)
        return true;
    else
        return false;
}

int main()
{
    return 0;
}