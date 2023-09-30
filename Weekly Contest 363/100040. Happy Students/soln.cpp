#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countWays(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int ans = 0, n = nums.size();
    int selected = 0;

    if (nums[0] != 0)
        ans = 1; // Not Selecting AnyOne
        
    for (int i = 0; i < n; i++)
    {
        selected++;
        if (selected > nums[i])
        {                                            // No. of Selected Students is strictly greater than nums[i].
            if (i + 1 < n && selected < nums[i + 1]) // Considering from (i+1) to n Students is not Selected.
                ans++;
            else if (i + 1 == n)
                ans++; // Last Student
        }
    }
    return ans;
}

int main()
{

    return 0;
}