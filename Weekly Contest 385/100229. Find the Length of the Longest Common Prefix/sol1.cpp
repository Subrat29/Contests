#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
{
    int lcp = 0;
    for (int i = 0; i < arr1.size(); i++)
    {
        string a = to_string(arr1[i]);
        cout << a << endl;
        for (int i = 0; i < arr2.size(); i++)
        {
            string b = to_string(arr2[i]);
            cout << b << endl;
            int cnt = 0;
            for (int j = 0; j < a.length() && j < b.length(); j++)
            {
                cout << a[j] << ", " << b[j] << endl;
                if (a[j] == b[j])
                    cnt++;
                else
                    break;

                cout << "cnt: " << cnt << endl;
            }
            lcp = max(lcp, cnt);
        }
    }
    return lcp;
}

// [3,26]
// [7,16]

int main()
{
    vector<int> arr1 = {3, 26};
    vector<int> arr2 = {7, 16};
    cout << longestCommonPrefix(arr1, arr2);
    return 0;
}