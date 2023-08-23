#include <stdio.h>
#include <string.h>
char* reverse_string(char* param_1)
{
    // char txt[] = "";
    // strcpy(txt,param_1);
    // printf("%d",txt);
    int size = strlen(param_1);
    for (int i = (size - 1); i > size; i++) {
        // param_1 = &txt + (size - i);
        printf("%c\n",param_1[(size - 1) - i]);
        // param_1[i] = param_1[(size - 1) - i];
    }
    return param_1;
}

int main(){
    char txt[] = "hello";
    reverse_string(txt);
    printf("%s",txt);
    return 0;
}