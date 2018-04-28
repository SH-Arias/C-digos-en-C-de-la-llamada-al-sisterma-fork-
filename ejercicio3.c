/**                                                                                    
Enunciado: "Write another program using fork() . The child process should              
print “hello”; the parent process should print “goodbye”. You should try to            
ensure that the child process always prints first; can you do this without             
calling wait() in the parent?"                                                         
                                                                                       
Author:                                                                                
Date:                                                                                  
*/                                                                                     
                                                                                       
// Incluya los archivos de cabecera necesarios para llevar a cabo la                   
// solucion en C de acuerdo al enunciado

#include <stdio.h>                                                                 
#include <stdlib.h>                                                                
#include <unistd.h>                                                                
#include <string.h>                                                                
#include <fcntl.h>                                                                 
#include <sys/wait.h>                                               
                                                                                       
int main(int argc, char** argv) {                                                      
  pid_t pid;                                                                           
  int status;                                                                          
                                                                                       
  // invoque la llamada al sistema fork()
  pid = fork();                                              
  if (pid != 0) {                                                                      
    // esta es la parte del padre que debe imprimir 'goodbye'
    waitpid(0, &status,0);
    printf("Soy el padre, mi PID es %d, GOODBYE\n", pid);                          
  } else {                                                                             
    // esta es la parte del hijo que debe imprimir 'hello'
    printf("Soy el hijo, mi PID es %d, HELLO\n", pid);                             
  }                                                                                    
}
