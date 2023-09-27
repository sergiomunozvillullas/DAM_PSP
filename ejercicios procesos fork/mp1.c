#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t padre, pid_hijo;

  padre = fork();

  		if (padre == -1 ) //Ha ocurrido un error 
  		{
    		printf("ERROR !!! No se ha podido crear el proceso hijo...");
    		exit(-1);       
  		}
  if (padre == 0 )  //Nos encontramos en Proceso hijo 
  {       
  	  printf("Nombre del alumno: \n");
	  printf("Sergio Muñoz Villullas \n");


  }
  else    //Nos encontramos en Proceso padre 
  { 
     //espera la finalización del proceso hijo
      pid_hijo = wait(NULL); 
      printf("PID del hijo= %d\n",padre);   
      printf("PID del padre= %d\n",getpid()); 

  }
   exit(0);
}
