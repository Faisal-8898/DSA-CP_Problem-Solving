#include <iostream>
using namespace std;

int reverseNumber(int num, int reversedNum = 0)
{
    return num == 0 ? reversedNum : reverseNumber(num / 10, reversedNum * 10 + (num % 10));
}

int main()
{
    int number;
    cin >> number;
    int reversedNumber = reverseNumber(number);

    cout << number << (number == reversedNumber ? " is Palindrome!" : " is not a Palindrome!") << endl;

    return 0;
}
