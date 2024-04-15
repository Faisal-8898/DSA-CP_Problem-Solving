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

int main() {
  fastIO();
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> arr(2 * n);
    vector<int> left(n);
    vector<int> right(n);
    unordered_map<int, int> l;
    unordered_map<int, int> r;
    map<int, int> mp1, mp2;
    vector<int> ans1, ans2;

    REP(i, 2 * n) cin >> arr[i];
    for (int i = 0; i < n; i++) {
      mp1[arr[i]]++;
      if (mp1[arr[i]] == 2) {
        ans1.push_back(arr[i]);
        ans1.push_back(arr[i]);
      }
    }
    for (int i = n; i < 2 * n; i++) {
      mp2[arr[i]]++;
      if (mp2[arr[i]] == 2) {
        ans2.push_back(arr[i]);
        ans2.push_back(arr[i]);
      }
    }
    int s = ans1.size();
    int s2 = ans2.size();
    if (s >= 2 * k || s2 >= 2 * k) {
      while (s > 2 * k) {
        ans1.pop_back();
        s--;
      }
      while (s2 > 2 * k) {
        ans2.pop_back();
        s2--;
      }
    } else {
      for (auto element : mp1) {

        if (s == 2 * k) {
          break;
        }
        if (element.second == 1 && mp2[element.first] == 1) {
          ans1.push_back(element.first);
          ans2.push_back(element.first);
          s++;
        }
      }
    }

    for (auto ele : ans1) {
      cout << ele << " ";
    }
    cout << "\n";
    for (auto ele : ans2) {
      cout << ele << " ";
    }
    cout << "\n";
  }

  return 0;
}

/* int main() { */
/*   fastIO(); */
/*   int t; */
/*   cin >> t; */
/*   while (t--) { */
/*     int n, k; */
/*     cin >> n >> k; */
/*     vector<int> arr(2 * n); */
/*     unordered_map<int, int> count_left, count_right; */
/*     vector<int> ans_left, ans_right; */
/**/
/*     for (int i = 0; i < 2 * n; ++i) { */
/*       cin >> arr[i]; */
/*       if (i < n) */
/*         count_left[arr[i]]++; */
/*       else */
/*         count_right[arr[i]]++; */
/*     } */
/**/
/*     for (int i = 0; i < 2 * n && ans_left.size() < 2 * k; ++i) { */
/*       if (count_left[arr[i]] == 2 && count_right[arr[i]] == 0) { */
/*         ans_left.push_back(arr[i]); */
/*         ans_right.push_back(arr[i]); */
/*       } else if (count_left[arr[i]] == 1 && count_right[arr[i]] == 1) { */
/*         ans_left.push_back(arr[i]); */
/*         ans_right.push_back(arr[i]); */
/*       } */
/*     } */
/**/
/*     for (int i = 0; i < 2 * k; ++i) { */
/*       cout << ans_left[i] << " "; */
/*     } */
/*     cout << "\n"; */
/*     for (int i = 0; i < 2 * k; ++i) { */
/*       cout << ans_right[i] << " "; */
/*     } */
/*     cout << "\n"; */
/*   } */
/*   return 0; */
/* } */
