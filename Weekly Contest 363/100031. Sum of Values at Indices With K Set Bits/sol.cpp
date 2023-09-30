#include <iostream>
#include <vector>
using namespace std;

int sumIndicesWithKSetBits(vector<int> &nums, int k)
{
    int res = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int noOfSetBits = 0;
        int i_copy = i;
        while (i_copy)
        {
            //checks if LSB of i_copy is set (equal to 1)
            noOfSetBits += i_copy & 1;
            //right shifts i_copy by one bit to examine next bit
            i_copy >>= 1;
        }
        if (noOfSetBits == k)
        {
            res += nums[i];
        }
    }
    return res;
}

int main()
{  
    vector<int> v;
    v.push_back(5);
    v.push_back(10);
    v.push_back(1);
    v.push_back(5);
    v.push_back(2);

    int k = 1;

    cout << sumIndicesWithKSetBits(v,k);

    return 0;
}


// Right shift concept (crystal clear)
// num >>= 1 --> num ko ek right shift krdo means num ke hr digit ko ek right shift kr do
// e.g:
// num = 6 (110)
//After right 1 digit shift
// 0 ko vhi rhne do
// first wale 1 ko 0 ki jagah daal do
// second 1 ko first 1 ki jagah daal do 

// Now, num = 3 (11) or (011)
