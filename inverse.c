#include <stdio.h>
/*
**
** QWASAR.IO -- my_swap
**
** @param {int*} param_1
** @param {int*} param_2
**
** @return {void}
**
*/

void my_swap(int* param_1, int* param_2)
{
    printf("a - %d, b - %d",&param_1,&param_2);
}

int main(){
    int *a = 10;
    int *b = 12;
    my_swap(a,b);
    return 0;
}