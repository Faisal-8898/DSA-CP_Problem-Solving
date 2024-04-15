#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, r;
    cin >> n >> r;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    if (r > 1) {
      cout << "YES" << endl;
    } else if (is_sorted(begin(arr), end(arr))) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
