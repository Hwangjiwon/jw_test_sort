void swap(int* a, int* b) {
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void siftdown(int* arr, int i, int size) {
	int l, r, c;

	l = i * 2 + 1;
	r = i * 2 + 2;

	if (l >= size)
		return;

	if (l < size && r == size)
		c = l;

	if (l < size && r < size)
		c = arr[l] > arr[r] ? l : r;

	if (arr[i] >= arr[c])
		return;

	swap(arr + i, arr + c);
	siftdown(arr, c, size);
}

void heapify(int *arr, int size) {
	int n;
	for (n = (size - 1) / 2; n >= 0; n--)
		siftdown(arr, n, size);
}

void heap_sort(int *arr, int size) {
	heapify(arr, size);

	while (size > 0) {
		swap(arr, arr + size - 1);
		siftdown(arr, 0, --size);
	}
}