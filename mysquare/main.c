#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
void printX (int x){
    printf("o");
    for(int i = 0; i < (x - 2); i++){
        printf("-");
    }
    printf("o\n");
}

void printY(int y, int x){
    
    for(int b = 0; b < (y - 2); b++){
        printf("|");
    for(int i = 0; i < (x - 2); i++){
        printf(" ");
    }
        printf("|\n");
    }
}
void my_square(int x,int y){
    if(x > 1 && y > 1){
      printX(x);
      printY(y,x);
      printX(x);
    }else{
        printf("");
    }
}
int main(int ac, char **av){
    
    if(ac <= 2){
        //  my_square(x,y);
        printf("hello");
    }else{
        int x = atoi(av[1]);
        int y = atoi(av[2]);
         my_square(x,y);
    }
    return 0;
}

/*
 :101
 \n,:9
 \n.:14
 \nA:1
 \nC:1
 \nD:1
 \nI:1
 \nL:2
 \nM:1
 \nN:1
 \nP:2
 \nQ:1
 \nS:1
 \nV:2
 \na:44
 \nb:7
 \nc:22
 \nd:22
 \ne:59
 \nf:6
 \ng:3
 \nh:1
 \ni:57
 \nl:35
 \nm:24
 \nn:23
 \no:30
 \np:19
 \nq:4
 \nr:33
 \ns:69
 \nt:47
 \nu:54
 \nv:2
 \n

 L:2
o:30
r:33
e:59
m:24
 :101
i:57
p:19
s:69
u:54
d:22
l:35
t:47
a:44
,:9
c:22
n:23
g:3
.:14
N:1
f:6
M:1
V:2
b:7
S:1
q:4
Q:1
C:1
v:2
P:2
A:1
h:1
D:1
I:1
*/