#include <bits/stdc++.h>
using namespace std;

// sc:
// tc:

// Learning: if int a = 11 then ans is in int
// double a = 11;
// double ans = a/2;
// cout << "ans::" << ans;

double minimumAverage(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    double mini = INT_MAX;
    int n = nums.size();
    for (int i = 0; i < n / 2; i++)
    {
        cout << "nums1: " << nums[i] << endl;
        cout << "nums2: " << nums[n - i - 1] << endl;

        double x = double(nums[i] + nums[n - i - 1]) / 2;
        cout << "x: " << x << endl;
        if (x < mini)
            mini = x;
    }
    return mini;
}

int main()
{
    return 0;
}