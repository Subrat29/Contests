#include <bits/stdc++.h>
using ll = signed long long int;
using namespace std;

vector<bool> findAnswer(int n, vector<vector<int>> &edges)
{
    // create a adj list
    vector<vector<pair<int, int>>> adj(n);
    for (auto &&edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<ll> d1(n, INT_MAX);
    vector<ll> d2(n, INT_MAX);

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> q1;
    q1.push({0, 0});
    d1[0] = 0;

    while (!q1.empty())
    {
        int currDist = q1.top().first;
        int currNode = q1.top().second;
        q1.pop();

        if (currDist > d1[currNode])
            continue;

        for (auto &&nbr : adj[currNode])
        {
            int nbrNode = nbr.first;
            int nbrWt = nbr.second;

            if (currDist + nbrWt < d1[nbrNode])
            {
                d1[nbrNode] = currDist + nbrWt;
                q1.push({d1[nbrNode], nbrNode});
            }
        }
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> q2;
    q2.push({0, n - 1});
    d2[n - 1] = 0;

    while (!q2.empty())
    {
        int currDist = q2.top().first;
        int currNode = q2.top().second;
        q2.pop();

        if (currDist > d2[currNode])
            continue;

        for (auto &&nbr : adj[currNode])
        {
            int nbrNode = nbr.first;
            int nbrWt = nbr.second;

            if (currDist + nbrWt < d2[nbrNode])
            {
                d2[nbrNode] = currDist + nbrWt;
                q2.push({d2[nbrNode], nbrNode});
            }
        }
    }
    vector<bool> ans(edges.size(), false);
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        if (d1[u] + d2[v] + w == d1[n - 1] || d1[v] + d2[u] + w == d1[n - 1])
            ans[i] = true;
    }
    return ans;
}

int main()
{
    return 0;
}