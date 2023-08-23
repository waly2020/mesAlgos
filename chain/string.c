#include <stdio.h>
#include "link.h"

char* my_upcase(char* param_1)
{
    char text = *param_1;
    return text;
}

int main (){
    char txt[] = "hello world";
    char myText = * my_upcase(txt);
    printf("Le texte est : ");
    // printf("%s",myText);
    return 0;
}