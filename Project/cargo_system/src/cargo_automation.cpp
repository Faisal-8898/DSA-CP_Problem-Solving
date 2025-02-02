#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define MAX_CITIES 15
#define MAX_CITY_NAME 50

// Adjacency matrices for price and weight
int priceGraph[MAX_CITIES][MAX_CITIES];
int weightGraph[MAX_CITIES][MAX_CITIES];
char cities[MAX_CITIES][MAX_CITY_NAME] = {
    "Paris", "London", "Berlin", "Tokyo", "Madrid",
    "Rome", "Sydney", "Cairo", "Moscow", "MexicoCity",
    "Jakarta", "Manila", "Lima", "CapeTown", "Dubai"};

// Structure to store results
typedef struct
{
  int cheapestCost;
  int maxWeightOnCheapestPath;
  int maxWeightCapacity;
  int totalPriceOfMaxWeightPath;
} Results;

// Edge structure for Kruskal's Algorithm
typedef struct
{
  int source, destination, weight;
} Edge;

// Parent array for Union-Find in Kruskal's Algorithm
int parent[MAX_CITIES];

// Function to initialize the graph
void initializeGraph()
{
  for (int i = 0; i < MAX_CITIES; i++)
  {
    for (int j = 0; j < MAX_CITIES; j++)
    {
      priceGraph[i][j] = INT_MAX; // No path initially
      weightGraph[i][j] = 0;      // No capacity initially
    }
  }
}

// Function to get the index of a city
int getCityIndex(const char *city)
{
  for (int i = 0; i < MAX_CITIES; i++)
  {
    if (strcmp(cities[i], city) == 0)
    {
      return i;
    }
  }
  return -1; // City not found
}

// Function to add edge with price and weight
void addEdge(int sourceIndex, int destIndex, int price, int weight)
{
  priceGraph[sourceIndex][destIndex] = price;
  priceGraph[destIndex][sourceIndex] = price;
  weightGraph[sourceIndex][destIndex] = weight;
  weightGraph[destIndex][sourceIndex] = weight;
}

// Function to read the file and load the data
void loadCargoData(const char *filename)
{
  FILE *file = fopen(filename, "r");
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return;
  }

  char source[MAX_CITY_NAME], destination[MAX_CITY_NAME];
  int price, weight;

  while (fscanf(file, "%s %s %d %d", source, destination, &price, &weight) != EOF)
  {
    int sourceIndex = getCityIndex(source);
    int destIndex = getCityIndex(destination);
    if (sourceIndex != -1 && destIndex != -1)
    {
      addEdge(sourceIndex, destIndex, price, weight);
    }
  }

  fclose(file);
}

// Function to print the price graph to a file
void printPriceGraph(FILE *file)
{
  fprintf(file, "Price Graph:\n");
  for (int i = 0; i < MAX_CITIES; i++)
  {
    for (int j = 0; j < MAX_CITIES; j++)
    {
      if (priceGraph[i][j] == INT_MAX)
      {
        fprintf(file, "INF ");
      }
      else
      {
        fprintf(file, "%d ", priceGraph[i][j]);
      }
    }
    fprintf(file, "\n");
  }
}

// Function to print the weight graph to a file
void printWeightGraph(FILE *file)
{
  fprintf(file, "Weight Graph:\n");
  for (int i = 0; i < MAX_CITIES; i++)
  {
    for (int j = 0; j < MAX_CITIES; j++)
    {
      fprintf(file, "%d ", weightGraph[i][j]);
    }
    fprintf(file, "\n");
  }
}

