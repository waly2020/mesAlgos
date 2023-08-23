#include <stdio.h>

void getSqr(int num){
    printf("le carre de %d est %d\n",num,num * num);
}

int main (){
    getSqr(18);
    getSqr(1);
    getSqr(8);
    getSqr(4);
    return 0;
}