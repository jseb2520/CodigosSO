Valencia + Taborda + Rodriguez

code-02.template
/*
 Enunciado: "Write a program that opens a file (with the open() system call)
 and then calls fork() to create a new process. Can both the child and parent
 access the file descriptor returned by open()? What happens when they are
 writing to the file concurrently, i.e., a t the same time?"
 
 Author:
 Date:
 */
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> // Incluir archivos de cabecera para las funciones que requiere para
// solucionar el enunciado


int main(int argc, char **argv) {
    // Usar estas variables
    int x;
    pid_t pid;
    char *filename="code-02.txt";
    int fd;
    
    //
    fd = open(filename, O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
    // Instrucciones para abrir archivo de lectura/escritura)
    //
    
    x = 100;
    pid = fork();
    if (pid == 0) {
        x++;
        dprintf(fd, "Soy el hijo, mi PID es %d y mi x es %d\n", getpid(), x);
    } else {
        x+=2;
        dprintf(fd, "Soy el padre, mi PID es %d y mi x es %d\n", pid, x);
    }
    
    close(fd);
}
