#include <stdio.h>
#include <string.h>

int main(){
    char * txt;
    char * txt2 = "ab";
    printf("\n\n\nQuel est votre nom ?\n\n\n\n");
    scanf("%s",txt);
    printf("\n\n\nBienvenu %s\n\n\n",txt);
    return 0;
}