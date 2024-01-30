#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> nums = {2, 4, 1, 1, 4, 16, 14, 20};

    sort(nums.begin(), nums.end());

    cout << "Print vector : ";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    int cnt = 1;
    int n, first;
    for (int i = 0; i < nums.size(); i++)
    {
        unordered_map<int, int> occurrenceMap;
        for (int num : nums)
            occurrenceMap[num]++;

        first = nums[i];
        n = nums[i];
        vector<int> ans;
        ans.push_back(n);
        occurrenceMap[n]--;
        bool check = true;

        while (check)
        {
            if (occurrenceMap[n * n] > 0)
            {
                n = n * n;
                ans.push_back(n);
                occurrenceMap[n]--;
            }
            else
            {
                check = false;
            }
        }

        cout << "Print Map: " << endl;
        for (auto num : occurrenceMap)
            cout << num.first << ": " << num.second << endl;
        cout << endl;

        while (ans.size() > 1 && first != n)
        {
            if (occurrenceMap[int(sqrt(n))] > 0)
            {
                cout << "hii" << int(sqrt(n)) << endl;
                n = int(sqrt(n));
                ans.push_back(n);
                occurrenceMap[n]--;
            }
            else
            {
                cout << "Idhr" << endl;
                ans.pop_back();
                n = ans.back();
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
