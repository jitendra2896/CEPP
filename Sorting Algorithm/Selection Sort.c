#include<stdio.h>

void swap(int* p, int*q) {
	
	int temp = *p;
	*p = *q;
	*q = temp;
}

void selection_sort(int a[], int n) {
	int i, j;
	int smallest_index;
	for (i = 0; i < n; i++) {
		smallest_index = i;
		for (j = i; j < n; j++) {
			if (a[j] < a[smallest_index])
				smallest_index = j;
		}
		swap(&a[i], &a[smallest_index]);
	}
}

int main() {
	int i;
	int a[] = { 2,1,4,3,5 };
	selection_sort(a, 5);

	for (i = 0; i < 5; i++) {
		printf("%d\t", a[i]);
	}
	getch();
	return 0;
}