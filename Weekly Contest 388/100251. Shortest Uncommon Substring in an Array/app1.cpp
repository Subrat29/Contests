#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// if u dont use the cmp fn then it sort it by lexographically only but not by length.
static bool cmp(string a, string b)
{
    if (a.size() < b.size())
        return true;
    if (a.size() == b.size() && a < b)
        return true;
    return false;
}

vector<string> shortestSubstrings(vector<string> &arr)
{
    int n = arr.size();

    // 2d vector to store all possible substrings of input strings
    vector<vector<string>> substring(n);

    // map to store the frequency of every substrings
    map<string, int> mp;

    for (int i = 0; i < n; i++)
    {
        int len = arr[i].length();
        for (int j = 0; j < len; j++)
        {
            string ss = "";
            for (int k = j; k < len; k++)
            {
                ss += arr[i][k];
                bool flag = false;
                for (auto &&subStr : substring[i])
                {
                    if (subStr == ss)
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag)
                    continue;

                mp[ss]++;
                substring[i].push_back(ss);
            }
        }
        sort(substring[i].begin(), substring[i].end(), cmp);
    }

    vector<string> ans(n, "");
    for (int i = 0; i < n; i++)
    {
        for (auto &&j : substring[i])
        {
            if (mp[j] == 1)
            {
                ans[i] = j;
                break;
            }
        }
    }
    return ans;
}

int main()
{
    vector<string> input = {"gfnt", "xn", "mdz", "yfmr", "fi", "wwncn", "hkdy"};
    vector<string> ans = shortestSubstrings(input);

    return 0;
}

// Print the subarrays
// for (auto &&i : substring)
// {
//     cout << "-> ";
//     for (auto &&j : i)
//     {
//         cout << j << ", ";
//     }
//     cout << endl;
// }