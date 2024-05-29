#include <bits/stdc++.h>

using namespace std;

const int INF = numeric_limits<int>::max();

void bellmanFord(int source, const vector<vector<pair<int, int>>> &graph, int n)
{
    vector<int> distance(n, INF);
    vector<int> predecessor(n, -1); // To store the path information

    distance[source] = 0;

    for (int u = 0; u < n; u++)
    {
        for (const auto &neighbor : graph[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (distance[u] != INF && distance[u] + weight < distance[v])
            {
                distance[v] = distance[u] + weight;
                predecessor[v] = u;
            }
        }
    }

    // Check for negative-weight cycles
    for (int u = 0; u < n; u++)
    {
        for (const auto &neighbor : graph[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (distance[u] != INF && distance[u] + weight < distance[v])
            {
                cout << "Graph contains a negative-weight cycle" << endl;
                return;
            }
        }
    }

    // Output the shortest distances and paths from the source node
    for (int i = 0; i < n; ++i)
    {
        if (distance[i] == INF)
        {
            cout << "Path " << source << " to " << i << ": No path" << endl;
        }
        else
        {
            cout << "Path " << source << " to " << i << ": ";
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
}

int main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    string sourceLine;
    cin.ignore();
    getline(cin, sourceLine);

    int source = stoi(sourceLine.substr(sourceLine.find(" ") + 1));

    bellmanFord(source, graph, n);

    return 0;
}
