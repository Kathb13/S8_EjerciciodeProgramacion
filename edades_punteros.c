/*Realizar un programa que permita ingresar la edad de una persona y aumentarle 5 años, 
el programa debe ser realizado con funciones y punteros mediante VARIABLES LOCALES*/

#include <stdio.h>
#include <stdlib.h>

//funcion para aumentar la edad

//no va a imprimir porque no es una variabl global, es una variable local

//se le agrego * a tres edades dentro de la funcion

void aumentarEdad(int *edad)
{
    *edad = *edad + 5;
}

int main()
{
    //variables locales
    int edad = 0;

    printf("Ingrese su edad: ");
    scanf("%d", &edad);

    system("cls");

    printf("Edad anterior: %d\n", edad);
    //para que le apunte se genea un & al parametro de la funcion en el main, y se utiliza * en la funcion en la declaracion de variables
    aumentarEdad(&edad);
    printf("Edad modificada: %d\n", edad);

    return 0;
}