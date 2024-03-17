#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isSubstringPresent(string s)
{
    string rev = s;
    reverse(rev.begin(), rev.end());
    int n = s.length() - 1;

    for (int i = 0; i < n; i++)
    {
        string a = "";
        for (int l = i; l < i + 2; l++)
            a += s[l];

        for (int j = 0; j < n; j++)
        {
            string b = "";
            for (int m = j; m < j + 2; m++)
                b += rev[m];

            if (a == b)
                return true;
        }
    }
    return false;
}

int main()
{
    string s = "abcba";
    // string s = "abcd";
    cout << isSubstringPresent(s) << endl;

    return 0;
}