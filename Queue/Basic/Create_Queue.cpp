#include <iostream>
using namespace std;

const int SIZE = 20;

int arr[SIZE];
int front = -1;
int rear = -1;

bool isFull() {
    return (rear + 1) % SIZE == front;
}

bool isEmpty() {
    return front == -1 && rear == -1;
}

void enqueue(int data) {
    if (isFull()) {
        cout << "Queue is full. Cannot enqueue more elements." << endl;
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }

    arr[rear] = data;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

char dequeue1() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return '\0'; // Assuming '\0' is not a valid element in the queue
    }

    char data = arr[front];

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }

    return data;
}

void copyQueue() {
    if (isEmpty()) {
        cout << "Queue is empty. No copy operation can be performed." << endl;
        return;
    }

    int i;
    for (i = front; i <= rear; i++) {
        enqueue(arr[i]);
    }
}

void printQueue() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }

    int current = front;
    while (current != rear) {
        cout << arr[current] << " ";
        current = (current + 1) % SIZE;
    }
    cout << arr[current] << endl;
}

string removeSpacesUsingQueue(const string& input) {
    for (char ch : input) {
        if (ch != ' ') {
            enqueue(ch);
        }
    }

    // Dequeue characters and form the new string without spaces
    string result;
    while (!isEmpty()) {
        result.push_back(dequeue1());
    }

    return result;
}

void deleteNeg() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }

    int originalFront = front; // Store the original front index
    int newFront = front; // Initialize newFront to the front of the queue

    while (newFront != rear) {
        // If the element at newFront is negative, skip it and move newFront forward
        if (arr[newFront] < 0) {
            newFront = (newFront + 1) % SIZE;
        } else {
            // If the element is non-negative, copy it to the original front index
            arr[originalFront] = arr[newFront];
            // Move both originalFront and newFront forward
            originalFront = (originalFront + 1) % SIZE;
            newFront = (newFront + 1) % SIZE;
        }
    }

    // Handle the last element (at rear) separately
    if (arr[newFront] >= 0) {
        arr[originalFront] = arr[newFront];
        originalFront = (originalFront + 1) % SIZE;
    }

    // Update front and rear indices after deletion
    front = originalFront;
    if (front == rear) {
        // The queue is empty after deletion
        front = rear = -1;
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    dequeue();

    copyQueue();

    string result = removeSpacesUsingQueue("hfjsldfj sjf lssldkjf lsj fs jkldf fsjldj sdjfls");
    cout << result << endl;

    printQueue();

    return 0;
}
