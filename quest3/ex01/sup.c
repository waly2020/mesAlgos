#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void my_ngram(char * txt){
    // char txt[] = "Bonjour";
    char l = 'o';
    int size = strlen(txt);
    char * newTxt = malloc(size * sizeof(char));
    // strcpy(newTxt,txt);

    for (int i = 0; i < size; i++)
    {
        int nwC = 0;
        if(txt[i] == l){
            // i+= 1;
            for(int j = i; j < size; j++){
                txt[j] = txt[j + 1];
            }
            i--;
            size--;
        }
    }
    // int i = 0;
        // for(i = 0; i < size; i++){
        //     printf("niv 1 : i = %d size = %d\n",i,size);
        //     if(txt[i] == l){

        //         // printf("niv 1 i = %d l = %c\n",i,txt[i]);

        //         for(int j = i + 1; j < (size - i); j++){
        //             if(txt[j] == l){

        //                 // printf("niv 2 i = %d j = %d l = %c\n",i,j,txt[j]);
        //                 int k = j;
        //                 while (txt[k] != '\0')
        //                 {
        //                     // printf("set str k + 1 = %c\n",txt[k]);
        //                     txt[k] = txt[k + 1];
        //                     // k--;
        //                     // size--;
        //                     k++;
        //                 }
        //                 // i--;
        //                 i = 0;
        //                 printf("end : i = %d size = %d\n",i,size);
        //             }
        //         }
        //     }
        // }
    
    printf("%s\n",newTxt);
}

int main(){

    char name[] = "Bonjour";

    my_ngram(name);
    printf("%s",name);

    return 0;
}