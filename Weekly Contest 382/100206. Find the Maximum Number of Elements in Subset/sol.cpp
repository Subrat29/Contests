#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>
#include <algorithm>
using namespace std;

// [15,15,225,225,50625,50625]

int main()
{
    vector<int> nums = {5, 4, 1, 2, 2};
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
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        if (ans.size() % 2 != 0 && ans.size() > cnt)
            cnt = ans.size();
    }
    cout << "count: " << cnt << endl;
    return 0;
}
