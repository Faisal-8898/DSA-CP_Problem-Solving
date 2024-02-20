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
#define pii pair<float, float>
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

bool compareTheYAxisElement(pair<float, float> a, pair<float, float> b) {
  return a.second < b.second;
}

float distanceBetweenThreePoints(pair<float, float> a, pair<float, float> b,
                                 pair<float, float> c) {
  return min(
      sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2)),
      min(sqrt(pow(b.first - c.first, 2) + pow(b.second - c.second, 2)),
          sqrt(pow(a.first - c.first, 2) + pow(a.second - c.second, 2))));
}

float distanceBetweenTwoPoints(pair<float, float> a, pair<float, float> b) {
  return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

float minimumDistanceBetweenTwoOrigin(vector<pair<float, float>> points,
                                      int start, int mid, int end, float d) {
  vector<pair<float, float>> gapElements;
  for (int i = start; i <= end; i++) {
    if (abs(points[i].first - points[mid].first) < d) {
      gapElements.push_back(points[i]);
    }
  }
  sort(gapElements.begin(), gapElements.end(), compareTheYAxisElement);
  int n = gapElements.size();
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (gapElements[j].second - gapElements[i].second > d) {
        break;
      }
      d = min(d, distanceBetweenTwoPoints(gapElements[i], gapElements[j]));
    }
  }
  return d;
}

float minDistance(vector<pair<float, float>> points, int start, int end) {
  if (end - start == 2) {
    return distanceBetweenThreePoints(points[start], points[start + 1],
                                      points[start + 2]);
  }
  if (end - start == 1) {
    return distanceBetweenTwoPoints(points[start], points[end]);
  } else {
    int mid = (start + end) / 2;
    float left = minDistance(points, start, mid);
    float right = minDistance(points, mid + 1, end);
    float d = min(left, right);
    float result = minimumDistanceBetweenTwoOrigin(points, start, mid, end, d);
    return result;
  }
}

int main() {
  fastIO();
  vector<pair<float, float>> points = {{40, 2},  {5, 4},  {-4, 4}, {6, 4},
                                       {-12, 8}, {9, 11}, {11, 12}};

  int n = points.size();
  sort(points.begin(), points.end());
  cout << minDistance(points, 0, n - 1) << endl;

  for (int i = 0; i < n; i++) {
    cout << points[i].first << " " << points[i].second << endl;
  }
  return 0;
}
