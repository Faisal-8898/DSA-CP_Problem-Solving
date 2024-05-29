#include <bits/stdc++.h>
using namespace std;

int n, m, grid[10][10], visited[10][10], minDifficulty = 11;

void climbRock(int i, int j, int maxClimbTillNow) {
  if (i >= n || i < 0 || j >= m || j < 0 || visited[i][j] != 0 || grid[i][j] == 0)
    return;
  
  if (grid[i][j] == 3) {
    if (maxClimbTillNow < minDifficulty)
      minDifficulty = maxClimbTillNow;
    return;
  }
  
  visited[i][j] = 1;

  int up = i + 1, down = i - 1, t1 = 0;

  while (up < n && (grid[up][j] == 0 || visited[up][j] != 0))
    up++;
  if (up < n && (grid[up][j] == 1 || grid[up][j] == 3)) {
    t1 = up - i;
    if (maxClimbTillNow > t1)
      t1 = maxClimbTillNow;
    climbRock(up, j, t1);
  }

  while (down >= 0 && (grid[down][j] == 0 || visited[down][j] != 0))
    down--;
  if (down >= 0 && (grid[down][j] == 1 || grid[down][j] == 3)) {
    t1 = i - down;
    if (maxClimbTillNow > t1)
      t1 = maxClimbTillNow;
    climbRock(down, j, t1);
  }

  if (j + 1 < m && (grid[i][j + 1] == 1 || grid[i][j + 1] == 3) && visited[i][j + 1] == 0)
    climbRock(i, j + 1, maxClimbTillNow);

  if (j - 1 >= 0 && (grid[i][j - 1] == 1 || grid[i][j - 1] == 3) && visited[i][j - 1] == 0)
    climbRock(i, j - 1, maxClimbTillNow);

  visited[i][j] = 0;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cin >> grid[i][j];
  }
  climbRock(n - 1, 0, 0);
  cout << minDifficulty << endl;
  return 0;
}

