#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void welcome(int round){
    printf("Will you find the secret code?\nPlease enter a valid guess\n---\nRound %d\n",round);
}
bool wrongInput(char * userCode){
    if (strlen(userCode) == 4)
    {
        for(int i = 0; i < strlen(userCode); i++){
        if(!(userCode[i] >= '0' && userCode[i] <= '9')){
            return false;
        }
        return true;
    }
    }else{
       return false;
    }
    
}
void wrongInputMessage(){
    printf("Wrong input!\n");
}
void wrong(char * code,char * userCode,int round){

    int size = strlen(code);
    int wrong = 0;
    int well = 0;

    for (int i = 0; i < size; i++){
      char letter[2];
      letter[0] = userCode[i];
      // printf("letter : %s\n",letter);
    //   printf("teste sur : %s -> %s\n",letter,strstr(code,letter));

      if(strstr(code,letter) != NULL){
        // printf("%s existe\n",letter);
        if(userCode[i] == code[i]){
            well++;
        }else if(userCode[i] != code[i]){
            wrong++;
        }
      }
    }
    printf("Well placed pieces: %d\nMisplaced pieces: %d\n---\nRound %d\n",well,wrong,round);
}

void win(){
    printf("Congratz! You did it!");
}

void my_mastermind(char * code,int rounds){

    char userCode[5];
    int round = 0;
    welcome(round);
    scanf("%s",userCode);

    while (strcmp(code,userCode) != 0 && round < rounds){
        printf("Valeur user code : %s\n",userCode);
        if (wrongInput(userCode)){
            wrong(code,userCode,round);
            scanf("%s",userCode);
            round++;
        }else{
            wrongInputMessage();
            scanf("%s",userCode);
        }
    }

    if (strcmp(code,userCode) == 0){
       win();
    }else{
        printf("echec");
    }
    
}


int main(int nbr,char ** param){
    int code = 0;
    int round = 0;
    for (int i = 0; i < nbr; i++)
    {
        if(strcmp(param[i],"-c") == 0){
            code = i + 1;
        }
        if(strcmp(param[i],"-t") == 0){
            round = i + 1;
        }
    }
   if(code == 0){
    code = ((rand() % 9000) + 999);
   }
    printf("-c = %s,-t = %s",param[code],param[round]);
    // my_mastermind(param[1],atoi(param[2]));
    
    return 0;
}