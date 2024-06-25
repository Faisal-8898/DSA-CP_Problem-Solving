#include <bits/stdc++.h>

using namespace std;

// Function to perform BFS and find an augmenting path
bool bfs(vector<vector<int>> &residualGraph, int source, int sink, vector<int> &parent)
{
    int n = residualGraph.size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; ++v)
        {
            if (!visited[v] && residualGraph[u][v] > 0)
            {
                if (v == sink)
                {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return false;
}

// Function to implement the Ford-Fulkerson algorithm using Edmonds-Karp method
int fordFulkerson(vector<vector<int>> &graph, int source, int sink)
{
    int u, v;
    int n = graph.size();

    // Create a residual graph and fill the residual graph with given capacities in the original graph
    vector<vector<int>> residualGraph(n, vector<int>(n));
    for (u = 0; u < n; ++u)
    {
        for (v = 0; v < n; ++v)
        {
            residualGraph[u][v] = graph[u][v];
        }
    }

    vector<int> parent(n); // This array is filled by BFS and to store path

    int maxFlow = 0; // There is no flow initially

    // Augment the flow while there is a path from source to sink
    while (bfs(residualGraph, source, sink, parent))
    {
        // Find the maximum flow through the path found by BFS
        int pathFlow = INT_MAX;
        for (v = sink; v != source; v = parent[v])
        {
            u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }

        // Update residual capacities of the edges and reverse edges along the path
        for (v = sink; v != source; v = parent[v])
        {
            u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        // Add the path flow to the overall flow
        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main()
{
    int n; // Number of vertices
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    // Reading the capacity matrix
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> graph[i][j];
        }
    }

    int source, sink;
    cin >> source >> sink;

    cout << "The maximum possible flow is " << fordFulkerson(graph, source, sink) << endl;

    return 0;
}
