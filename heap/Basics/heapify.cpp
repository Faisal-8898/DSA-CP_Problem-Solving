 #include<bits/stdc++.h>
 using namespace std;

void minHeapify(int i){
    int left = 2*i+1;
    int right = 2*i+2;
    int smallest = i;
    if(left<size && arr[left]< arr[smallest]){
        smallest = left;
    }

    if(right < size && arr[right] < arr[smallest]){
        smallest = right;
    }

    if(smallest != i){
        swap(arr[smallest], arr[i]);
        minHeapify(smallest);
    }
}

 int main(){

 }