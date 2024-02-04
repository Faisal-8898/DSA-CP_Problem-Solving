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
#define f first
#define s second

// shortcuts for frequently used code
/* #define for(i, a, b) for (int i = a; i < b; ++i) */
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

void selectionSort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    int min = i;
    for (int j = i; j < n; j++) {
      if (arr[min] > arr[j]) {
        min = j;
      }
    }
    int temp;
    temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
  }
}

void bubbleSort(int arr[], int n) {
  int flag;
  for (int i = 0; i < n && flag; i++) {
    flag = 0;
    for (int j = 0; j < n - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        flag = 1;
      }
    }
  }
}

void insertionSort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    int victim = arr[i];
    int j = i;
    while (arr[j - 1] > victim && j >= 1) {
      arr[j] = arr[j - 1];
      j--;
    }
    arr[j] = victim;
  }
}

void mergeSort(int arr[], int temp[], int left, int right) {
  int mid;
  if (left < right) {
    mid = (right + left) / 2;
    mergeSort(arr, temp, left, mid);
    mergeSort(arr, temp, mid + 1, right);
  }
}

void Merge(int arr[], int temp[], int left, int mid, int right) {}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

// Main function
int main() {
  fastio();

  int arr[] = {30, 1, 12, 3, 67, 67, 40, 90};
  int n = sizeof(arr) / sizeof(arr[0]);
  printArray(arr, n);
  /* selectionSort(arr, n); */
  /* bubbleSort(arr, n); */
  /* insertionSort(arr, n); */
  printArray(arr, n);
  return 0;
}
