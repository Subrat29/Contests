#include <iostream>
#include <string>
using namespace std;

bool isSymmetric(int num)
{
    string numStr = to_string(num);
    int length = numStr.length();

    if (length % 2 != 0)
    {
        return false;
    }

    int a = 0;
    int b = 0;

    for (int i = 0; i < length / 2; i++)
    {
        a = a + numStr[i] - '0';
        b = b + numStr[length - 1 - i] - '0';
    }

    if (a == b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int countSymmetricIntegers(int low, int high)
{
    int count = 0;
    for (int i = low; i <= high; i++)
    {
        if (isSymmetric(i))
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int a = countSymmetricIntegers(1200, 1230);
    cout << "Ans = " << a;
    return 0;
}
