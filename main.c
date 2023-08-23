#include <stdio.h>

void typeRetour (signed char type,int debut,int fin){
    for(int i = debut; i <= fin; i++){

        if(type == 'I'){
            if(i % 2 != 0){
                printf("%d,",i);
            }
        }else if(type == 'P'){
            if (i % 2 == 0){
                printf("%d,",i);
            }
        }else{
            printf("Quelque chose s'est mal passe");
            break;
        }
    }
}

int main() {
    int debut = 0;
    int fin = 0;
    signed char type = 'I';
    printf("Ce programme vous permet d'avoir les nombre paire ou impaire d'un interval de nombre\n");
    printf("Tapez les type de nombre que vous voulez, 'I' pour impaire et 'P' pour paire : ");
    scanf("%c",&type);

    if(type != 'P' && type != 'I'){
        printf("Le type \"%c\" n'est pas pris en charge\n",type);
        return 0;
    }

    printf("Debut de l'interval : ");
    scanf("%d",&debut);
    printf("Fin de l'interval : ");
    scanf("%d",&fin);

    if(type == 'I'){
        printf("Dans l'interval de %d a %d les nombre impaire sont : ",debut,fin);
        typeRetour(type,debut,fin);
    }
    else if(type == 'P'){
        printf("Dans l'interval de %d a %d les nombre paire sont : ",debut,fin);
        typeRetour(type,debut,fin);
    }
    return 0;
}