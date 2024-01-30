#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>
#include <algorithm>
using namespace std;

// TLE = 724/725
int maximumLength(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    unordered_map<int, int> occurrenceMap;
    for (int num : nums)
    {
        occurrenceMap[num]++;
    }

    int cnt = 1;
    if (occurrenceMap[1] && occurrenceMap[1] % 2 == 0)
        cnt = occurrenceMap[1] - 1;
    else
        cnt = occurrenceMap[1];

    int n, first;
    for (int i = 0; i < nums.size(); i++)
    {
        first = nums[i];
        n = nums[i];
        vector<int> ans;
        ans.push_back(n);
        occurrenceMap[n]--;
        bool check = true;

        while (check)
        {
            long long next_num = static_cast<long long>(n) * static_cast<long long>(n);
            if (next_num <= numeric_limits<int>::max() && occurrenceMap[next_num] > 0)
            {
                n = static_cast<int>(next_num);
                ans.push_back(n);
                occurrenceMap[n]--;
            }
            else
            {
                check = false;
            }
        }

        while (ans.size() > 1 && first != n)
        {
            if (occurrenceMap[int(sqrt(n))] > 0)
            {
                n = int(sqrt(n));
                ans.push_back(n);
                occurrenceMap[n]--;
            }
            else
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