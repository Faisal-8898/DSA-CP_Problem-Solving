#include <bits/stdc++.h>
using namespace std;
int main()
{
    int count = 1;
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        float ans = 0;
        vector<float> sum(n);
        for (int i = 0; i < n * 2; i++)
        {
            string name;
            cin >> name;
            long long x, y;
            cin >> x >> y;
            sum[i] = sqrt(x * x + y * y);
            // cout << sum << endl;
            float diff;
            if (i > 0)
            {
                diff = fabs(sum[i] - sum[i - 1]);
                ans = ans + diff;
            }
        }
        cout << "Case " << count << ": " << setprecision(3) << ans << endl;

        count++;
    }
}