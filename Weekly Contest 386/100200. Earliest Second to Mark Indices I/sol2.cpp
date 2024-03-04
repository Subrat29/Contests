#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

bool binarySearch(vector<int> &nums, vector<int> &changeIndices, int idx)
{
    unordered_map<int, int> last;
    for (int i = 0; i < idx; i++)
        last[changeIndices[i]] = i;

    if (last.size() != nums.size())
        return false;

    int cnt = 0; // record we can reduce how many number
    for (int i = 0; i < idx; i++)
    {
        // if it is last time we visit this idx, we must mark
        // so check whether this idx already reduce to zero, if not, then return false.
        if (i == last[changeIndices[i]])
        {
            if (cnt < nums[changeIndices[i] - 1])
                return false;
            else
                cnt -= nums[changeIndices[i] - 1];
        }
        else
        {
            cnt++;
        }
    }
    return true;
}

int earliestSecondToMarkIndices(vector<int> &nums, vector<int> &changeIndices)
{
    int n = nums.size();
    int m = changeIndices.size();
    int l = 0;
    int r = m + 1;

    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (binarySearch(nums, changeIndices, mid))
            r = mid;
        else
            l = mid + 1;
    }
    return r == m + 1 ? -1 : r;
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