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

int lower_bound(vector<int> vec, int ele) {
  int low = 0, high = vec.size();
  while (low < high) {
    int mid = low + (high - low) / 2;
    if (vec[mid] < ele) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  if (vec[low] >= ele) {
    return low;
  }
  /* if (vec[high] >= ele) { */
  /*   return high; */
  /* } */
  return -1;
}

int upper_bound(vector<int> vec, int ele) {
  int low = 0, high = vec.size();
  while (low < high) {
    int mid = low + (high - low) / 2;
    if (vec[mid] <= ele) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  if (vec[low] > ele) {
    return low;
  }
  if (vec[high] > ele) {
    return high;
  }
  return -1;
}

int main() {
  fastIO();
  int n;
  cin >> n;
  vector<int> vec(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    vec[i] = x;
  }
  int element;
  cin >> element;
  int lb = lower_bound(vec, element);
  int up = upper_bound(vec, element);
  cout << vec[up] << " " << up << endl;
  cout << vec[lb] << " " << lb;
  return 0;
}
