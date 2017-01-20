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
