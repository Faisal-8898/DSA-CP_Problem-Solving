#include <bits/stdc++.h>
using namespace std;

class Heap
{
public:
    /* data */
    int capacity;
    int size;
    int *arr;

public:
    Heap(int capacity) : capacity(capacity), size(0)
    {
        arr = new int[capacity];
    }
    ~Heap()
    {
        delete[] arr;
    }

    void insertion(int data)
    {
        if (size == capacity)
            return;
        int parent = (size - 1) / 2;
        size++;
        arr[size-1]=data;
        for(int i = size-1; i!=0&& arr[parent] > arr[i];){
            swap(arr[i],arr[parent]);
            i = parent;
            // parent = (i - 1) / 2;
        }
    }

    void printHeap (){
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << ' ';
        }
        
    }
};

int main()
{
    Heap minheap(9);
    minheap.insertion(5);
    minheap.insertion(12);
    minheap.insertion(60);
    minheap.insertion(20);
    minheap.insertion(20);
    minheap.insertion(20);
    minheap.printHeap();

}