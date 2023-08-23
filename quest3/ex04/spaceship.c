#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/*
**
** QWASAR.IO -- my_spaceship
**
** @param {char*} param_1
**
** @return {char*}
**
*/

char* my_spaceship(char* param_1)
{
    int size = strlen(param_1);
    int x = 0;
    int y = 0;
    int dir = 0;
    char *direction[4] = {"up","right","down","left"};
    char * jSon = malloc(36 * sizeof(char));
    for(int i = 0; i < size; i++){
        if(param_1[i] == 'R'){
            dir++;
        }
        if(param_1[i] == 'L'){
            dir--;
        }
        if(dir < 0){
                dir = 3;
            }
        if(dir >= 4){
            dir = 0;
        }
        if(param_1[i] == 'A'){
           
            if(strcmp(direction[dir], direction[0]) == 0){
                y--;
            }
            if(strcmp(direction[dir], direction[1]) == 0){
                x++;
            }
            if(strcmp(direction[dir], direction[2]) == 0){
                y++;
            }
            if(strcmp(direction[dir], direction[3]) == 0){
                x--;
            }
        }
    }
    sprintf(jSon,"{x: %d, y: %d, direction: '%s'}",x,y,direction[dir]);
    return jSon;
}

int main(){
    char code[] = "RAALALL";
    printf("code : %s",my_spaceship(code));
    return 0;
}