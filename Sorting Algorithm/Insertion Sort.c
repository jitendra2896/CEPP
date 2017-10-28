//This is Insertion sort algorithm
#include<stdio.h>
#include<conio.h>

void insertion_sort(int a[],int n)
{

	int i, j, k;

	for (i = 1; i < n; i++)
	{
		k = a[i];
		j = i - 1;

		while (j >= 0 && a[j]>k)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = k;
	}
}

int main()
{
	int i;
	int a[] = { 3,1,2,6,5 };
	insertion_sort(a, 5);
	for (i = 0; i < 5; i++) {
		printf("%d\t", a[i]);
	}
	getch();
	return 0;
}
