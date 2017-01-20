
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "main.h"
#include "sort/sort.h"
#include "helper.h"

char *value[3] = {NULL};

int main(int argc, char *argv[]) {
    int num;
    extern char *optarg;
    extern int optind;
    
    int *arr = NULL;
    char *sort = NULL;
    char *opt = "rand";
    int size = 32768;

    clock_t t;
    
    t=clock();

    while((num = getopt(argc,argv,"a:o:s:")) != -1){
     switch(num) {
        case 'a':
            sort = optarg;
            break;
            
        case 'o':
            opt = optarg;
            break;
            
        case 's':
            size = atoi(optarg);
            break;
            
        case '?':
            printf("ERROR: Check the options\n");
            return;
     }
    }
   
    arr = (int*)malloc(sizeof(int)*size);

    init_option(arr,size,opt);

    sort_option(arr,size,sort);

    t = clock()-t;
    t = t/T;
    printf("%s : %ld ms\n",sort,t);
    
    printf("sort: %s  opt: %s   size: %d \n",sort, opt, size);

    return 0;
}
