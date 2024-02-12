#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> modifiedMatrix(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();

    for (size_t i = 0; i < col; i++)
    {
        int maxi = -1;
        for (size_t j = 0; j < row; j++)
        {
            maxi = max(matrix[j][i], maxi);
        }

        for (size_t j = 0; j < row; j++)
        {
            if (matrix[j][i] == -1)
                matrix[j][i] = maxi;
        }
    }
    return matrix;
}

int main()
{
    return 0;
}