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

    return parenthesesStack.empty();
}

int main() {
    string expression;
    cout << "Enter an expression with parentheses: ";
    getline(cin, expression);

    bool unmatchedOpening = false;
    stack<int> unmatchedIndices;

    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == '(') {
            unmatchedOpening = true;
            unmatchedIndices.push(i);
        } else if (expression[i] == ')') {
            if (unmatchedOpening) {
                unmatchedOpening = false;
                unmatchedIndices.pop();
            } else {
                cout << "Closing parenthesis not matched" << endl;
                return 0;
            }
        }
    }

    if (unmatchedOpening) {
        int index = unmatchedIndices.top();
        cout << "Opening parentheses not ended at index " << index << endl;
    } else {
        cout << "All parentheses are matched." << endl;
    }

    return 0;
}
