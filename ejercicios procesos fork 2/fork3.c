#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main()
{
pid_t pid1, pid2, pid3, pid4, pid5;
  	         printf("PID del proceso padre: %d \n",getpid()); 
  	         //printf("PPID del proceso padre: %d \n",getppid()); 
  	         	         
  	         
  	         
  	         
pid1 = fork();

if (pid1==0)
{
printf("PID del proceso 1: %d \n",getpid()); 
printf("PPID del proceso 1: %d \n",getppid()); 
	
	//el hijo crea otro hijo (nieto)
	//padre crea otro hijo	
	pid2 = fork();

	if (pid2==0)
	{
	printf("PID del proceso 2: %d \n",getpid()); 
	printf("PPID del proceso 2: %d \n",getppid()); 
		
		//nieto2 hace hijo
			
		pid3 = fork();

		if (pid3==0)
		{
		printf("PID del proceso 3: %d \n",getpid()); 
		printf("PPID del proceso 3: %d \n",getppid()); 
		
		}
		else
		{
	
		//
		wait(0);
		}	
	
	
//wait	
wait(0);
			
	}
	else
	{
	//nieto1 hace hijo
	
		//padre crea otro hijo	
		pid4 = fork();

		if (pid4==0)
		{
		printf("PID del proceso 4: %d \n",getpid()); 
		printf("PPID del proceso 4: %d \n",getppid()); 
		
		}
		else
		{
	
	//
	wait(0);
	}	
	
	
//wait	
wait(0);
	
	
	//
	wait(0);
	}	
	
	
//wait	
wait(0);
}
else
{
//padre no hace nada

}
exit(0);
}
