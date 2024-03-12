#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
public:
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
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = arr.size();
        vector<string> ans(n, "");
        vector<vector<string>> substring(n);
        map<string, int> m;
        for (int i = 0; i < n; i++)
        {
            int k = arr[i].size();
            for (int j = 0; j < k; j++)
            {
                string sub = "";
                for (int l = j; l < k; l++)
                {
                    sub += arr[i][l];
                    bool found = false;
                    for (const auto &str : substring[i])
                    {
                        if (str == sub)
                        {
                            found = true;
                            break;
                        }
                    }
                    if (found)
                        continue;
                    m[sub]++;
                    substring[i].push_back(sub);
                }
            }
            sort(substring[i].begin(), substring[i].end(), cmp);
        }
        for (int i = 0; i < n; i++)
        {
            for (auto it : substring[i])
            {
                if (m[it] == 1)
                {
                    ans[i] = it;
                    break;
                }
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}