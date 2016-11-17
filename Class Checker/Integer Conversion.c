#include"header.h"
int convertToInteger(char c[],int a[]){
    int n = 0;
    int j = 0;
    int hasMinus = 0;
    int i;

    for(i = 0;i<strlen(c);i++){

        if(c[i] == '-'){
            hasMinus = 1;
            i++;
        }
        if(c[i]!=' ' && c[i]!='\n'){
            n = n*10 + (c[i] - 48);
        }
        else{
            if(hasMinus){
                n = n*-1;
                hasMinus = 0;
            }
            a[j++] = n;
            n = 0;
        }
    }
    return j;
}
