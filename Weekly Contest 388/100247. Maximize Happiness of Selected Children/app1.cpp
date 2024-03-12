#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long maximumHappinessSum(vector<int> &happiness, int k)
{
    sort(happiness.begin(), happiness.end());

    int n = happiness.size();
    int cnt = 0;
    long long ans = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (cnt < k && (happiness[i] - cnt) > 0)
        {
            ans += happiness[i] - cnt;
            cnt++;
        }
        else
            break;
    }
    return ans;
}

int main()
{
    vector<int> happiness = {1,1,1,1};
    int k = 3;
    // vector<int> happiness = {3, 4, 5, 6, 7, 8, 9, 11, 12};
    // int k = 3;
    // vector<int> happiness = {2, 3, 4, 5};
    // int k = 1;
    // vector<int> happiness = {1, 1, 1, 1};
    // int k = 2;
    // vector<int> happiness = {1,2,3};
    // int k = 2;
    cout << "Ans: " << maximumHappinessSum(happiness, k);
    return 0;
}