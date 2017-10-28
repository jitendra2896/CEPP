//This Bubble sort algorithm
#include<stdio.h>
#include<conio.h>

void swap(int* p, int*q) {

	int temp = *p;
	*p = *q;
	*q = temp;
}

void bubble_sort(int a[], int n)
{
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n-i-1; j++) {

			if (a[j] > a[j + 1]) 
				swap(&a[j], &a[j + 1]);
		}
	}
}

int main() {
	int i;
	int a[] = { 5,4,3,2,1 };
	bubble_sort(a, 5);
	for (i = 0; i < 5; i++) {
		printf("%d\t", a[i]);
	}
	getch();
	return 0;
}
