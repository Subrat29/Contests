#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> par;
vector<int> rank;
vector<int> wgt;

int find(int n)
{
    if (par[n] != n)
        return find(par[n]);
    return par[n];
}

void merge(int s, int d, int w)
{
    int ps = find(s);
    int pd = find(d);
    if (ps == pd)
    {
        if (wgt[ps] == -1)
            wgt[ps] = w;
        else
            wgt[ps] = (wgt[ps] & w);
        return;
    }
    if (rank[ps] > rank[pd])
    {
        par[pd] = ps;
        if (wgt[ps] == -1)
            wgt[ps] = w;
        else
            wgt[ps] = (wgt[ps] & w & wgt[pd]);
        rank[ps]++;
    }
    else
    {
        par[ps] = pd;
        if (wgt[pd] == -1)
            wgt[pd] = w;
        else
            wgt[pd] = (wgt[pd] & w & wgt[ps]);
        rank[pd]++;
    }
}

vector<int> minimumCost(int n, vector<vector<int>> &v, vector<vector<int>> &q)
{
    for (int i = 0; i < n; i++)
    {
        par.push_back(i);
        rank.push_back(0);
        wgt.push_back(-1);
    }

    for (int i = 0; i < v.size(); i++)
    {
        int s = v[i][0], d = v[i][1], w = v[i][2];
        merge(s, d, w);
    }

    int m = q.size();
    vector<int> ans;
    for (int i = 0; i < m; i++)
    {
        int s = q[i][0], d = q[i][1];
        if (s == d)
        {
            ans.push_back(0);
            continue;
        }
        int ps = find(s);
        int pd = find(d);
        if (ps != pd)
            ans.push_back(-1);
        else
            ans.push_back(wgt[ps]);
    }
    return ans;
}

int main()
{
    return 0;
}