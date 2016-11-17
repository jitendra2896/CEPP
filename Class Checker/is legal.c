#include "header.h"
int isLegal(char c[]){
    int length = strlen(c);
    int i;
    for(i = 0;i<length;i++){
        if(c[i] != ' ' && c[i] != '\n' && c[i] != '-'){
            if(!isdigit(c[i]))
                return 0;
        }
    }
    return 1;
}
