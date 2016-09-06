#include<stdio.h>

void duplicates(int a[], int n) {

	int i;
	for (int i = 0; i < n; i++) {
		a[a[i]] = -a[a[i]];
	}

	for (int i = 0; i < n; i++) {
		
		if (a[i] > 0) {
			printf("YES");
			return;
		}
	}
	printf("NO");
	

}

int main() {

	int a[] = { 1,2,1};
	duplicates(a, 3);
	getch();
}