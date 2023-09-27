#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t p1, p2, pid_p2, pid_p3;

  p1 = fork();

  		if (p1 == -1 ) //Ha ocurrido un error 
  		{
    		printf("ERROR !!! No se ha podido crear el proceso padre...");
   		 exit(-1);       
  		}
  		if (p1 == 0 )  //Nos encontramos en Proceso p2 
  		{        
  
  
  p2 = fork();

	  		if (p2 == -1 ) //Ha ocurrido un error 
  			{
  	 		 printf("ERROR !!! No se ha podido crear el proceso hijo...");
   			 exit(-1);       
  			}
 	 if (p2 == 0 )  //Nos encontramos en Proceso p3 
  	{        
         printf("Soy el proceso 3 \n");
         printf("PID del p3= %d\n",getpid());
         printf("PID del p2= %d\n",getppid());

  	}
  	else    //Nos encontramos en Proceso p2 
  	{ 

    pid_p3 = wait(NULL); //espera la finalización del proceso p3
    printf("Soy el proceso 2 \n");
    printf("PID del p2= %d\n",getpid());
    printf("PID del p1= %d\n",getppid());   

  	}
//
  }
  	else    //Nos encontramos en Proceso p1 
  { 
         pid_p2 = wait(NULL); //espera la finalización del proceso p2
         printf("Soy el proceso 1 \n");
         printf("PID del p1= %d\n",getpid());
         printf("PID del p2= %d\n",p1); 
   

  }
   exit(0);
}
