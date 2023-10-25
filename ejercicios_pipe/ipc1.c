#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <time.h>

void main(){


     time_t hora;
     char *fecha ;
     int fd[2]; 
     char buffer[30];
     pid_t pid;
    
     // Creamos el pipe
     pipe(fd); 
     
     //Se crea un proceso hijo
     pid = fork();

     if (pid==0)
     //hijo
     {
                close(fd[1]); // Cierra el descriptor de escritura
                read(fd[0], buffer, 21);
                printf("\t Mensaje leido del pipe: %s \n", buffer);
     
     }
     
     else
     //padre
     {
     

		time(&hora);
		fecha = ctime(&hora) ;
     
     
                close(fd[0]); // Cierra el descriptor de lectura
                printf("El padre escribe en el PIPE...\n");
                write(fd[1], time, 10);
                write(fd[1], " ", 1);
                write(fd[1], fecha, 10);   
                //para que el hijo no se quede huerfano
                wait(NULL);    
     }
     
        
}
