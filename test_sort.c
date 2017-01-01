#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* insert_sort(int *arr, int size){
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
     return arr;
}

int* bubble_sort(int *arr, int size){
    int i;
    for(i=0; i<size; i++){
        int j, tmp;
        for(j=0; j=size-i-1; j++){
            if(arr[j] > arr[j+1]){
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    return arr;
}

int* select_sort(int *arr, int size){
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
    return arr;
}

int main(int argc, char *argv[]) {
    int *arr;
    char *sort = argv[1];
    char *opt = argv[2];
    int size = atoi(argv[3]);
    int i;
    
    if(argc != 4){
        printf("segmentation error");
        return -1;
    }
    
    arr = (int*)malloc(sizeof(int)*size);
    if(strncmp(opt,"same",4)==0){
        for(i=0;i<size;i++)
          arr[i] = size;
    }
    else if(strncmp(opt,"asc",3)==0){
        for(i=0;i<size;i++)
            arr[i] = i;
    }
    else if(strncmp(opt,"desc",4)==0){
        for(i=0;i<size;i++)
            arr[i] = size-i-1;
    }
    else if(strncmp(opt,"rand",4)==0){
        for(i=0;i<size;i++)
            arr[i] = rand()%size;
    }
    
    else{
        printf("init_option error");
        return -1;
    }
     
    if(strncmp(sort,"ins",3)==0)
        arr = insert_sort(arr,size);
    else if(strncmp(sort,"bub",3)==0)
        arr = bubble_sort(arr,size);
    else if(strncmp(sort,"sel",3)==0)
        arr = select_sort(arr,size);
    else{
         printf("sort_option error");
         return -1;
    }
    
    for(i=0;i<size;i++)
        printf("%d ",arr[i]);

    return 0;
}
