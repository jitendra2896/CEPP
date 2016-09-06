#include<stdio.h>

int partition(int a[], int low, int high) {

	int i = low;
	int j = high;
	int temp;
	int pivot = a[high];

	while (i < j) {

		while (a[i] < pivot)
			i++;
		
		while (a[j] >= pivot)
			j--;

		if (i < j) {
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	a[high] = a[i];
	a[i] = pivot;
	return i;
}

void quick_sort(int a[], int low, int high) {

	int pivot = 0;

	if (low < high) {

		pivot = partition(a, low, high);

		quick_sort(a, low, pivot - 1);
		quick_sort(a, pivot + 1, high);

	}
}

int main() {
	int i;
	int a[] = { 2,5,1,4,3 };
	quick_sort(a, 0, 4);

	for (i = 0; i < 5; i++)
		printf("%d\t", a[i]);

	getch();
	return 0;
}