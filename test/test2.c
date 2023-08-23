#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * alert(char * text,char rest){
    int size = strlen(text);
    char * newtext = malloc(size * sizeof(char));
    for (int i = 0; i < size; i++){
        if (text[i] == rest)
        {
            for (int b = 0; b < (size - i); b++)
            {
                newtext[b] = text[i + b];
            }
            break;
        }
        
    }
    return newtext;
}

int main(){
    char text[] = "waly le dev";
    char l = 'a';
    printf("%s",alert(text,l));
    return 0;
}