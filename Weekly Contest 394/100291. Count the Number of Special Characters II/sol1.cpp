#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;

int numberOfSpecialChars(string word)
{
    unordered_map<char, int> mp;
    for (int i = 0; i < word.size(); i++)
    {
        if (!mp[word[i]] && int(word[i]) >= 65 && int(word[i]) <= 90)
            mp[word[i]] = i + 1;
    }

    for (int i = word.size() - 1; i >= 0; i--)
    {
        if (!mp[word[i]] && int(word[i]) >= 97 && int(word[i]) <= 122)
            mp[word[i]] = i + 1;
    }

    int cnt = 0;
    for (int i = 0; i < word.size(); i++)
    {
        // capital letters
        if (int(word[i]) >= 65 && int(word[i]) <= 90)
        {
            int low = int(word[i]) + 32;
            char clow = char(low);
            if (mp[clow] > 0 && mp[word[i]] > 0 && mp[clow] < mp[word[i]])
            {
                mp[clow] = 0;
                mp[word[i]] = 0;
                cnt++;
                cout << "cnt Update" << endl;
                cout << clow << " < " << word[i] << endl;
                cout << mp[clow] << " < " << mp[word[i]] << endl;
            }
        }
    }

    for (auto &&i : mp)
        cout << i.first << ": " << i.second << endl;

    return cnt;
}

int main()
{
    // string s = "aaAaA";
    // string s = "aaAbcBC";
    // string s = "AbBCab";
    string s = "dcbCC";
    cout << "Ans: " << numberOfSpecialChars(s);
    return 0;
}