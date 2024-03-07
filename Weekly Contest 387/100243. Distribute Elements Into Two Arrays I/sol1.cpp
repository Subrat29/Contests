#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> resultArray(vector<int> &nums)
{
    vector<int> arr1;
    vector<int> arr2;
    arr1.push_back(nums[0]);
    arr2.push_back(nums[1]);

    for (int i = 2; i < nums.size(); i++)
    {
        if (arr1.back() > arr2.back())
            arr1.push_back(nums[i]);
        else
            arr2.push_back(nums[i]);
    }

    arr1.insert(arr1.end(), arr2.begin(), arr2.end());
    return arr1;
}

int main()
{
    vector<int> vec1 = {1, 2, 3};
    vector<int> vec2 = {4, 5, 6};
    vec1.insert(vec1.end(), vec2.begin(), vec2.end());

    return 0;
}