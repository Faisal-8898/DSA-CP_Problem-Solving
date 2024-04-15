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

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define REV(i, a, b) for (int i = a; i >= b; --i)
#define REPR(i, n) REV(i, n - 1, 0)

void fastIO() {
  ios_base::sync_with_stdio(0);

  cin.tie(0);
}

bool compare(const int &a, const int &b) { return a < b; }

int knapsack(vector<ll> &weight, vector<ll> &val, ll n, ll capacity) {
  vector<int> table(capacity + 1, 0);

  for (int i = weight[0]; i <= capacity; i++) {
    table[i] = val[0];
  }

  for (int ind = 1; ind < n; ind++) {
    for (int cap = capacity; cap >= 0; cap--) {
      int notTaken = table[cap];
      int taken = INT_MIN;

      if (weight[ind] <= cap) {
        taken = val[ind] + table[cap - weight[ind]];
      }

      table[cap] = max(notTaken, taken);
    }
  }

  return table[capacity];
}

/* int main() { */
/*   fastIO(); */
/**/
/*   8 */
/*   3 30 */
/*   1 60 */
/*   2 40 */
/*   3 60 */
/*   4 70 */
/*   3 50 */
/*   1 10 */
/*   2 20 */
/*   10 */
/*   n = 8; */
/*   vector<ll> weight = {3, 1, 2, 3, 4, 3, 1, 2}; */
/*   vector<ll> value = {30, 60, 40, 60, 70, 50, 10, 20}; */
/*   ll capacity = 10; */
/**/
/*   ll n; */
/**/
/*   freopen("data.txt", "r", stdin); */
/**/
/*   cin >> n; */
/*   vector<ll> weight(n), value(n); */
/*   REP(i, n) cin >> weight[i] >> value[i]; */
/*   ll capacity; */
/*   cin >> capacity; */
/**/
/*   cout << knapsack(weight, value, n, capacity) << endl; */
/*   return 0; */
/* } */

int main() {
  int n;
  cin >> n;
  int wt[n], p[n];
  for (int i = 0; i < n; i++)
    cin >> wt[i];
  for (int i = 0; i < n; i++)
    cin >> p[i];

  int m;
  cin >> m;

  int K[n + 1][m + 1];

  for (int i = 0; i <= n; i++) {
    for (int w = 0; w <= m; w++) {
      if (i == 0 or w == 0)
        K[i][w] = 0;

      else if (wt[i - 1] <= w) {
        K[i][w] = max(p[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
      }

      else
        K[i][w] = K[i - 1][w];
    }
  }
  int res = K[n][m];
  cout << K[n][m] << endl;

  int w = m;
  cout << "Selected Items: ";
  for (int i = n; i > 0 && res > 0; i--) {
    if (res == K[i - 1][w])
      continue;
    else {
      cout << i << " ";
      res = res - p[i - 1];
      w = w - wt[i - 1];
    }
  }
}
