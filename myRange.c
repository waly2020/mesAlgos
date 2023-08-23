#include <stdio.h>
/*
**
** QWASAR.IO -- my_range
**
** @param {int} param_1
** @param {int} param_2
**
** @return {int*}
**
*/
#define MAX_SIZE 255
int * my_range(int param_1, int param_2)
{
  static int tab[MAX_SIZE];
  int idx = 0;
  for (int i = param_1; i < param_2; i++){
    tab[idx] = i;
    idx++;
  }
  return tab;
}
int main (){
    int *tablbeau = my_range(8,16);
    printf("%d",tablbeau[0]);
    return 0;
}
