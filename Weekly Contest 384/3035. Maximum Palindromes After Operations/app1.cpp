#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int maxPalindromesAfterOperations(vector<string> &words)
{
    // step1: find freq of all characters
    unordered_map<char, int> mp;
    for (int i = 0; i < words.size(); i++)
    {
        for (int j = 0; j < words[i].size(); j++)
            mp[words[i][j]]++;
    }

    // step2: count total number of pairs present
    int totalPairs = 0;
    for (auto &&ch : mp)
    {
        totalPairs += ch.second / 2;
    }
    cout << "tp = " << totalPairs << endl;

    // step3: find pairs required for each word
    vector<int> pairRequire;
    for (int i = 0; i < words.size(); i++)
    {
        pairRequire.push_back(words[i].size() / 2);
    }

    // step4: sort the pairRequire vector bc we have to find max palindrome acc to word length
    sort(pairRequire.begin(), pairRequire.end());

    // step5: At Last, traverse pairRequire and find ans
    int ans = 0;
    for (int i = 0; i < pairRequire.size(); i++)
    {
        if (pairRequire[i] > totalPairs)
            break;
        totalPairs = totalPairs - pairRequire[i];
        ans++;
    }
    return ans;
}

int main()
{
    vector<string> words = {"abbcc", "acab", "ba", "bab", "l"};
    maxPalindromesAfterOperations(words);
    return 0;
}