#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countPrefixSuffixPairs(vector<string> &words)
{
    int cnt = 0;
    for (int i = 0; i < words.size(); i++)
    {
        for (int j = i + 1; j < words.size(); j++)
        {
            string s1 = words[i];
            string s2 = words[j];

            if (s1 == s2)
                cnt++;

            else if (s1.size() < s2.size())
            {
                bool flag = true;
                for (int k = 0; k < s1.size(); k++)
                {
                    if (s1[k] == s2[k] && s1[k] == s2[s2.size() - s1.size() + k])
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