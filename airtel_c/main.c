#include <stdio.h>
// scanf("%s",name);
int main(){
    char ** texte[][] = {
        {
            "Creee",
            "Creee",
            "Creee",
            "Creee",
            "Creee",
            "Creee",
        },
    };
   for (int i = 0; i < 1; i++)
   {
    /* code */
    for (int b = 0; b < 4; b++)
    {
        /* code */
        printf("%s",texte[0][b])
    }
    
    printf("%d.%s\n",i + 1,texte[i]);
   }
   
    return 0;
}
