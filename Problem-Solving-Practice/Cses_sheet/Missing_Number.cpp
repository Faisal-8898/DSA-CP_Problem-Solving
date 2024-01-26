#include <bits/stdc++.h>
using namespace std;
int main() {
  int he;
  long long n;
  cin >> n;
  vector<long long> vec;
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    vec.push_back(x);
  }
  sort(vec.begin(), vec.end());
  for (int i = 0; i <= n - 1; i++) {
    if (i + 1 != vec[i]) {
      cout << i + 1;
      break;
    }
  }
}
