#include <stdio.h>
#include <unistd.h>
#include "link.h"

int my_putchar(char c) {
  return write(1, &c, 1);
}

void size (char * arr){
    char texte[] = "";
    int i = 0;
    while (arr[i] != '\0')
    {
        /* code */
        my_putchar(arr[i]);
        // texte[i] += *arr + i;
        i++;
    }
    
    // printf("texte %s", texte);
    // printf("%c",arr[2]);
    
}