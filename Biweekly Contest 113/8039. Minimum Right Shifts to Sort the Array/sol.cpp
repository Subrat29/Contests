#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void display(string s)
{
    cout << s << endl;
    cout << endl;
}

void shiftArray(vector<int> &nums)
{
    print(nums);
    display("RS outside loop start me");

    for (int i = 1; i < nums.size(); i++)
    {
        // if (i == 0)
        // {
        //     nums[i] = nums[nums.size() - 1];
        // }

        nums[i] = nums[i - 1];

        print(nums);
        display("RS inside loop");
    }

    print(nums);
    display("RS outside loop end me ");
}

int minimumRightShifts(vector<int> &nums)
{
    print(nums);
    display("minmRS before loop enter");

    int cnt = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        print(nums);
        display("minmRS inside loop enter");

        if (nums[i] > nums[i + 1])
        {
            cnt++;
            shiftArray(nums);

            print(nums);
            display("minmRS inside if condn");
        }

        print(nums);
        display("minmRS outside loop end fn time");
    }
    return cnt;
}

int main()
{
    vector<int> nums;
    nums.push_back(5);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);

    print(nums);
    display("main before fn call");

    int a = minimumRightShifts(nums);

    // cout << "ans: " << a;

    return 0;
}