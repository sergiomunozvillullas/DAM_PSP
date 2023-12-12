#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void signal_funcion(int signum){
int cont=0;
  printf("Han transcurrido %d segundos\n",cont);
  sleep(5);
  cont=cont+5;
}

int main(){
  pid_t pid;

  signal(SIGUSR1,signal_funcion); // Registro de la señal SIGUSR1    
  kill(getpid(),SIGUSR1);  // Se envía la señal SIGUSR1 a sí mismo
  printf("Terminación del proceso\n");
  
  return 0;
}
