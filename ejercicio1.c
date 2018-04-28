/**                                                                                    
Enunciado: Write a program that calls fork(). Before calling fork(), have              
the main process access a variable (e.g., x) and set its value to something            
(e.g., 100). What value is the variable in the child process? What happens             
to the variable when both the child and parent cha nge the value of x?                 
                                                                                       
Author:                                                                                
Date:                                                                                  
*/                                                                                     
                                                                                       
// Incluir archivos de cabecera que definen los prototipos de las                      
// funciones: 'printf', 'sleep' y 'fork'                                               

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
                                                                                       
int main(char *argc, char** argv) {                                                    
  int x;                                                                               
  pid_t pid;
  x = 17;                                                                           
                                                                                       
  //                                                                                   
  printf("En el padre el x inicial es %d\n", x);
  
  pid = fork();

  if(!pid){
    x = 2;
    printf("Soy el hijo, mi PID es %d y mi x es %d\n", getpid(), x);
  }else{
    wait(NULL);
    x = 3;
    printf("Soy el padre, mi PID es %d y mi x es %d\n", getpid(), x);
  }                                                                         
  //                                                                                   
                                                                                       
  return 0;                                                                            
}
