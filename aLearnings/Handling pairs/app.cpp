#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // If u have to compare pairs in vector then u can use these 2 approaches
    vector<int> v;

    // Approach 1
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] > v[i + 1]);
    }

    // Approach 2
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] > v[i - 1]);
    }

    return 0;
}