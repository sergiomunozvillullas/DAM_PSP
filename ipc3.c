#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>

int main() {
    time_t hora;
    char *fecha;
    int fd[2];
    int suma = 0;
    pid_t pid, pid_proceso;

    char buffer[6]; // Tamaño reducido para leer números de 1 a 50
    char numeroleer[6]; // Tamaño reducido para almacenar números aleatorios
    int random1,random2,num1,num2;

    // Inicializa la semilla para rand()
    srand(time(NULL));

    // Creamos el pipe
    pipe(fd);

    // Se crea un proceso hijo
    pid = fork();

    if (pid == 0) {
    	// Cierra el descriptor de escritura
        close(fd[1]); 
        read(fd[0], buffer, sizeof(buffer));
        char *token = strtok(buffer, " "); // Divide la cadena usando un espacio
        if (token) {
            num1 = atoi(token); // Convierte la primera parte en un entero
        }

        token = strtok(NULL, ",");
        if (token) {
            num2 = atoi(token); // Convierte la segunda parte en un entero
        }
        
        printf("Primer número leído: %d\n", num1);
        printf("Segundo número leído: %d\n", num2);
        printf(" \n");
        printf("Suma de los números: %d\n", num1 + num2);
        printf("Resta de los números: %d\n", num1 - num2);
        printf("Multiplicación de los números: %d\n", num1 * num2);
        printf("División de los números: %d\n", num1 / num2);
    } else {
        random1 = (rand() % 50) + 1;
        random2 = (rand() % 50) + 1;
        // Convierte el número a una cadena
        sprintf(numeroleer, "%d %d", random1, random2); 
        write(fd[1], numeroleer, strlen(numeroleer));

        // Para que el hijo no se quede huérfano
        wait(NULL);
    }

    return 0;
}

