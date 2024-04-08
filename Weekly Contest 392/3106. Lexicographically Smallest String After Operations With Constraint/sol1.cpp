#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string getSmallestString(string s, int k)
{
    for (char &ch : s)
    {
        int left = ch - 'a';
        int right = 'z' - ch + 1;
        int mini = min(left, right);

        if (k >= mini)
        {
            k = k - mini;
            ch = 'a';
        }
        else
        {
            ch = char(ch - k);
            break;
        }
    }
    return s;
}

int main()
{
    return 0;
}