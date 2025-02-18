// Tc: n^2
// Sc: n

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool maxSubstringLength(string s, int k)
{
    unordered_map<char, int> firstOccurence, lastOccurence;
    vector<pair<int, int>> intervals;
    int n = s.size();

    // Store the first and last occurrence (index) of each char in the input string
    for (int i = 0; i < n; i++)
    {
        if (firstOccurence.count(s[i]) == 0)
        {
            firstOccurence[s[i]] = i;
        }
        lastOccurence[s[i]] = i;
    }

    // Store valid special substrings
    for (int i = 0; i < n; i++)
    {
        if (i != firstOccurence[s[i]])
        {
            continue;
        }

        int left = firstOccurence[s[i]];
        int right = lastOccurence[s[i]];
        bool isValid = true;

        for (int j = left; j <= right; j++)
        {
            if (firstOccurence[s[j]] < left)
            {
                isValid = false;
                break;
            }
            right = max(right, lastOccurence[s[j]]);
        }

        if (isValid && right - left + 1 < n)
        {
            intervals.push_back({left, right});
        }
    }

    // Sort all the intervals according to their last occurrence
    sort(intervals.begin(), intervals.end(), [](auto &a, auto &b)
         { return a.second < b.second; });

    // Count valid disjoint special substrings
    int cnt = 0;
    int lastEnd = -1;
    for (auto &[start, end] : intervals)
    {
        if (lastEnd < start)
        {
            cnt++;
            lastEnd = end;
        }
    }

    return cnt >= k;
}
int main()
{
    return 0;
}