#include <bits/stdc++.h>
#define SIZE 10
using namespace std;

class Queue
{
private:
    int arr[SIZE], front, rear;

public:
    Queue() : front(-1), rear(-1){};

    // bool isFull()
    // {
    //     if (front == 0 && rear == SIZE - 1)
    //     {
    //         return false;
    //     }
    //     return true;
    // }

    //  ANOTHER WAY TO HAVE THIS FUCNTION
    bool isFull()
    {
        return (rear + 1) % SIZE == front;
    }

    bool isEmpty()
    {
        return front == -1 && rear == -1;
    }

    void enqueue(int data)
    {
        if (isFull())
        {
            cout << "queue is full ";
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % SIZE;
        }

        arr[rear] = data;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
    }

    void copyQueue(Queue &myQueue1, Queue &myQueue2)
    {
        if (myQueue1.isEmpty())
        {
            cout << "queue is empty , no copy operation can be happen";
            return;
        }
        else
        {
            int i;
            for (i = myQueue1.front; i <= myQueue1.rear; i++)
            {
                myQueue2.enqueue(myQueue1.arr[i]);
            }
        }
    }

    void printQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        int current = front;
        while (current != rear)
        {
            cout << arr[current] << " ";
            current = (current + 1) % SIZE;
        }
        cout << arr[current] << endl;
    }
};

int main()
{
    Queue myQueue1, myQueue2;
    myQueue1.enqueue(1);
    myQueue1.enqueue(2);
    myQueue1.enqueue(3);

    myQueue1.copyQueue(myQueue1,myQueue2);

    myQueue2.printQueue();

    myQueue1.printQueue();
}