// Dijkstra's algorithm for the cheapest path
Results dijkstraCheapest(int source, int destination, int citiesCount)
{
  Results result;
  int dist[citiesCount], visited[citiesCount], prev[citiesCount];
  for (int i = 0; i < citiesCount; i++)
  {
    dist[i] = INT_MAX;
    visited[i] = 0;
    prev[i] = -1; // To reconstruct the path
  }
  dist[source] = 0;

  for (int i = 0; i < citiesCount - 1; i++)
  {
    int minDist = INT_MAX, minIndex;
    for (int j = 0; j < citiesCount; j++)
    {
      if (!visited[j] && dist[j] < minDist)
      {
        minDist = dist[j];
        minIndex = j;
      }
    }

    visited[minIndex] = 1;

    for (int j = 0; j < citiesCount; j++)
    {
      if (!visited[j] && priceGraph[minIndex][j] != INT_MAX && dist[minIndex] + priceGraph[minIndex][j] < dist[j])
      {
        dist[j] = dist[minIndex] + priceGraph[minIndex][j];
        prev[j] = minIndex; // Track the path
      }
    }
  }

  // Reconstruct the path
  int path[MAX_CITIES], pathIndex = 0;
  for (int v = destination; v != -1; v = prev[v])
  {
    path[pathIndex++] = v;
  }

  // Calculate the maximum weight on the cheapest path
  int maxWeight = INT_MAX;
  for (int i = pathIndex - 1; i > 0; i--)
  {
    int u = path[i], v = path[i - 1];
    if (weightGraph[u][v] < maxWeight)
    {
      maxWeight = weightGraph[u][v];
    }
  }

  result.cheapestCost = dist[destination];
  result.maxWeightOnCheapestPath = maxWeight;
  return result;
}

// Function to find the parent of a node (with path compression)
int find(int i)
{
  if (parent[i] == i)
    return i;
  return parent[i] = find(parent[i]);
}

// Function to perform union of two sets (with union by rank)
void unionSets(int x, int y)
{
  int xroot = find(x);
  int yroot = find(y);
  parent[xroot] = yroot;
}

// Comparator function for sorting edges in descending order of weight
int compareEdges(const void *a, const void *b)
{
  Edge *edgeA = (Edge *)a;
  Edge *edgeB = (Edge *)b;
  return edgeB->weight - edgeA->weight;
}

// Kruskal's Algorithm to find the Maximum Spanning Tree (MST)
void kruskalMaxSpanningTree(Edge edges[], int numEdges, int numCities, int mst[MAX_CITIES][MAX_CITIES])
{
  // Initialize MST
  for (int i = 0; i < numCities; i++)
  {
    for (int j = 0; j < numCities; j++)
    {
      mst[i][j] = 0;
    }
  }

  // Sort all edges in descending order of weight
  qsort(edges, numEdges, sizeof(Edge), compareEdges);

  // Initialize parent array for Union-Find
  for (int i = 0; i < numCities; i++)
  {
    parent[i] = i;
  }

  int edgeCount = 0;
  for (int i = 0; i < numEdges; i++)
  {
    int u = edges[i].source;
    int v = edges[i].destination;

    if (find(u) != find(v))
    {
      unionSets(u, v);
      mst[u][v] = edges[i].weight;
      mst[v][u] = edges[i].weight;
      edgeCount++;
    }

    if (edgeCount == numCities - 1)
    {
      break; // MST is complete
    }
  }
}

// DFS to find the path from source to destination in the MST
int dfsMaxWeightPath(int mst[MAX_CITIES][MAX_CITIES], int source, int destination, int visited[MAX_CITIES], int path[MAX_CITIES], int pathIndex, int *maxWeight, int *totalPrice)
{
  visited[source] = 1;
  path[pathIndex] = source;
  pathIndex++;

  if (source == destination)
  {
    // Calculate the maximum weight and total price in the path
    *maxWeight = INT_MAX;
    *totalPrice = 0;
    for (int i = 0; i < pathIndex - 1; i++)
    {
      if (mst[path[i]][path[i + 1]] < *maxWeight)
      {
        *maxWeight = mst[path[i]][path[i + 1]];
      }
      *totalPrice += priceGraph[path[i]][path[i + 1]];
    }
    return 1; // Path found
  }

  for (int i = 0; i < MAX_CITIES; i++)
  {
    if (mst[source][i] > 0 && !visited[i])
    {
      if (dfsMaxWeightPath(mst, i, destination, visited, path, pathIndex, maxWeight, totalPrice))
      {
        return 1;
      }
    }
  }

  return 0; // Path not found
}

