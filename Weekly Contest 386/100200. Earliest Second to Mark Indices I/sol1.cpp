#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

// 533 / 570 testcases passed
int earliestSecondToMarkIndices(vector<int> &nums, vector<int> &changeIndices)
{
    int n = nums.size();
    int m = changeIndices.size();
    vector<bool> mark(n, false);
    vector<int> priority(n, 0);

    int total = n;
    for (int i = 0; i < n; i++)
    {
        total += nums[i];
    }

    for (int i = total - 1; i >= 0; i--)
    {
        if (priority[changeIndices[i] - 1] == 0)
            priority[changeIndices[i] - 1] = i;
    }

    for (int i = 0; i < m; i++)
    {
        if (nums[changeIndices[i] - 1] == 0 && mark[changeIndices[i] - 1] == false)
        {
            mark[changeIndices[i] - 1] = true;
        }
        else
        {
            int mini = INT_MAX;
            int idx = -1;
            for (int j = 0; j < priority.size(); j++)
            {
                if (mark[j] == false && nums[j] != 0 && mini > priority[j])
                {
                    mini = min(mini, priority[j]);
                    idx = j;
                }
            }
            if (idx != -1)
                nums[idx]--;
        }

        bool flag = true;
        for (int k = 0; k < mark.size(); k++)
        {
            if (mark[k] == false)
            {
                flag = false;
                break;
            }
        }

        if (flag)
            return i + 1;
    }
    return -1;
}

int main()
{
    vector<int> nums = {2, 4};
    vector<int> changeIndices = {1, 2, 1, 2, 1, 1, 2, 1, 1, 1, 2};
    // vector<int> nums = {0,1};
    // vector<int> changeIndices = {2,2,2};
    // vector<int> nums = {1,3};
    // vector<int> changeIndices = {1,1,1,2,1,1,1};
    // vector<int> nums = {2, 2, 0};
    // vector<int> changeIndices = {2, 2, 2, 2, 3, 2, 2, 1};

    cout << "  ans :: " << earliestSecondToMarkIndices(nums, changeIndices);

    return 0;
}