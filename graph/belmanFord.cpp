#include <bits/stdc++.h>
using namespace std;

void belman(int source, const vector<vector<pair<int, int>>> &graph, int n)
{
    vector<int> distance(n, INT_MAX);
    vector<int> pre(n, -1);

    distance[source] = 0;

    for (int currentNode = 0; currentNode < n; currentNode++)
    {
        for (const auto &nei : graph[currentNode])
        {
            int nextNode = nei.first;
            int dis = nei.second;

            int newDis = distance[currentNode] + dis;
            if (distance[currentNode] != INT_MAX && newDis < distance[nextNode])
            {
                distance[nextNode] = newDis;
                pre[nextNode] = currentNode;
            }
        }
    }

    for (int currentNode = 0; currentNode < n; currentNode++)
    {
        for (const auto &nei : graph[currentNode])
        {
            int nextNode = nei.first;
            int dis = nei.second;

            int newDis = distance[currentNode] + dis;
            if (distance[currentNode] != INT_MAX && newDis < distance[nextNode])
            {
                cout << "negative weight found";
                return;
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (distance[i] == INT_MAX)
        {
            cout << "Path " << source << " to " << i << ": No path" << endl;
        }
        else
        {
            cout << "Path " << source << " to " << i << ": ";
            vector<int> path;
            for (int at = i; at != -1; at = pre[at])
            {
                path.push_back(at);
            }
            reverse(path.begin(), path.end());
            for (size_t j = 0; j < path.size(); ++j)
            {
                if (j > 0)
                    cout << "->";
                cout << path[j];
            }
            cout << " Cost: " << distance[i] << endl;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    // string sourceLine;
    // cin.ignore();
    // getline(cin, sourceLine);

    // int source = stoi(sourceLine.substr(sourceLine.find(" ") + 1));

    int source;
    cin >> source;
    belman(source, graph, n);
}