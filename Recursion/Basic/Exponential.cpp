#include <bits/stdc++.h>
using namespace std;
double powerh(double base , int power){
if (power == 0){
    return 1;
}
else if (power>0){
    return base * powerh(base , power-1);
}
else {
    return 1.0 / powerh(base , -power);
}

}
int main(){
    int base , power;
    cin >> base >> power;
    cout << powerh(base , power);
}