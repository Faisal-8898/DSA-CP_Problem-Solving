#include <bits/stdc++.h>

using namespace std;

const int INF = numeric_limits<int>::max();

// Function to implement the Floyd-Warshall algorithm
void floydWarshall(vector<vector<int>> &dist)
{
    int n = dist.size();

    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main()
{
    int n;
    cin >> n; // Number of vertices

    vector<vector<int>> dist(n, vector<int>(n));

    // Reading the adjacency matrix
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            string value;
            cin >> value;
            if (value == "∞")
            {
                dist[i][j] = INF;
            }
            else
            {
                dist[i][j] = stoi(value);
            }
        }
    }

    // Running the Floyd-Warshall algorithm
    floydWarshall(dist);

    // Printing the result
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (dist[i][j] == INF)
            {
                cout << "∞ ";
            }
            else
            {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
