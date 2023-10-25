#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>

void main() {
    time_t hora;
    char *fecha;
    int fd[2];
    int suma = 0;
    pid_t pid, pid_proceso;

    char buffer[4];
    char numeroleer[2];
    // Creamos el pipe
    pipe(fd);

    // Se crea un proceso hijo
    pid = fork();

    if (pid == 0)
    // hijo
    {
        close(fd[1]); // Cierra el descriptor de escritura
        read(fd[0], buffer, 4);

        if (buffer[3] == '+') {
            suma = 0; // Reiniciamos la suma
            for (int i = 0; i < 3; i++) {
                printf("numero: %c \n", buffer[i]);
                // el -'0' hace que el ascii lo convierta en int
                suma = suma + (buffer[i] - '0');
            }
            printf("suma: %d \n", suma);
        }
    }

    else
    // padre
    {

        close(fd[0]); // Cierra el descriptor de lectura

        for (int i = 0; i < 3; i++) {
            sprintf(numeroleer, "%d", i); // Convertir el entero a cadena
            write(fd[1], numeroleer, 1); // Escribir en el pipe
        }

        write(fd[1], "+", 1);

        // Para que el hijo no se quede huérfano
        wait(NULL);
    }
}

