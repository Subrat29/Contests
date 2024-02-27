#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time Limit Exceeded
// 711 / 717 testcases passed

int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
{
    int lcp = 0;
    for (int i = 0; i < arr1.size(); i++)
    {
        string a = to_string(arr1[i]);
        for (int i = 0; i < arr2.size(); i++)
        {
            string b = to_string(arr2[i]);
            int cnt = 0;
            for (int j = 0; j < a.length() && j < b.length(); j++)
            {
                if (a[j] == b[j])
                    cnt++;
                else
                    break;
            }
            lcp = max(lcp, cnt);
        }
    }
    return lcp;
}

int main()
{
    vector<int> arr1 = {32, 26};
    vector<int> arr2 = {72, 3216};
    cout << longestCommonPrefix(arr1, arr2);
    return 0;
}