// Function to find the maximum weight path using Kruskal's Algorithm
Results findMaxWeightPathKruskal(int source, int destination, int numCities)
{
  Results result;
  Edge edges[MAX_CITIES * MAX_CITIES];
  int numEdges = 0;

  // Create a list of edges from the weight graph
  for (int i = 0; i < numCities; i++)
  {
    for (int j = i + 1; j < numCities; j++)
    {
      if (weightGraph[i][j] > 0)
      {
        edges[numEdges].source = i;
        edges[numEdges].destination = j;
        edges[numEdges].weight = weightGraph[i][j];
        numEdges++;
      }
    }
  }

  int mst[MAX_CITIES][MAX_CITIES];
  kruskalMaxSpanningTree(edges, numEdges, numCities, mst);

  int visited[MAX_CITIES] = {0};
  int path[MAX_CITIES];
  int pathIndex = 0;
  int maxWeight = 0, totalPrice = 0;

  if (dfsMaxWeightPath(mst, source, destination, visited, path, pathIndex, &maxWeight, &totalPrice))
  {
    result.maxWeightCapacity = maxWeight;
    result.totalPriceOfMaxWeightPath = totalPrice;
  }
  else
  {
    result.maxWeightCapacity = -1; // Indicates no path found
    result.totalPriceOfMaxWeightPath = -1;
  }

  return result;
}

int main()
{
  initializeGraph();

  // Load data from cargo_routes.txt
  loadCargoData("cargo_routes.txt");

  // Open files to save the entire graph
  FILE *cheapestResultsFile = fopen("cheapest_results.txt", "w");
  FILE *maxWeightResultsFile = fopen("max_weight_results.txt", "w");

  if (!cheapestResultsFile || !maxWeightResultsFile)
  {
    printf("Error opening result files.\n");
    return 1;
  }

  // Save the entire price graph to cheapest_results.txt
  printPriceGraph(cheapestResultsFile);

  // Save the entire weight graph to max_weight_results.txt
  printWeightGraph(maxWeightResultsFile);

  // Close the files
  fclose(cheapestResultsFile);
  fclose(maxWeightResultsFile);

  // Test the algorithms with source and destination indices
  int source = getCityIndex("Paris");      // Example: Paris
  int destination = getCityIndex("Tokyo"); // Example: Tokyo

  if (source == -1 || destination == -1)
  {
    printf("Invalid source or destination city.\n");
    return 1;
  }

  // Find the cheapest path and maximum weight on that path
  Results cheapestResult = dijkstraCheapest(source, destination, MAX_CITIES);

  // Find the path with the maximum weight capacity and its total price
  Results maxWeightResult = findMaxWeightPathKruskal(source, destination, MAX_CITIES);

  // Print the results in the main function
  printf("Cheapest path from %s to %s:\n", cities[source], cities[destination]);
  printf("Cheapest cost: %d\n", cheapestResult.cheapestCost);
  printf("Maximum weight on this path: %d\n\n", cheapestResult.maxWeightOnCheapestPath);

  if (maxWeightResult.maxWeightCapacity != -1)
  {
    printf("Path with maximum weight capacity from %s to %s:\n", cities[source], cities[destination]);
    printf("Maximum weight capacity: %d\n", maxWeightResult.maxWeightCapacity);
    printf("Total price of this path: %d\n", maxWeightResult.totalPriceOfMaxWeightPath);
  }
  else
  {
    printf("No path found from %s to %s using Kruskal's Algorithm.\n", cities[source], cities[destination]);
  }

  return 0;
}