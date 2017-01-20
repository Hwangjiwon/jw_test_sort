void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void min_heap(int *arr, int size, int root){
    int cur;
    if(size - root < 2) return;

    cur = root;
    while(cur >= 0){
       int i = cur;
       int start = cur;
        while(start*2+1 < size){
           int left = start*2+1;
           int right = start*2+2;
            start = left;

            if((right < size) && (arr[right] >= arr[left])){
                start = right;
            }
            if(arr[start] > arr[i]){
                swap(&arr[i],&arr[start]);
                i = start;
            }
        }
        --cur;
    }
}

void heap_sort(int *arr, int size){
    //insert heap
    min_heap(arr, size, size/2-1);
    while(size > 0){
       --size;
       swap(&arr[0],&arr[size]);
       min_heap(arr,size,0);
    }
}

