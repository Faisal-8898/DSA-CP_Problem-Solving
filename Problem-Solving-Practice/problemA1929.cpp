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

// Function for fast I/O
void fastIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}

// Custom sort function (optional)
bool compare(const int &a, const int &b) { return a < b; }

// Main function
int main() {
  fastIO();

  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++) {
      cin >> a[i];
    }
    ll max = a[0];
    ll min = a[0];
    for (ll i = 0; i < n; i++) {
      if (a[i] > max) {
        max = a[i];
      }
      if (a[i] < min) {
        min = a[i];
      }
    }
    ll ans = (max - min);
    cout << ans << endl;
  }
  return 0;
}
