#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

// TLE: 719/725
int maximumLength(vector<int> &nums)
{
    int cnt = 1;
    sort(nums.begin(), nums.end());
    unordered_map<int, int> occurrenceMap;
    for (int num : nums)
    {
        occurrenceMap[num]++;
    }

    if (occurrenceMap[1] && occurrenceMap[1] % 2 == 0)
        cnt = occurrenceMap[1] - 1;
    else
        cnt = occurrenceMap[1];

    for (int i = 0; i < nums.size(); i++)
    {
        int first = nums[i];
        int m = 0;
        int n = nums[i];
        vector<int> ans;
        ans.push_back(n);
        occurrenceMap[n]--;
        int flag = i;
        while (m != n)
        {
            m = n;
            for (int j = flag + 1; j < nums.size(); j++)
            {
                if (nums[j] / n == n && occurrenceMap[nums[j]] > 0)
                {
                    n = nums[j];
                    flag = j;
                    ans.push_back(n);
                    occurrenceMap[n]--;
                    break;
                }
            }
        }

        m = -1;
        while (m != n && ans.size() > 1 && first != n)
        {
            m = n;
            for (int j = i + 1; j < flag; j++)
            {
                if (nums[j] == int(sqrt(n)) && occurrenceMap[nums[j]] > 0)
                {
                    n = nums[j];
                    flag = j;
                    ans.push_back(n);
                    occurrenceMap[n]--;
                    break;
                }
            }
            if (m == n)
            {
                ans.pop_back();
                n = ans.back();
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