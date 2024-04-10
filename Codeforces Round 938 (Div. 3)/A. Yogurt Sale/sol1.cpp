#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t, n, a, b;
    cin >> t;
    while (t--)
    {
        cin >> n >> a >> b;
        if (2 * a < b)
            b = 2 * a;

        int noOf2Yogurt = n / 2;
        int noOf1Yogurt = n % 2;
        int minPrice = noOf2Yogurt * b + noOf1Yogurt * a;
        cout << minPrice << endl;
    }
    return 0;
}