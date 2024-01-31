#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

int maximumLength(vector<int> &nums)
{
    unordered_map<double, int> mp;
    for (auto &&num : nums)
        mp[num]++;

    int cnt, ans = 1;

    for (auto &&num : nums)
    {
        cnt = 1;
        double p = pow(num, .5);

        while (p >= 2)
        {
            if (mp.find(p) != mp.end())
            {
                if (mp[p] >= 2)
                    cnt += 2;
                else
                    break;
                p = pow(p, .5);
            }
            else
            {
                break;
            }
        }
        ans = max(ans, cnt);
    }

    if (mp[1] > ans)
    {
        if (mp[1] & 1)
            return mp[1];
        else
            return mp[1] - 1;
    }
    return ans;
}

int main()
{
    return 0;
}