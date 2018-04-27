Semana 11
Mateo + Cuartas

code-01.template
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(char *argc, char ** argv){
    int x;
    
    pid_t pid = fork();
    if(!pid){
        x=2;
        printf("Soy el hijo, mi pid es %d y X tiene el valor de %d para mi\n", getpid(), x);
    }
    else{
        wait(NULL);
        x=3;
        printf("Soy el padre, mi pid es %d y X tiene el valor de %d para mi", getpid(), x);
    }
    
    return 0;
}
