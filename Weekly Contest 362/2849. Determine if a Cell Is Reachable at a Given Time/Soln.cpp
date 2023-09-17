#include <iostream>
using namespace std;

// Catch
// sx: x ki direction me kuch distance(sx) se start hora h

bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
{
    int xdiff = abs(sx - fx);
    int ydiff = abs(sy - fy);

    if (xdiff == 0 && ydiff == 0 && t == 1)
        return false;
    return ((min(xdiff, ydiff) + abs(xdiff - ydiff)) <= t);
}

int main()
{

    return 0;
}