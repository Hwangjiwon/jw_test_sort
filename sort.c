

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
