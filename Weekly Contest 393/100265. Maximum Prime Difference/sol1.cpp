#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPrime(int n)
{
    if (n == 1)
        return false;

    int factor = 2;
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i != 0)
            continue;
        factor++;
    }
    return factor == 2 ? true : false;
}

int maximumPrimeDifference(vector<int> &nums)
{
    int l = 0;
    int r = nums.size() - 1;
    int maxDiff = 0;
    while (l <= r)
    {
        if (!isPrime(nums[l]))
            l++;
        if (!isPrime(nums[r]))
            r--;
        if (isPrime(nums[l]) && isPrime(nums[r]))
        {
            maxDiff = max(maxDiff, r - l);
            break;
        }
    }
    return maxDiff;
}

int main()
{
    vector<int> v = {5};
    cout << 5 %2 << endl;
    cout << "Ans: "<< maximumPrimeDifference(v);
    return 0;
}