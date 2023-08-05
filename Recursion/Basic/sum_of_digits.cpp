#include <bits/stdc++.h>
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

// Shortcuts for frequently used code
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define REV(i, a, b) for (int i = a; i >= b; --i)
#define REPR(i, n) REV(i, n - 1, 0)

// Function for fast I/O
void fastIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

// Custom sort function (optional)
bool compare(const int& a, const int& b) {
    return a < b;
}

int sumDigit(int n){
 if(n==0){
    return n;
 }
 else return n%10+sumDigit(n/10);
}

// Main function
int main() {
    fastIO();

    int n;
    cin >> n;
    cout << sumDigit(n);

    return 0;
}
