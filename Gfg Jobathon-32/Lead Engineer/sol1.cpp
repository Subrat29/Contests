#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int leadOptions(int N, vector<int> &E)
{
    int maxElement = *max_element(E.begin(), E.end());
    int cnt = 0;
    for (auto &&i : E)
    {
        if (i == maxElement)
            cnt++;
    }
    return cnt;
}

int main()
{
    return 0;
}