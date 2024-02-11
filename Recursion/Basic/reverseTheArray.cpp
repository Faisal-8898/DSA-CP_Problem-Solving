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

void swapWithN(int arr[], int i, int n) {
  if (i >= n / 2) {
    return;
  }
  swap(arr[i], arr[n - i - 1]);
  return swapWithN(arr, i + 1, n);
}

void reverseA(int arr[], int start, int end) {
  if (start >= end) {
    return;
  }
  swap(arr[start], arr[end]);
  return reverseA(arr, start + 1, end - 1);
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}

// Main function
int main() {
  fastIO();
  int arr[] = {1, 2, 3, 4, 5};
  swapWithN(arr, 0, 5);
  printArray(arr, 5);

  return 0;
}
