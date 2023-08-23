#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
**
** QWASAR.IO -- my_is_sort
**
** @param {integer_array*} param_1
**
** @return {bool}
**
*/
#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY
typedef struct s_integer_array
{
    int size;
    int* array;
} integer_array;
#endif

bool my_is_sort(integer_array* param_1)
{
    int size = param_1 -> size;
    char * newArray = malloc(size * sizeof(char));
    int index = 0;
    for (int  i = 0; i < size; i++)
    {
       if(param_1->array[i] != param_1->array[i + 1]){
        newArray[index] = param_1->array[i];
        index++;
       }
    }
    if(newArray[0] > newArray[1]){
        for (int j = 0; j < (index - 1); j++)
        {
            if(newArray[j] < newArray[j + 1]){
                // printf("decroissant cond inf, %d est < a %d, index = %d,j = %d\n",newArray[j],newArray[j + 1],index,j);
                return false;
            }
        }
        
    }else if(newArray[0] < newArray[1]) {
        for (int y = 0; y < (index - 1); y++)
        {
            if(newArray[y] > newArray[y + 1]){
                // printf("decroissant cond sup, %d est > a %d, index = %d,y = %d\n",newArray[y],newArray[y + 1],index,y);
                return false;
            }
        }
    }
    return true;
    
}
int main(){
    integer_array perso;
    int tab[] = {1,1,1,2,2,2,3,4,5,6,7,8};
    perso.size = 12;
    perso.array = tab;
    int i = 0;
    printf("%d",my_is_sort(&perso));
    
    return 0;
}