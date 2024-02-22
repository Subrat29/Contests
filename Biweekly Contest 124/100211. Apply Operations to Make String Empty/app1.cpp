#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// Time Limit Exceeded
// 656 / 697 testcases passed

string lastNonEmptyString(string s)
{
    map<char, int> mp;
    string last = s;
    while (!s.empty())
    {
        last = s;
        for (int i = 0; i < s.size(); i++)
        {
            if (mp[s[i]] != 1)
            {
                mp[s[i]] = 1;
                s.erase(i, 1);
                i--;
            }
        }
        mp.clear();
    }
    return last;
}

int main()
{
    string s = "aabcbbca";
    cout << "ans: " << lastNonEmptyString(s) << endl;

    return 0;
}