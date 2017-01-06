#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "test_sort.h"

char *value[3] = {NULL};
int input_check(int argc, char** argv);
void init_option(int *arr, int size, char *opt);
void insert_sort(int *arr, int size);
void bubble_sort(int *arr, int size);
void select_sort(int *arr, int size);
void sort_option(int *arr, int size, char *sort);
void print_t(long clock);

int main(int argc, char *argv[]) {
    int *arr;
    char *sort;
    char *opt;
    int size;
    int i;

    clock_t t;
    
    t=clock();
/*
    if(argc < 4){
        printf("segmentation error\n");
        return -1;
    }
*/
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

int input_check(int argc, char** argv)
{
	int i,j,k;

	if(argc == 1)
	{	
	    printf("실행예시: ./test_sort -a bub -o asc -s 1004\n");
		return -1;
	}
	else if (argc % 2 == 0 || 0 == strncmp(argv[argc-1],"-",1)) //argc가 홀수 이거나 argv[마지막]이 옵션일때 error
	{
		printf("ERROR: INPUT THE VALUE\n");
		return -1;
	}
	else
	{
		for (i = 1; i < argc; i++) {
			k = i%2; //k==1 홀수   k==0 짝수
			j = (i+1)%2;
			if (k == 1 && 0 == strncmp(argv[i], "-", 1)) //argv[홀]이 옵션인가
			{ 				
				if (j == 0 && 0 != strncmp(argv[i+1], "-", 1)) //argv[짝]이 값인가
				{
					
//					printf("[%s][%s]\n",argv[i],argv[i+1]);
					
					if(0==strcmp(argv[i],"-a"))
						value[0] = argv[i+1];
					if(0==strcmp(argv[i],"-o"))
						value[1] = argv[i+1];
					if(0==strcmp(argv[i],"-s"))
						value[2] = argv[i+1];

				}
				else printf("input error\n");
			}
		}
		if (value[0] == NULL) {
			printf("실행예시: ./test_sort -a bub -o asc -s 1004\n");
			return -1;
		}
		else {
			if (value[1] == NULL) {
				value[1] = "random";
			}
			if (value[2] == NULL) {
				value[2] = "32768";
			}
		}
/*		
		printf("\n#########\n");
		for (i = 0; i < 3; i++) {
			printf("value[%d]=%s\n",i,value[i]);
		}
*/		
	}
	return 0;
}

