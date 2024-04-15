#include <iostream>
using namespace std;

int main() {
  // Write C++ code here
  long int n, r;
  int count = 0;
  cin >> n;

  while (n > 0) {
    r = n % 10;
    n = n / 10;
    if (r == 7 || r == 4) {
      count++;
    }
  }
  if (count == 4 || count == 7) {
    cout << "YES";
  } else {
    cout << "NO";
  }

  return 0;
}
