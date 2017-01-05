#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void init_option(int *arr, int size, char *opt);
void insert_sort(int *arr, int size);
void bubble_sort(int *arr, int size);
void select_sort(int *arr, int size);
void sort_option(int *arr, int size, char *sort);


int main(int argc, char *argv[]) {
    int *arr;
    char *sort;
    char *opt;
    int size;
    int i;

    clock_t t;

    t=clock();

    if(argc != 4){
        printf("segmentation error\n");
        return -1;
    }
    
    sort = argv[1];
    opt = argv[2];
    size = atoi(argv[3]);


    arr = (int*)malloc(sizeof(int)*size);

    init_option(arr,size,opt);

    sort_option(arr,size,sort);

    t = clock()-t;
    printf("%s : %ld ms\n",sort,t);

    return 0;
}


void init_option(int *arr, int size, char* opt){
    int i;
 
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
        printf("init_option error\n");
        return;
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

void sort_option(int *arr, int size, char* sort){

    if(strncmp(sort,"ins",3)==0)
        insert_sort(arr,size);
    else if(strncmp(sort,"bub",3)==0)
        bubble_sort(arr,size);
    else if(strncmp(sort,"sel",3)==0)
        select_sort(arr,size);
    else{
         printf("sort_option error\n");
         return;
    }
}
