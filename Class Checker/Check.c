#include"header.h"
void check(int a[], int size, int p){
    int c = 0;
    int j;
        for(j=0;j<size;j++)
        {
            if(a[j]<=0)
                c++;
        }

        if(c>=p)
            printf("ON\n");
        else
            printf("OFF\n");
}
