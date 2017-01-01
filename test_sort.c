#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int *arr;
    int size = atoi(argv[4]);
    int i;
    
    arr = (int*)malloc(sizeof(int)*size);
    
    if(strncmp(argv[3],"same",4)){
        for(i=0;i<(sizeof(arr)/sizeof(int));i++)
            arr[i] = size;
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

    return 0;
}
