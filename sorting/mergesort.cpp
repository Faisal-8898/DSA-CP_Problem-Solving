#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
#define SIZE 5000
int ddata[SIZE];

// Shortcuts for frequently used code
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

void RandomDataWrite(const char *FileName) {
  FILE *fp;
  time_t t;
  int i;
  fp = fopen(FileName, "w");
  srand((unsigned)time(&t));

  for (i = 0; i < SIZE; i++) {
    fprintf(fp, "%d\n", rand() % INT_MAX);
  }
  fclose(fp);
}

void ReadFromFile(const char *FileName) {
  FILE *fp;
  int i;
  fp = fopen(FileName, "r");
  for (i = 0; i < SIZE; i++) {
    fscanf(fp, "%d", &ddata[i]);
  }
  fclose(fp);
}

void WriteToConsole() {
  for (int i = 0; i < SIZE; i++) {
    cout << setw(10) << ddata[i];
  }
}

void merge(int arr[], int start, int mid, int end) {
  int length1 = mid - start + 1;
  int length2 = end - mid;
  int L[length1], R[length2];
  for (int i = 0; i < length1; i++) {
    L[i] = arr[start + i];
  }
  for (int i = 0; i < length2; i++) {
    R[i] = arr[mid + 1 + i];
  }
  int i = 0, j = 0, k = start;
  while (i < length1 && j < length2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < length1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < length2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int start, int end) {
  if (start >= end) {
    return;
  }
  int mid = start + (end - start) / 2;
  int mid1 = (start + end) / 2;
  mergeSort(arr, start, mid);
  mergeSort(arr, mid + 1, end);
  merge(arr, start, mid, end);
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

// Main function
int main() {
  fastIO();
  int arr[] = {1, 23, 4, 565, -123};
  int n = end(arr) - begin(arr);
  int n1 = sizeof(ddata) / sizeof(ddata[0]);
  mergeSort(arr, 0, n - 1);
  printArray(arr, n);
  clock_t start, end;
  int i;

  /* RandomDataWrite("RandomIntegers.txt"); */
  /* ReadFromFile("RandomIntegers.txt"); */
  /* WriteToConsole(); */
  /* start = clock(); */
  /* mergeSort(ddata, 0, SIZE); */
  /* end = clock(); */
  /* printArray(ddata, SIZE); */

  /* double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // in seconds
   */
  /* printf("\n\nMerge sort took %.10lf seconds to execute \n", time_taken); */

  return 0;
}
