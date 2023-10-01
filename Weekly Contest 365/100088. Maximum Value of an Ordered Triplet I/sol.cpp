#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long maximumTripletValue(vector<int> &nums)
{
    int n = nums.size();
    long long ans = 0;

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                long long triplet = (nums[i] - nums[j]) * nums[k];
                ans = max(ans, triplet);
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums;
    nums.push_back(12);
    nums.push_back(6);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(7);

    cout << "ans: " << maximumTripletValue(nums);

    return 0;
}