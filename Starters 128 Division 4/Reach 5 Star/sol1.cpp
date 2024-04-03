#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    x += y;
    string ans = "NO";
    if (x >= 2000)
        ans = "YES";
    cout << ans;
    return 0;
}