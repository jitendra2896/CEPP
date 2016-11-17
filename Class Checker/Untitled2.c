#include"header.h"
#include"Check.c"
#include"Count Lines.c"
#include"Integer Conversion.c"
#include"is legal.c"
int main(){

    FILE* fp = fopen("input.txt","r");
    if(fp == NULL){
        printf("File doesn't exist");
        exit(1);
    }
    int a = count_lines(fp);
    fclose(fp);
    fp = fopen("input.txt","r");
    int i,no_of_test_cases[1];
    int n;
    char c[max];
    char d[max];
    int size;
    int c1[max];
    int d1[max];
    fgets(c,max,fp);
    if(!isLegal(c)){
        printf("Test case is not an integer\n");
        exit(1);
    }
    else{
        convertToInteger(c,no_of_test_cases);
        n = no_of_test_cases[0];
        if(n<0){
            printf("Test case should be positive integer\n");
            exit(1);
        }
        if(a - 1 < 2*n){
            printf("Not all test cases are present\n");
            exit(1);
        }
        else if(a - 1 > 2*n){
            printf("Extra test cases are present than specified\n");
            exit(1);
        }

        for(i = 0;i<n;i++){
            fgets(c,max,fp);
            fgets(d,max,fp);

            if(isLegal(c) && isLegal(d)){
                convertToInteger(c, c1);
                if(c1[0]<c1[1]){
                    printf("Present student are more than Total number of students\n");
                }
                else{
                    size = convertToInteger(d,d1);
                    if(c1[0] > size){
                        printf("Total number of students entered are less than specified\n");
                    }
                    else if(c1[0] < size){
                        printf("Total number of students entered are more than specified\n");
                    }
                    else{
                        check(d1, size, c1[1]);
                    }
                }
            }
            else{
                printf("Wrong Input\n");
            }
        }
    }
}
