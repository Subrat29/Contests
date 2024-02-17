#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxOperations(vector<int> &nums)
{
    int sum = nums[0] + nums[1];
    int cnt = 0;
    while (nums.size() >= 2)
    {
        if (nums[0] + nums[1] == sum)
        {
            nums.erase(nums.begin(), nums.begin() + 2);
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