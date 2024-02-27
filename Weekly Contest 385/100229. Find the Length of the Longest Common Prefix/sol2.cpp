#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Hint 1 - Put all the possible prefixes of each element in arr1 into a HashSet.
// Hint 2 - For all the possible prefixes of each element in arr2, check if it exists in the HashSet.

// The elements are hashed into different buckets based on their hash values, allowing for fast average
// constant-time insertion, deletion, and lookup operations.

int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
{
    unordered_set<int> s;
    for (auto &&i : arr1)
    {
        while (i > 0)
        {
            s.insert(i);
            i = i / 10;
        }
    }

    int lcp = 0;
    for (auto &&i : arr2)
    {
        while (i > 0)
        {
            if (s.find(i) != s.end())
            {
                string digit = to_string(i);
                int length = digit.length();
                lcp = max(lcp, length);
            }
            i = i / 10;
        }
    }
    return lcp;
}

int main()
{
    vector<int> arr1 = {1, 10, 100};
    vector<int> arr2 = {1000};
    cout << longestCommonPrefix(arr1, arr2);
    return 0;
}