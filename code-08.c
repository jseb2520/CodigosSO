//
//  code-08.c
//  
//
//  Created by Sebastian Hernandez on 4/25/18.
//
#include <stdio.h>
#include <string.h>
//#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
//#include <unistd.h>


#define buffer 32


int main(int argc, char *argv[]){
    
    char buff[buffer];
    int p[2];
    
    if (pipe(p) < 0)
        exit(1);
    
    int frk = fork();
    
    if (frk < 0) {
        fprintf(stderr, "fallo fork 1\n");
        exit(1);
        
    } else if (frk == 0) {
        
        // Hijo #1
        printf(" Child 1 ");
        close(p[0]);
        dup2(p[1], 1);
        printf("Esto sera enviado al Pipe");
        
    } else{
        int frk2 = fork();
        if (frk2 < 0) {
            fprintf(stderr, "fallo fork 2\n");
            exit(1);
        } else if (frk2 == 0) {
            // Hijo 2
            printf(" Child 2 ");
            dup2(p[0], 0);
            close(p[1]);
            
            char buf[512];
            
            read(STDIN_FILENO, buf, 512);
            printf("%s", buf);
            
        } else {
            
            int wp = waitpid(frk2, NULL, 0);
            printf("Fin");
        }
    }
    return 0;
}
