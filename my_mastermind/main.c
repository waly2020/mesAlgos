#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

void welcome(int round){
    printf("Bienvenue sur my master minde\n");
    printf("Reussirez-vous a trouver le code secret en %d essais ?\n",round);
    printf("Entree un code de 4 nombres\n");
}

void printRound(int current,int round){
    printf("---\nEssai %d/%d\n>",current,round);
}

int getGoodRound(int index,char ** arrayParm){
    if(index == 0){
        return 10;
    }else{
        return atoi(arrayParm[index]);
    }
}

char * getGoodCode(int index,char ** arrayParm){
    char strNums[] = "012345678";
    int size = strlen(strNums);
    char * randomCode = malloc(5 * sizeof(char));

    srand(time(NULL));
    if(index == 0){ 
        for (int i = 0; i < 4; i++) {
        int index = rand() % size;
        randomCode[i] = strNums[index];
        }
        randomCode[4] = '\0';
        return randomCode;
    }else{
        return arrayParm[index];
    }
}

bool wrongInput(char * userCode){
    int size = strlen(userCode);
    if (size == 4)
    {
        for(int i = 0; i < size; i++){
        if(!(userCode[i] >= '0' && userCode[i] <= '9')){
            return false;
        }
        return true;
    }
    }
    return false;
}

void wrongInputMessage(){
    printf("Entree des valeurs numerique\n>");
}

void wrong(char * code,char * userCode){

    int size = strlen(code);
    int wrong = 0;
    int well = 0;

    for (int i = 0; i < size; i++){
      char letter[2];
      letter[0] = userCode[i];
      if(strstr(code,letter) != NULL){
        if(userCode[i] == code[i]){
            well++;
        }else if(userCode[i] != code[i]){
            wrong++;
        }
      }
    }
    printf("Pieces bien place : %d\nPieces mal place : %d\n",well,wrong);
}

void win(){
    printf("Felicitation vous avez reussi\n");
}

void my_mastermind(char * code,int rounds){

    char userCode[5];
    char input;
    int round = 0;
    int id = 0;
    welcome(rounds);
    printRound(round,rounds);
    while (read(STDIN_FILENO, &input, 1) && input != '\n')
            {
                int ls = sizeof(userCode);
                if (id < ls - 1)
                {
                    userCode[id++] = input;
                }
            }
            userCode[id] = '\0';

    while (strcmp(code,userCode) != 0 && round < (rounds - 1)){
        if (wrongInput(userCode)){
            round++;
            wrong(code,userCode);
            printRound(round,rounds);
            id = 0;
            while (read(STDIN_FILENO, &input, 1) && input != '\n')
            {
                int ls = sizeof(userCode);
                if (id < ls - 1)
                {
                    userCode[id++] = input;
                }
            }
            userCode[id] = '\0';
        }else{
            wrongInputMessage();
            id = 0;
            while (read(STDIN_FILENO, &input, 1) && input != '\n')
            {
                int ls = sizeof(userCode);
                if (id < ls - 1)
                {
                    userCode[id++] = input;
                }
            }
            userCode[id] = '\0';
        }
    }

    if (strcmp(code,userCode) == 0){
       win();
    }else{
        wrong(code,userCode);
        printf("---\nEchec, le code secret etait %s\n", code);
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
    my_mastermind(getGoodCode(code,param),getGoodRound(round,param));
    
    return 0;
}