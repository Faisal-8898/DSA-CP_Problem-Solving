#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long ans;
        long long x, y;
        cin >> x >> y;
        long long maxx = max(x, y);
        long long corner = (maxx * (maxx - 1)) + 1;
        if (x == y)
        {
            cout << corner << endl;
            continue;
        }
        if (maxx % 2 == 0)
        {
            long long start = corner - maxx;
            if (x > y)
            {
                ans = corner + (x - y);
            }
            else
            {
                ans = start + x;
            }
        }
        else
        {
            long long start = corner + maxx;
            if (x > y)
            {
                ans = corner - (x - y);
            }
            else
            {
                ans = start - x;
            }
        }
        cout << ans << endl;
    }
}