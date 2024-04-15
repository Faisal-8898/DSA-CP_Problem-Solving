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

bool compare(const int &a, const int &b) { return a < b; }

/* int main() { */
/*   fastIO(); */
/*   int n; */
/*   cin >> n; */
/*   int arr[n]; */
/*   for (int i = 0; i < n; i++) { */
/*     cin >> arr[i]; */
/*   } */
/*   sort(arr, arr + n); */
/*   for (int i = 0; i < n; i++) { */
/*     cout << arr[i] << " "; */
/*   } */
/**/
/*   int *ptr = lower_bound(arr + 4, arr + n, 100); */
/*   int *ptr3 = upper_bound(arr + 4, arr + n, 100); */
/**/
/*   cout << endl << *ptr << endl; */
/*   cout << *ptr3 << endl; */
/**/
/*   if (ptr == arr + n) { */
/*     cout << "not found" << endl; */
/*     return 0; */
/*   } */
/*   return 0; */
/* } */

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    vec[i] = x;
  }
  sort(vec.begin(), vec.end());
  for (int i = 0; i < n; i++) {
    cout << vec[i] << " ";
  }
  cout << endl;
  auto it = upper_bound(vec.begin(), vec.end(), 5);
  cout << (*it) << endl;
}
