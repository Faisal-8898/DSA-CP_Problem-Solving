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

// macros for common operations
#define inf 1e9
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define f first
#define s second

// shortcuts for frequently used code
#define for(i, a, b) for (int i = a; i < b; ++i)
#define rep(i, n) for (i, 0, n)
#define rev(i, a, b) for (int i = a; i >= b; --i)
#define repr(i, n) rev(i, n - 1, 0)

// function for fast i/o
void fastio() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}

// custom sort function (optional)
bool compare(const int &a, const int &b) { return a < b; }

int binary_search(int arr[], int low, int high, int value) {
  int mid = low + (high - low) / 2;
  if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
    return arr[mid];
  }
  if (mid == high || mid == low) {
    return arr[mid];
  }
  if (arr[mid] < arr[mid + 1]) {
    return binary_search(arr, mid + 1, high, value);
  } else {
    return binary_search(arr, low, mid - 1, value);
  }
}

// main function
int main() {
  int arr[] = {-20, 2, 5, 21, 10, 20, 60, 90, 84};
  int low = 0;
  int high = sizeof(arr) / sizeof(arr[0]);
  int value = 84;
  cout << binary_search(arr, low, high, value);
}
