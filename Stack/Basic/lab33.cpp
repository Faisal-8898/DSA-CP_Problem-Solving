#include <iostream>
#include <stack>
using namespace std;

bool checkParentheses(const string& expression) {
    stack<char> parenthesesStack;

    for (char ch : expression) {
        if (ch == '(') {
            parenthesesStack.push(ch);
        } else if (ch == ')') {
            if (parenthesesStack.empty()) {
                return false; // Closing parenthesis without a matching opening parenthesis
            }
            parenthesesStack.pop();
        }
    }

    return parenthesesStack.empty(); // If stack is empty, all parentheses are matched
}

int main() {
    string expression;
    cout << "Enter an expression with parentheses: ";
    getline(cin, expression);

    if (checkParentheses(expression)) {
        cout << "All parentheses are matched." << endl;
    } else {
        cout << "Unmatched parentheses found." << endl;
    }

    return 0;
}
