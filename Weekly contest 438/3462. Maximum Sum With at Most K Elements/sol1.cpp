#include <bits/stdc++.h>
using namespace std;

// tc: row*col * log(row*col)
// sc: row*col

class Solution
{
public:
    struct c
    {
        int num;
        int row;

        // Define comparison operator for max heap
        bool operator<(const c &other) const
        {
            return num < other.num; // Max heap based on `num`
        }
    };

    long long maxSum(vector<vector<int>> &grid, vector<int> &limits, int k)
    {
        int row = grid.size();
        int col = grid[0].size();
        priority_queue<c> pq;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                pq.push({grid[i][j], i});
            }
        }

        long long ans = 0;
        while (!pq.empty() && k > 0)
        {
            auto top = pq.top();
            pq.pop();

            int n = top.num;
            int n_row = top.row;

            if (limits[n_row] > 0)
            {
                ans += n;
                k--;
                limits[n_row]--;
            }
        }

        return ans;
    }
};

int main()
{
    return 0;
}