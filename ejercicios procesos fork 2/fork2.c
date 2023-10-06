#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main()
{
pid_t pid1, pid2, pid3;
  	         printf("PID del proceso padre: %d \n",getpid()); 
  	         //printf("PPID del proceso padre: %d \n",getppid()); 
pid1 = fork();

if (pid1==0)
{
printf("PID del proceso 1: %d \n",getpid()); 
printf("PPID del proceso 1: %d \n",getppid()); 
	

}
else
{
//padre crea otro hijo	
	pid2 = fork();

	if (pid2==0)
	{
	printf("PID del proceso 2: %d \n",getpid()); 
	printf("PPID del proceso 2: %d \n",getppid()); 

	}
	else
	{
	//padre crea otro hijo	
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
	
	//
	wait(0);
	}	
	
	
//wait	
wait(0);

}
exit(0);
}
