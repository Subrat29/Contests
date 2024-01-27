#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// TLE: 507/549

// jabbhi minimum path ki baat ho aur weights na de rkhe ho to bfs lgao
// because defaultly it traverse with minimum path

vector<long long> countOfPairs(int n, int x, int y)
{
    vector<long long> ans(n,0);
    if (x == y)
    {
        for (int i = 1; i < n; i++)
        {
            ans[i-1] = (2 * (n - i));
        }
        return ans;
    }

    // adj list
    vector<vector<long long>> adj(n + 1);
    for (int i = 1; i < n; i++)
    {
        adj[i].push_back(i + 1);
        adj[i + 1].push_back(i);
    }

    // extra edge
    adj[x].push_back(y);
    adj[y].push_back(x);

    // bfs
    for (int i = 1; i <= n; i++)
    {
        queue<long long> q;
        q.push(i);
        vector<bool> visited(n + 1, false);
        visited[i] = true;

        int k = 0; // level
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                int node = q.front();
                q.pop();
                for (auto &&neighbour : adj[node])
                {
                    if (!visited[neighbour])
                    {
                        q.push(neighbour);
                        visited[neighbour] = true;
                        ans[k]++;
                    }
                }
            }
            k++;
        }
    }
    return ans;
}

int main()
{

    return 0;
}
