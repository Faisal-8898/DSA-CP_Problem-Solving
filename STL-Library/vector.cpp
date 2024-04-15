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

// Main function
int main() {
  fastIO();
  vector<int> moja;
  vector<long long> longMoja;
  moja.push_back(23);
  moja.push_back(123);
  moja.push_back(54);
  /* moja.insert(moja.begin() + 5, 992); */
  size_t size = moja.size();

  /* cout << size << " "; */
  /* cout << moja[5] << " "; */
  // Print the first element
  /* cout << moja.front() << " "; */
  /* cout << moja.back(); */

  // erase individual element
  /* moja.erase(moja.begin()); */

  // see the vector is empty or not
  if (moja.empty()) {
    cout << "Pura khali bhai";
  }

  // sort vector
  /* sort(moja.begin(), moja.end()); */
  sort(moja.begin(), moja.end(), greater<int>());
  sort(moja.begin(), moja.end(), greater<int>());
  /* auto ashami = find(moja.begin(), moja.end(), 42); */
  for (const int value : moja) {
    cout << value << " ";
  }

  return 0;
}
