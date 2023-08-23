#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * my_strrchr(char * param_1,char param_2){
  
  int size = strlen(param_1);
  char * newChar = malloc(size * sizeof(char));
  int index = 0;
  
  for(int i = size; i > 0; i--){
    if(param_1[i] == param_2){
      
      for (int b = i; b < size; b++){
        newChar[index] = param_1[b];
        index++;
      }
      //return newChar;
      break;
      
    }
  }
  if(index > 0){
    return newChar;
  }
  return newChar;
}

int main(){
    char * txt1 = "hello";
    char txt0 = 'd';
    printf("%s\n",my_strrchr(txt1,txt0));
    return 0;
}