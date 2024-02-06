#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// Macros for common operations
#define INF 1e9
#define MOD 1000000007
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define F first
#define S second

// Shortcuts for frequently used code
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define REV(i, a, b) for (int i = a; i >= b; --i)
#define REPR(i, n) REV(i, n - 1, 0)

// Function for fast I/O
void fastIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}

// Custom sort function (optional)
bool compare(const int &a, const int &b) { return a < b; }

int mazePath(int n, int m, int x, int y) {
  int right = 0;
  int down = 0;
  if (x == n && y == m) {
    return 1;
  } else if (x == n) {
    down = mazePath(n, m, x, y + 1);
  } else if (y == m) {
    right = mazePath(n, m, x + 1, y);
  } else if (x < n && y < m) {
    down = mazePath(n, m, x, y + 1);
    right = mazePath(n, m, x + 1, y);
  }
  return right + down;
}

// Main function
int main() {
  fastIO();
  int n, m;
  cin >> n >> m;
  cout << mazePath(n, m, 1, 1);
  return 0;
}
