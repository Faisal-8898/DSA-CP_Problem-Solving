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

int partition(int arr[], int start, int end) {
  int pivot = arr[start];
  int i = start + 1;
  int j = end;
  while (i <= j) {
    while (i <= end && arr[i] <= pivot) {
      i++;
    }
    while (j > start && arr[j] > pivot) {
      j--;
    }
    if (i < j) {
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[start], arr[j]);
  return j;
}

void quickSort(int arr[], int start, int end) {
  if (start < end) {
    int q = partition(arr, start, end);
    quickSort(arr, start, q - 1);
    quickSort(arr, q + 1, end);
  }
}
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}

// Main function
int main() {
  fastIO();

  int arr[] = {1, 34, 5, -1, 985, 102, -134, 34, -1234};
  int n = sizeof(arr) / sizeof(arr[0]);
  quickSort(arr, 0, n - 1);
  printArray(arr, n);
  return 0;
}
