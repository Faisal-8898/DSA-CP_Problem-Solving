#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin >> str;
    int maxx = 1;
    for (int i = 0; i < str.length() - 1; i++)
    {
        int count = 1;
        while (str[i] == str[i + 1] && i < str.length())
        {
            count++;
            i++;
        }
        maxx = max(count, maxx);
    }
    cout << maxx;
}