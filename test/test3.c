#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* my_strstr(char* param_1, char* param_2)
{
    int size = strlen(param_1);
    int size2 = strlen(param_2);

    char * strTest = malloc(size * sizeof(char));
    char * newText = malloc(size2 * sizeof(char));

    if (size2 == 0){
         return param_1;
    }else{

        for (int i = 0; i < size; i++){

            if(param_1[i] == param_2[0]){
                for(int b = 0; b < size2; b++){
                    strTest[b] = param_1[i + b];
                }
            }
            if( strcmp(strTest,param_2) == 0){
                for (int c = 0; c < (size - i); c++)
                {
                    newText[c] = param_1[i + c];
                }
                return newText;
                break;
            }else{
                strcpy(strTest,"");
            }
        }
    }

    return NULL;
}
int main(){
    char txt[] = "1212121223121212";
    char t[] = "23";
    printf("%s",my_strstr(txt,t));
    
    return 0;
}