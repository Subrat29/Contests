#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimumBoxes(vector<int> &apple, vector<int> &capacity)
{
    int totalApple = 0;
    for (int i = 0; i < apple.size(); i++)
        totalApple += apple[i];

    sort(capacity.begin(), capacity.end());

    int cnt = 0;
    for (int j = capacity.size() - 1; j >= 0; j--)
    {
        if (totalApple > 0)
        {
            totalApple -= capacity[j];
            cnt++;
        }
        else
            break;
    }
    return cnt;
}

int main()
{
    return 0;
}