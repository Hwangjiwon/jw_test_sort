#include <stdlib.h>

void merge(int *arr, int start, int mid, int end, int* result) { //Conquer
	int i = start, j=mid+1, k=start, t;
	
	//�������� ����
	while (i <= mid && j <= end) { 
		if (arr[i] <= arr[j]){ //���� �迭��
			result[k] = arr[i];
			i++; //���� element��
			} else { //���� �迭��
			result[k] = arr[j];
			j++; //���� element��
			}
		k++; //�պ�
	}

	//start~mid���� �� ó�� �Ǿ���, mid+1~end������ element�� ������ ��
	if (i > mid) { //���� ���� �迭�� ����
		for (t = j; t <= end; t++, k++)
			result[k] = arr[t];
	} else { //j>end
		for (t = i; t <= mid; t++, k++)
			result[k] = arr[t];
	}

	//arr�� result����
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
