#include <bits/stdc++.h>
using namespace std;

void dijkstra(int s, const vector<vector<pair<int, int>>> &graph, int n)
{
    vector<int> distance(n, INT_MAX);
    vector<bool> visited(n, false);
    vector<int> predecessor(n, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distance[s] = 0;
    pq.emplace(0, s);

    while (!pq.empty())
    {
        int currentDistance = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if (visited[currentNode])
            continue;
        visited[currentNode] = true;

        for (const auto &n : graph[currentNode])
        {
            int nextNode = n.first;
            int dist = n.second;

            int new_distance = currentDistance + dist;

            if (new_distance < distance[nextNode])
            {
                distance[nextNode] = new_distance;
                predecessor[nextNode] = currentNode;
                pq.emplace(new_distance, nextNode);
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (distance[i] == INT_MAX)
        {
            cout << "Path " << s << " to " << i << ": No path" << endl;
        }
        else
        {
            cout << "Path " << s << " to " << i << ": ";
            vector<int> path;
            for (int at = i; at != -1; at = predecessor[at])
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

    cout << endl
         << endl;

    for (int i = 0; i < n; i++)
    {
        cout << predecessor[i] << " ";
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

    int soruce;
    cin >> soruce;

    for (int i = 0; i < n; i++)
    {
        cout << "Current node " << i << " " << endl;
        for (const auto &edge : graph[i])
        {
            cout << edge.first << ", " << edge.second << endl;
        }
    }
    cout << endl
         << endl;
    dijkstra(soruce, graph, n);
}