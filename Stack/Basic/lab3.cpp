#include <iostream>
#include <cstdlib>


int *arr;
int capacity;
int top = -1;

void push(int x) {
  if(top == capacity-1) {
    int *newArr = new int[2*capacity];
    capacity *= 2;

    for(int i=0; i<capacity/2; i++) {
      newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;
  }

  top++;
  arr[top] = x;
}

void pop() {
  if(top == -1) {
    std::cout << "Stack Underflow" << std::endl;
    return;
  }

  top--;
}



int main() {

  std::cout << "Enter initial size: ";
  std::cin >> capacity;

  arr = new int[capacity];

  // Use stack

  delete[] arr;
  return 0;
}