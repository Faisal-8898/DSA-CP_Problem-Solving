#include <bits/stdc++.h>

using namespace std;

void matrixChainOrder(int arr[], int n) {
  int cost[n][n];
  int paren[n][n];

  for (int i = 0; i < n; i++)
    cost[i][i] = 0;

  for (int len = 2; len < n; len++) {
    for (int i = 0; i < n - len + 1; i++) {
      int j = i + len - 1;
      cost[i][j] = INT_MAX;
      for (int k = i; k < j; k++) {
        int tempCost =
            cost[i][k] + cost[k + 1][j] + arr[i] * arr[k + 1] * arr[j + 1];
        if (tempCost < cost[i][j]) {
          cost[i][j] = tempCost;
          paren[i][j] = k;
        }
      }
    }
  }

  cout << cost[0][n - 1] << endl;
}

int main() {
  int arr[] = {40, 25, 20, 10, 5, 15, 25};
  int n = sizeof(arr) / sizeof(arr[0]);
  matrixChainOrder(arr, n);
  return 0;
}
