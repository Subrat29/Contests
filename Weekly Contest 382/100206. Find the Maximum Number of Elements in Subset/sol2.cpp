#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int maximumLength(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int cnt = 1;
    int n, m, first;
    for (int i = 0; i < nums.size(); i++)
    {
        first = nums[i];
        m = 0;
        n = nums[i];
        vector<int> ans;
        ans.push_back(n);
        while (m != n)
        {
            m = n;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] == n * n)
                {
                    n = nums[j];
                    ans.push_back(n);
                }
            }
        }

        m = 0;
        while (m != n && ans.size() > 1 && first != n)
        {
            m = n;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] == int(sqrt(n)))
                {
                    n = nums[j];
                    ans.push_back(n);
                }
            }
        }

        if (ans.size() % 2 != 0 && ans.size() > cnt)
            cnt = ans.size();
    }
    return cnt;
}

int main()
{
    return 0;
}