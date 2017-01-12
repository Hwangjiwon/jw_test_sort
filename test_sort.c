
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "test_sort.h"
#include "sort.h"
#include "helper.h"

char *value[3] = {NULL};

int main(int argc, char *argv[]) {
    int *arr;
    char *sort;
    char *opt;
    int size;
    int i;

    clock_t t;
    
    t=clock();

     if( -1 ==  input_check(argc,argv)){
         return -1;
     }
    sort = value[0];
    opt = value[1];
    size = atoi(value[2]);

    arr = (int*)malloc(sizeof(int)*size);

    init_option(arr,size,opt);

    sort_option(arr,size,sort);

    t = clock()-t;
    t = t/T;
    printf("%s : %ld ms\n",sort,t);

    return 0;
}
