#include <iostream>
#include <unordered_map>
using namespace std;

int numberOfPoints(vector<vector<int>> &nums)
{
    unordered_map<int, bool> umap;
    int count = 0;

    // for (auto x : umap)
    // {
    //     x.second = false;
    // }

    for (int i = 0; i < nums.size(); i++)
    {
        int start = nums[i][0];
        int end = nums[i][1];

        for (int i = start; i <= end; i++)
        {
            if (umap[i] != true)
            {
                // umap.insert(make_pair(i, true));
                umap[i] = true;
                count++;
            }
        }
    }

    return count;
}

int main()
{

    return 0;
}