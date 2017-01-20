#include <stdio.h>
#include <string.h>
#include <time.h>

#include "sort.h"

#define SIZE 3276800

int arr[SIZE];
int arr_c[SIZE];

int main(void) {
    int i;
    int chk;
    
    srand(time(NULL));
    
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand();
        printf("%d\n", arr[i]);
    }

    memcpy(arr_c, arr, sizeof (arr));
    quick_sort(arr, SIZE);
    heap_sort(arr_c, SIZE);
    
    for (i = 0; i < SIZE; i++) {
        printf("%d %d\n", arr[i], arr_c[i]);
    }
    
    chk = memcmp(arr, arr_c, SIZE * sizeof(int));
    
    if (chk == 0) {
        puts("CORRECT");
    } else {
        puts("FAIL");
    }
    puts("TEST END");
}
