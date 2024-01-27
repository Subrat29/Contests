#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int minimumPushes(string word)
{
    // step1: create a map which has word and its freqency
    unordered_map<char, int> mp;
    for (auto &&c : word)
    {
        mp[c]++;
    }

    // step2: create a queue and push all char with freq so we can take highest freq char each time
    priority_queue<pair<int, char>> q;
    for (auto &&i : mp)
    {
        q.push({i.second, i.first});
    }

    int ans = 0;
    int i = 1;
    while (!q.empty())
    {
        int freq = q.top().first;
        q.pop();

        if (i <= 8)
            ans += freq;
        else if (i <= 16)
            ans += freq * 2;
        else if (i <= 24)
            ans += freq * 3;
        else if (i <= 26)
            ans += freq * 4;
        i++;
    }
    return ans;
}

int main()
{
    return 0;
}