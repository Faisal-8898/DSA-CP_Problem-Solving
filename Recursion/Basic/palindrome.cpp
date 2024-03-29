#include <iostream>

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

bool isPalindrome(const std::string &str, int start, int end) {
  if (start >= end) {
    return true;
  }

  return (str[start] == str[end]) && isPalindrome(str, start + 1, end - 1);
}

// Main function
int main() {
  int n;
  cin >> n;

  double a = n / 3.0;
  double w = n / 3.0;
  double h = n / 3.0;

  double volume = l * w * h;
  cout << fixed << setprecision(12) << (n / 3.0) * (n / 3.0) * (n / 3.0)
       << endl;

  return 0;
}
