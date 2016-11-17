#include"header.h"
int count_lines(FILE* fp){
    int counter = 0;
    char c[100];
    while(fgets(c,100,fp) != NULL){
        counter++;
    }
    fclose(fp);
    return counter;
}
