#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimumPushes(string word)
{
    int len = word.size();
    int ans = 0;
    
    if (len <= 8)
        ans = len;
    else if (len <= 16)
        ans = 8 + (len - 8) * 2;
    else if (len <= 24)
        ans = 8 + 16 + (len - 16) * 3;
    else if (len <= 26)
        ans = 8 + 16 + 24 + (len - 24) * 4;

    return ans;
}

int main()
{
    return 0;
}