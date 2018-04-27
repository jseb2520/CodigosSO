Sanclemente
code-03.template
/**
 Enunciado: "Write another program using fork() . The child process should
 print "hello"; the parent process should print "goodbye". You should try to
 ensure that the child process always prints first; can you do this without
 calling waitpid() in the parent?"
 
 Author:
 Date:
 */

// Incluya los archivos de cabecera necesarios para llevar a cabo la
// solucion en C de acuerdo al enunciado
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
    pid_t pid;
    pid = fork();
    
    // invoque la llamada al sistema fork()
    if (pid != 0) { :V
        waitpid(pid,NULL,0);
        printf("%s\n","Goodbye");
        
    } else {
        printf("%s\n","Hello");
        sleep(2);
    }
    return 0;
}

