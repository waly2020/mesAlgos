#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sortString(char * str) {
    int i, j;
    int size = strlen(str);
    char key;
    for (i = 1; i < size; i++) {
        key = str[i];
        j = i - 1;

        while (j >= 0 && str[j] > key) {
            str[j + 1] = str[j];
            j = j - 1;
        }
        str[j + 1] = key;
    }
}

void my_ngram(char * txt){
    
    sortString(txt);

    int size = strlen(txt);
    char * newTxt = malloc(size * sizeof(char));
    
    int idx = 0;

    for(int i = 0; i < size; i++){
        if(strchr(newTxt,txt[i]) == NULL){
            // printf("Pas de corespondances a l'index %d\n",i);
            newTxt[idx] = txt[i];
            idx++;
            int nbl = 0;
            for(int c = 0; c < size; c++){
                if(txt[i] == txt[c]){
                    nbl++;
                }
            }
            printf("%c:%d\n",txt[i],nbl);
        }
    }
    
    // printf("%d\n",size);
}
// 
int main(int nbParam,char ** param){
    // long size = param[1];
    // printf("\n\n\n%s\n\n\nsize : %lli",param[1], size)
    if(nbParam){
        my_ngram(param[1]);
    }
    // printf("%s",name);

    return 0;
}