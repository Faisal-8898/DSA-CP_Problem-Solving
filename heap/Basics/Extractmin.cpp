int extractMin(){
    if(size == 0){
        return __INT16_MAX__;
    }

    if(size == 1){
        size--;
        return arr[0];
    }

    swap(arr[0], arr[size-1]);
    size--;
    minHeapify(0);
    return arr[size];
}