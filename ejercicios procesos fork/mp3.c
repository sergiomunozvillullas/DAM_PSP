#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
//Variables
  pid_t proceso, pid_hijo;
  
  	//Estamos en el proceso padre
  	printf("Soy el proceso: 1\n");
        printf("PAPA PID= %d\n",getpid());
        printf("-------------------------------------\n");
  
//Recorro el for empezando en el 2 porque ya esta existe el 1 que es el padre y voy hasta el 4, creando 2 procesos, el 2 y el 3
  for(int i=2; i<4; i++){
  proceso = fork();
  
  		if (proceso == -1 ) //Ha ocurrido un error 
  		{
    		printf("ERROR !!! No se ha podido crear el proceso hijo...");
    		exit(-1);       
  		}
  		if (proceso == 0 )  //Nos encontramos en Proceso hijo 
  		{     
 
  		//printf("Voy a dormir 10 segundos ... \n");
  		 //sleep(10);
  		// } 
  		 printf("Soy el proceso: %d\n",i);
  	         printf("PID del proceso %d: %d\n",i,getpid()); 
  	         printf("PPID del proceso %d: %d\n",i,getppid()); 
  	         //PID del padre es el PID del hijo
		 printf("-------------------------------------\n");
 		 break;
  		 }
  	//Nos encontramos en Proceso padre 
  	else
  	{ 
     	//espera la finalización del proceso hijo
      	pid_hijo = wait(NULL); 

	}

  }

     exit(0);
}
  
  
