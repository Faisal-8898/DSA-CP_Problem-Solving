#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Recursive function to find the length of LCS
int lcsLength(const string &X, const string &Y, int i, int j)
{
    if (i == 0 || j == 0)
    {
        return 0;
    }
    if (X[i - 1] == Y[j - 1])
    {
        return 1 + lcsLength(X, Y, i - 1, j - 1);
    }
    else
    {
        return max(lcsLength(X, Y, i - 1, j), lcsLength(X, Y, i, j - 1));
    }
}

// Recursive function to reconstruct the LCS
string lcsString(const string &X, const string &Y, int i, int j)
{
    if (i == 0 || j == 0)
    {
        return "";
    }
    if (X[i - 1] == Y[j - 1])
    {
        return lcsString(X, Y, i - 1, j - 1) + X[i - 1];
    }
    else
    {
        if (lcsLength(X, Y, i - 1, j) > lcsLength(X, Y, i, j - 1))
        {
            return lcsString(X, Y, i - 1, j);
        }
        else
        {
            return lcsString(X, Y, i, j - 1);
        }
    }
}

int main()
{
    string X = "ABCBDAB";
    string Y = "BDCAB";

    int m = X.length();
    int n = Y.length();

    cout << "Length of LCS: " << lcsLength(X, Y, m, n) << endl;
    cout << "LCS: " << lcsString(X, Y, m, n) << endl;

    return 0;
}
