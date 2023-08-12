#include <iostream>

using namespace std;

class Stack {
private:
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack is full." << endl;
            return;
        }

        arr[++top] = value;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }

        return arr[top--];
    }
};

class QueueUsingStacks {
private:
    Stack stack1;
    Stack stack2;

public:
    QueueUsingStacks(int size) : stack1(size), stack2(size) {}

    void enqueue(int value) {
        if (stack1.isFull()) {
            cout << "Queue is full." << endl;
            return;
        }

        while (!stack1.isEmpty()) {
            stack2.push(stack1.pop());
        }

        stack1.push(value);

        while (!stack2.isEmpty()) {
            stack1.push(stack2.pop());
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }

        return stack1.pop();
    }

    bool isEmpty() {
        return stack1.isEmpty();
    }
};

int main() {
    QueueUsingStacks q(5);

    // Enqueue elements
    for (int i = 1; i <= 5; ++i) {
        q.enqueue(i);
    }

    cout << "Dequeued elements: ";
    while (!q.isEmpty()) {
        cout << q.dequeue() << " ";
    }

    cout << endl;

    return 0;
}
