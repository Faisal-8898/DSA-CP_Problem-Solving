#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    vector<long long> number(n);
    long long maxx = 0;
    for (long long i = 0; i < n; i++)
    {
        cin >> number[i];
    }
    for (long long i = 0; i < n - 1; i++)
    {
        if (number[i] > number[i + 1])
        {
            long long ans = 0;
            ans = number[i] - number[i + 1];
            number[i + 1] = number[i + 1] + ans;
            maxx = maxx + ans;
        }
    }
    cout << maxx;
}
