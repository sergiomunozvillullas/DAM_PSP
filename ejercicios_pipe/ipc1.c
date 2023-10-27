#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <time.h>
#include <string.h>

void main(){


     time_t hora;
     char *fecha ;
     int fd[2]; 
     
     pid_t pid,pid_proceso;
     
     //para que lo tenga el hijo
	time(&hora);
	fecha = ctime(&hora) ;
	//para saber cuanto la logitud de la fecha
	//+1 para caracer nulo
	size_t longitud = strlen(fecha)+1;
	char buffer[longitud];
     // Creamos el pipe
     pipe(fd); 
     
     //Se crea un proceso hijo
     pid = fork();

     if (pid==0)
     //hijo
     {
                close(fd[1]); // Cierra el descriptor de escritura
                read(fd[0], buffer, longitud);
                printf("La fecha es: %s \n", buffer);
                printf("pid del hijo= %d\n",getpid());

     
     }
     
     else
     //padre
     {

		
     
	close(fd[0]); // Cierra el descriptor de lectura
        
	
         write(fd[1], fecha, longitud);

        // Para que el hijo no se quede huérfano
        wait(NULL); 
     }
     
        
}
