#include <stdio.h>

/*El valor de la variable es: 10
El valor de memoria de la variable es 000000802f3ff71c*/

int main()
{
    int numero = 10;
    //el * es para almacenar la direccion de memoria de la variable asignada y sacada previamente & en numero
    int *puntero = &numero;

    //imprimir el valor de la variable
    printf("El valor de la variable es: %d\n", numero);

    //imprimir la direccion de memoria de la variable
    //se pone %p porqua ya es de tipo puntero
    //el (void*) es un casteo de variables: transformacion de variables
    printf("La direccion de memoria de la variable es %p\n", (void*)&numero);

    //imprimir la direccion de la memoria mediante el puntero
    printf("La direccion de memoria mediante el puntero es: %p\n", (void*) puntero);

    //imprimir el dato que almacena esa direccion de memoria
    printf("El valor de la variable original mediante el puntero es: %d\n", *puntero);

    //alterar el dato
    *puntero = 500;

    //imprimir el valor de la variable
    printf("El valor de la variable es: %d\n", numero);

    return 0;
}