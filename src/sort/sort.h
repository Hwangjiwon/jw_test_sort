#ifndef SORT_H
#define SORT_H

void q_sort(int *arr, int left, int right);
void quick_sort(int *arr, int size);
void swap(int *a, int *b);
void siftdown(int* arr, int i, int size);
void heapify(int *arr, int size);
void heap_sort(int *arr, int size);
void insert_sort(int *arr, int size);
void bubble_sort(int *arr, int size);
void select_sort(int *arr, int size);
void merge(int *arr, int start, int mid, int end, int* result);
void mergeSort(int *arr, int start, int end);

#endif // SORT_H
