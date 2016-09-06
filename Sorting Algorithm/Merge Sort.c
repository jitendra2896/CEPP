#include<stdio.h>

#define MAX 100

void merge(int a[], int p, int q, int r) 
{
	int n1 = q - p + 1;		//size of left array
	int n2 = r - q;			//size of right array

	int i, lv = 0, rv = 0;

	int la[MAX];	//The left array
	int ra[MAX];	//The right array


	for (i = 0; i < n1; i++)
		la[i] = a[p + i];
	for (i = 0; i < n2; i++)
		ra[i] = a[q + i + 1];


	for (i = p; i <= r; i++) {

		if (lv == n1)	//when all the left array element have been put into a
		{
			a[i] = ra[rv];	//just copy remaining right array elements into a
			rv++;
		}
		else if (rv == n2)	//when all the right array element have been put into a
		{
			a[i] = la[lv];	//just copy remaining right array elements into a
			lv++;
		}
		else if (la[lv] <= ra[rv])
		{
			a[i] = la[lv];
			lv++;
		}
		else
		{
			a[i] = ra[rv];
			rv++;
		}
	}
}

void merge_sort(int a[],int low,int high)
{
	int mid = 0;
	if (low < high)
	{
		mid = (low + high) / 2;
		merge_sort(a, low, mid);
		merge_sort(a, mid + 1, high);
		merge(a, low, mid, high);
	}
}

int main() {
	int i;
	int a[] = { 5,6,8,1,0,3,0 };
	merge_sort(a, 0, 6);

	for (i = 0; i < 7; i++)
		printf("%d\t",a[i]);

	getch();
	return 0;
}