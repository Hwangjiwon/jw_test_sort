void q_sort(int *arr, int left, int right){
    int pi,l,r;
    l = left;
    r = right;
    pi = arr[left]; //arr[0]이 피봇
    
    while(left < right){
        while((arr[right] >= pi) && (left < right))
            right--;
        if(left != right)
            arr[left] = arr[right];
        
        while((arr[left] <= pi) && (left < right))
            left++;
        if(left != right){
            arr[right] = arr[left];
            right--;
        }
    }
    
    arr[left] = pi;
    pi = left;
    left = l;
    right = r;
    
    if(left < pi)
        q_sort(arr,left,pi-1);
    if(right > pi)
        q_sort(arr,pi+1,right);
}

void quick_sort(int *arr, int size){
    q_sort(arr,0,size-1);
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void min_heap(int *arr, int size, int root){
    int left, right, cur, start, i;
    if(size - root < 2) return;

    cur = root;
    while(cur >= 0){
        i = cur;
        start = cur;
        while(start*2+1 < size){
            left = start*2+1;
            right = start*2+2;
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

void insert_sort(int *arr, int size){
    int i;
    for(i=1; i<size; i++){
        int tmp = arr[i];
        int j;
        for(j=i-1; j>=0; j--){
            if(arr[j]<tmp) break;
            else arr[j+1] = arr[j];
        }
        arr[j+1] = tmp;
     }
}

void bubble_sort(int *arr, int size){
    int i;
    for(i=0; i<size; i++){
        int j, tmp;
        for(j=0; j<size-1-i; j++){
            if(arr[j] > arr[j+1]){
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

void select_sort(int *arr, int size){
    int i,min,tmp=0;
    for(i=0; i<size-1; i++){
        int j;
        min = arr[i];
        for(j=i; j<size-1; j++){
            if(min > arr[j+1]){
                min = arr[j+1];
                tmp = j+1;
            }
        }
        arr[tmp] = arr[i];
        arr[i] = min;
    }
}

