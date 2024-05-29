#include <bits/stdc++.h>

using namespace std;

string lcs(string s1, string s2) {
  int m = s1.length();
  int n = s2.length();
  int lcsMattrix[m + 1][n + 1];

  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 || j == 0) {
        lcsMattrix[i][j] = 0;
      } else if (lcsMattrix[i - 1] == lcsMattrix[j - 1]) {
        lcsMattrix[i][j] = lcsMattrix[i - 1][j - 1] + 1;
      } else {
        lcsMattrix[i][j] = max(lcsMattrix[i - 1][j], lcsMattrix[i][j - 1]);
      }
    }
  }
  string result;
  int i = m, j = n;
  while (i > 0 && j > 0) {
    if (s1[i - 1] == s2[j - 1]) {
      result = s1[i - 1] + result;
      i--;
      j--;
    } else if (lcsMattrix[i - 1][j] > lcsMattrix[i][j - 1]) {
      i--;
    } else {
      j--;
    }
  }
  return result;
}

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  string lcs_string = lcs(s1, s2);
  cout << lcs_string << endl;
}
