#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countKeyChanges(string s)
{
    int cnt = 0;
    for (int i = 0; i < s.size() - 1; i++)
    {
        int diff = abs(s[i] - s[i + 1]);
        if (diff != 32 || diff != 0)
            cnt++;
    }
    return cnt;
}

int main()
{
    return 0;
}