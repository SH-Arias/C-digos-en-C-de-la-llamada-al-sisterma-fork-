/*                                                                                     
Enunciado: "Write a program that opens a file (with the open() system call)            
and then calls fork() to create a new process. Can both the child and parent           
access the file descriptor returned by open()? What happens when they are              
writing to the file concurrently, i.e., a t the same time?"                            
                                                                                       
Author:                                                                                
Date:                                                                                  
*/

// Incluir archivos de cabecera para las funciones que requiere para                   
// solucionar el enunciado                                                            

#include <stdio.h>                                                                 
#include <stdlib.h>                                                                
#include <unistd.h>                                                                
#include <string.h>                                                                
#include <fcntl.h>                                                                 
#include <sys/wait.h>
                                                                                       
int main(int argc, char **argv) {                                                      
  // Usar estas variables                                                              
  int x;                                                                               
  pid_t pid;                                                                           
  char *filename="code-02.txt";                                                        
  int fd;                                                                              
                                                                                       
  //                                                                                   
  // Instrucciones para abrir archivo de lectura/escritura)
                                                          
  fd = open(filename, O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);                            
  //                                                                                   
                                                                                       
  x = 100;                                                                             
  pid = fork();                                                                        
  if (pid == 0) {                                                                      
    x++;                                                                               
    // Instruccion para escribir en archivo una cadena                                 
    // acompanada del valor de 'x'
    dprintf(fd, "Yo soy el hijo, mi PID es %d y mi valor de x es %d\n", getpid(), x);                                                     
  } else {                                                                             
    x+=2;                                                                              
    // Instruccion para escribir en archivo una cadena                                 
    // acompanada del valor de 'x'
    dprintf(fd, "Yo soy el padre, mi PID es %d y mi valor de x es %d\n", getpid(), x);                                                     
  }                                                                                    
                                                                                       
  close(fd);                                                                           
}
