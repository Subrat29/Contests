#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sumOfTheDigitsOfHarshadNumber(int x)
{
    string s = to_string(x);
    int num = 0;
    for (int i = 0; i < s.length(); i++)
        num += s[i] - '0';

    if (x % num == 0)
        return num;
    else
        return -1;
}

int main()
{
    int x = 23;
    cout << sumOfTheDigitsOfHarshadNumber(x);
    return 0;
}