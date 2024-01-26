#include <iostream>
using namespace std;
int main()
{
    long long xMate, yMate, hallcount, xHall, yHall;
    cin >> xMate >> yMate >> hallcount >> xHall >> yHall;
    long long ans1 = (xHall / xMate) * (yHall / yMate);
    long long ans2 = (xHall / yMate) * (yHall / xMate);
    if (ans1 >= ans2)
        cout << ans1;
    else
        cout << ans2;
}
