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

/* #define FOR(i, a, b) for (int i = a; i < b; ++i) */
#define REP(i, n) FOR(i, 0, n)
#define REV(i, a, b) for (int i = a; i >= b; --i)
#define REPR(i, n) REV(i, n - 1, 0)

void fastIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}

bool compare(pair<double, int> a, pair<double, int> b) {
  return a.first > b.second;
}

int main() {
  fastIO();
  int n, w;
  double result = 0.0;
  cin >> n >> w;
  vector<pair<double, int>> val(n);
  for (int i = 0; i < n; i++) {
    double prof;
    double we;
    cin >> prof >> we;
    val[i].first = (double)prof / (double)we;
    val[i].second = we;
  }

  sort(val.begin(), val.end());
  while (n-- && w > 0.0) {
    int i = n;
    double firstI = (double)val[i].first;
    double secondI = val[i].second;
    if (w - secondI >= 0) {
      w = w - secondI;
      result = result + firstI * secondI;
    } else {
      result = result + w * firstI;
      w = 0.0;
    }
  }
  cout << fixed << setprecision(7) << result;
  return 0;
}
