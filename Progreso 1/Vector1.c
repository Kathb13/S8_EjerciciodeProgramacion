#include <stdio.h> //entrada y salida de datos
#include <stdlib.h> //limpiar pantalla y pause comandos del Sistema Operativo
#include <string.h> //manipulacion de cadenas

int main()
{
    //variables
    char nombre1[4] = "Luis";
    char usuario[30]; //Luis\n

    printf("Ingrese su usuario: ");
    fgets(usuario, sizeof(usuario), stdin); //rececpcion de cadena de caracteres
    //se puede poner directamente el rango de la variable o se utiliza el sizeof para que lea automaticamente el tamaño

    usuario[strcspn(usuario, "\n")] = '\0'; //elimina el ultimo registro, en este caso el \n

    if (strcmp(usuario, nombre1) == 0) //compara dos cadenas de caracteres
    // 0 es verdadero y 1 es falso

    {
        printf("Nombres iguales...");
    }
    else
    {
        printf("No coinciden...");
    }

    return 0;
}