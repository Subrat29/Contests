#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// If nums[i] < 0, it moves left by -nums[i] units.
// If nums[i] > 0, it moves right by nums[i] units.

int returnToBoundaryCount(vector<int> &nums)
{
    int boundaryValue = 0;
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        boundaryValue += nums[i];

        if (boundaryValue == 0)
            cnt++;
    }
    return cnt;
}

int main()
{
    vector<int> nums = {4, 6, 7, 8, -9, -9, 3, 4 - 14};
    cout << returnToBoundaryCount(nums) << endl;
    return 0;
}