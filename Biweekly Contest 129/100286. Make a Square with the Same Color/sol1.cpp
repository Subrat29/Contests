#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canMakeSquare(vector<vector<char>> &grid)
{
    int black, white;

    black = 0, white = 0;

    if (grid[0][0] == 'B')
        black++;
    else
        white++;

    if (grid[0][1] == 'B')
        black++;
    else
        white++;

    if (grid[1][0] == 'B')
        black++;
    else
        white++;

    if (grid[1][1] == 'B')
        black++;
    else
        white++;

    if (black - white != 0)
        return true;

    black = 0, white = 0;

    if (grid[0][1] == 'B')
        black++;
    else
        white++;

    if (grid[0][2] == 'B')
        black++;
    else
        white++;

    if (grid[1][1] == 'B')
        black++;
    else
        white++;

    if (grid[1][2] == 'B')
        black++;
    else
        white++;

    if (black - white != 0)
        return true;

    black = 0, white = 0;

    if (grid[1][0] == 'B')
        black++;
    else
        white++;

    if (grid[1][1] == 'B')
        black++;
    else
        white++;

    if (grid[2][0] == 'B')
        black++;
    else
        white++;

    if (grid[2][1] == 'B')
        black++;
    else
        white++;

    if (black - white != 0)
        return true;

    black = 0, white = 0;

    if (grid[1][1] == 'B')
        black++;
    else
        white++;

    if (grid[1][2] == 'B')
        black++;
    else
        white++;

    if (grid[2][1] == 'B')
        black++;
    else
        white++;

    if (grid[2][2] == 'B')
        black++;
    else
        white++;

    if (black - white != 0)
        return true;

    return false;
}

int main()
{
    return 0;
}