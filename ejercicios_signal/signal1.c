
#include <time.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
//fdsf

//Función de manejo de la señal
void sig_handler(int signo)
{
  if (signo == SIGINT){
  time_t hora;
     	char *fecha ;
    	time(&hora);
	fecha = ctime(&hora) ;
    printf("Fin de proceso %d: %s\n",getpid(),fecha);
    kill(getpid(),SIGKILL);
}
}

void inicio( )
{
	time_t hora;
     	char *fecha ;
    	time(&hora);
	fecha = ctime(&hora) ;
 printf("Inicio del proceso pid %d: %s\n", getpid(),fecha);
 
}


int main(void)
{
inicio(); //Función manejadora de la señal
  signal(SIGINT, sig_handler);
 //Bucle infinito proceso queda a la espera de la señal
  while(1) 
    sleep(1);
  return 0;
}
