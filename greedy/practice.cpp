#include <bits/stdc++.h>
using namespace std;

int primsTree(int source, vector<vector<int>> adj[], int n)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<bool> vis(n, false);
    pq.push({0, source});
    int sum = 0;

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int dis = it.first;
        if (vis[node])
            continue;
        vis[node] = true;
        sum += dis;
        for (auto it : adj[node])
        {
            int adj = it[0];
            int edW = it[1];
            if (!vis[adj])
            {
                pq.push({edW, adj});
            }
        }
    }

    return sum;
}

int main()
{

    int n = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    vector<vector<int>> adj[n];
    for (auto it : edges)
    {
        vector<int> tmp(2);
        tmp[0] = it[1];
        tmp[1] = it[2];
        adj[it[0]].push_back(tmp);

        tmp[0] = it[0];
        tmp[1] = it[2];
        adj[it[1]].push_back(tmp);
    }

    int sum = primsTree(0, adj, n);
    cout << sum;
}