#include <iostream>

const int MAX_SIZE = 100;

int queue[MAX_SIZE];
int frontIndex = -1;
int rearIndex = -1;

bool isEmpty() {
    return frontIndex == -1 && rearIndex == -1;
}

bool isFull() {
    return (rearIndex + 1) % MAX_SIZE == frontIndex;
}

void enqueue(int item) {
    if (isFull()) {
        std::cout << "Queue is full. Cannot enqueue.\n";
        return;
    }

    if (isEmpty()) {
        frontIndex = 0;
        rearIndex = 0;
    } else {
        rearIndex = (rearIndex + 1) % MAX_SIZE;
    }

    queue[rearIndex] = item;
}

void dequeue() {
    if (isEmpty()) {
        std::cout << "Queue is empty. Cannot dequeue.\n";
        return;
    } else if (frontIndex == rearIndex) {
        frontIndex = -1;
        rearIndex = -1;
    } else {
        frontIndex = (frontIndex + 1) % MAX_SIZE;
    }
}

int front() {
    if (isEmpty()) {
        std::cout << "Queue is empty. No front element.\n";
        return -1; // Or throw an exception if desired
    }

    return queue[frontIndex];
}

int rear() {
    if (isEmpty()) {
        std::cout << "Queue is empty. No rear element.\n";
        return -1; // Or throw an exception if desired
    }

    return queue[rearIndex];
}

void printQueue() {
    if (isEmpty()) {
        std::cout << "Queue is empty.\n";
        return;
    }

    int current = frontIndex;
    while (current != rearIndex) {
        std::cout << queue[current] << " ";
        current = (current + 1) % MAX_SIZE;
    }
    std::cout << queue[current] << std::endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    std::cout << "Queue contents: ";
    printQueue();

    dequeue();
    std::cout << "Queue contents after dequeue: ";
    printQueue();

    return 0;
}
