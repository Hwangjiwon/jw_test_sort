#include <stdlib.h>

void merge(int *arr, int start, int mid, int end, int* result) { //Conquer
	int i = start, j=mid+1, k=start, t;
	
	//오름차순 정렬
	while (i <= mid && j <= end) { 
		if (arr[i] <= arr[j]){ //앞의 배열의
			result[k] = arr[i];
			i++; //다음 element로
			} else { //뒤의 배열의
			result[k] = arr[j];
			j++; //다음 element로
			}
		k++; //합병
	}

	//start~mid까지 다 처리 되었고, mid+1~end까지의 element가 남았을 때
	if (i > mid) { //남은 뒤의 배열을 복사
		for (t = j; t <= end; t++, k++)
			result[k] = arr[t];
	} else { //j>end
		for (t = i; t <= mid; t++, k++)
			result[k] = arr[t];
	}

	//arr에 result복사
	for (t = start; t <= end; t++)
		arr[t] = result[t];
}

void merge_sort(int *arr, int start, int end) { // Divide
	int mid = (start + end) / 2;
	int *result;

	result = (int*)malloc(sizeof(int)*end);
	
	if (start < end) {
		merge_sort(arr, start, mid);
		merge_sort(arr, mid+1, end);
		merge(arr, start, mid, end, result);
	}
}
