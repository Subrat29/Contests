#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countPrefixSuffixPairs(vector<string> &words)
{
    int cnt = 0;
    for (int i = 0; i < words.size(); i++)
    {
        for (int j = 0; j < words.size(); j++)
        {
            if (2 * words[i].size() < word[j].size())
            {
                string s1 = words[i];
                string s2 = words[j];
                bool flag = true;

                for (int k = 0; k < s1.size(); k++)
                {
                    if (s1[k] == s2[k] && s1[k] == s2[s1.size() + k])
                        continue;
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    return 0;
}