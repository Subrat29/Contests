#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> nums = {4, 4, 16, 256};

    unordered_map<int, int> occurrenceMap;
    for (int num : nums)
    {
        occurrenceMap[num]++;
    }

    sort(nums.begin(), nums.end());

    cout << "Print vector : ";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    int cnt = 1;
    int n, m, first;
    for (int i = 0; i < nums.size(); i++)
    {
        first = nums[i];
        m = 0;
        n = nums[i];
        vector<int> ans;
        ans.push_back(n);
        occurrenceMap[n]--;
        int flag = i;
        while (m != n)
        {
            m = n;
            for (int j = flag + 1; j < nums.size(); j++)
            {
                if (nums[j] == n * n && occurrenceMap[nums[j]] > 0)
                {
                    n = nums[j];
                    flag = j;
                    ans.push_back(n);
                    occurrenceMap[n]--;
                    break;
                }
            }
        }

        m = 0;
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
