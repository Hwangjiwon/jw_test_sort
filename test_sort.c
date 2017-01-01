#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* insert_sort(int *arr){
    int i;
    for(i=1; i<(sizeof(arr)/sizeof(int)); i++){
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

int* bubble_sort(int *arr){
    int i;
    for(i=0; i<(sizeof(arr)/sizeof(int)); i++){
        int j, tmp;
        for(j=0; j=sizeof(arr)/sizeof(int)-i-1; j++){
            if(arr[j] > arr[j+1]){
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    return arr;
}

int* select_sort(int *arr){
    int i,min,tmp=0;
    for(i=0; i<(sizeof(arr)/sizeof(int)-1); i++){
        int j;
        min = arr[i];
        for(j=i; j<(sizeof(arr)/sizeof(int)-1); j++){
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
    int size = atoi(argv[4]);
    int i;
    
    arr = (int*)malloc(sizeof(int)*size);
    printf("size = %d   ",size);
    printf("argv[3]= %s",argv[3]);
    if(strncmp(argv[3],"same",4)){
        printf("qwer");
        for(i=0;i<(sizeof(arr)/sizeof(int));i++)
        {    arr[i] = size;
        
        }
        for(i=0;i<sizeof(arr)/sizeof(int);i++)
            printf("dkdkdk :%d ",arr[i]);
    }
    else if(strncmp(argv[3],"asc",3)){
        for(i=0;i<(sizeof(arr)/sizeof(int));i++)
            arr[i] = i;
    }
    else if(strncmp(argv[3],"desc",4)){
        for(i=0;i<(sizeof(arr)/sizeof(int));i++)
            arr[i] = size-i;
    }
    else if(strncmp(argv[3],"rand",4)){
        for(i=0;i<(sizeof(arr)/sizeof(int));i++)
            arr[i] = rand()%size;
    }
    
    else printf("error");
    printf("hello\n");
    
    if(strncmp(argv[2],"ins",3))
       arr = insert_sort(arr);
    else if(strncmp(argv[2],"bub",3))
       arr = bubble_sort(arr);
    else if(strncmp(argv[2],"sel",3))
       arr = select_sort(arr);
    else printf("error");
    
    printf("bye\n");
    
    for(i=0;i<sizeof(arr)/sizeof(int);i++)
        printf("%d ",arr[i]);

    return 0;
}
