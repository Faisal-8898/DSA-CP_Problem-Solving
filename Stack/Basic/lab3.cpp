#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
int arr[MAX_SIZE];
int top = -1;

bool isEmpty() {
    return (top == -1);
}

bool isFull() {
    return (top == MAX_SIZE - 1);
}

void push(int data) {
    if (isFull()) {
        cout << "Stack overflow. Cannot push more elements." << endl;
        return;
    }

    top++;
    arr[top] = data;
}

int pop() {
    if (isEmpty()) {
        cout << "Stack underflow. Cannot pop from an empty stack." << endl;
        return -1;
    }

    int data = arr[top];
    top--;
    return data;
}

void printStack() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return;
    }

    cout << "Current stack: ";
    for (int i = top; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

string decimalToBinary(int decimalNumber) {
    if (decimalNumber == 0) {
        return "0";
    }

    string binaryNumber = "";
    while (decimalNumber > 0) {
        int remainder = decimalNumber % 2;
        binaryNumber = to_string(remainder) + binaryNumber;
        decimalNumber /= 2;
    }

    return binaryNumber;
}

bool checkParentheses(const string& expression) {
    
    for (char ch : expression) {
        if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            if (isEmpty()) {
                return false; // Closing parenthesis without a matching opening parenthesis
            }
            pop();
        }
    }

    return isEmpty(); // If stack is empty, all parentheses are matched
}

int main() {
    int choice, data;
    string expression; // Move the declaration here

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert data (Push to stack)\n";
        cout << "2. Print stack\n";
        cout << "3. Pop stack\n";
        cout << "4. Convert decimal number to binary\n";
        cout << "5. Check for unmatched parentheses\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to push into the stack: ";
                cin >> data;
                push(data);
                break;
            case 2:
                printStack();
                break;
            case 3:
                data = pop();
                if (data != -1) {
                    cout << "Data " << data << " popped from the stack." << endl;
                }
                break;
            case 4:
                cout << "Enter a decimal number to convert to binary: ";
                int decimalNumber;
                cin >> decimalNumber;
                cout << "Binary representation: " << decimalToBinary(decimalNumber) << endl;
                break;
            case 5:
                cin.ignore();
                cout << "Enter an expression with parentheses: ";
                getline(cin, expression);
                if (checkParentheses(expression)) {
                    cout << "All parentheses are matched." << endl;
                } else {
                    cout << "Unmatched parentheses found." << endl;
                }
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
