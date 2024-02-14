#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TLE 775 / 782
int countMatchingSubarrays(vector<int> &nums, vector<int> &pattern)
{
    vector<int> arr;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] < nums[i + 1])
            arr.push_back(1);

        else if (nums[i] == nums[i + 1])
            arr.push_back(0);

        else if (nums[i] > nums[i + 1])
            arr.push_back(-1);
    }

    int l = arr.size() - pattern.size();
    int cnt = 0;
    for (int i = 0; i <= l; i++)
    {
        bool flag = true;
        for (int j = 0; j < pattern.size(); j++)
        {
            if (arr[i + j] != pattern[j])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cnt++;
    }
    return cnt;
}

int main()
{
    vector<int> nums = {376068870, 376068870, 376068870};
    vector<int> pattern = {0, 0};
    // vector<int> nums = {1, 4, 4, 1, 3, 5, 5, 3};
    // vector<int> pattern = {1, 0, -1};
    cout << "ans: " << countMatchingSubarrays(nums, pattern);
    return 0;
}