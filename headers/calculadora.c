// en el .c va el desarrollo de las funciones

#include <stdio.h>
#include "calculadora.h" //es el nombre del archivo, se llama a nuestra libreria

// desarollo de las funciones void
void sumar (double num1, double num2)
{
    double resultado = num1 + num2;
    printf("\nResultado de la suma: %.2lf\n", resultado); //lf son las siglas del tipo double
}

void restar (double num1, double num2)
{
    double resultado = num1 - num2;
    printf("\nResultado de la resta: %.2lf\n", resultado); 
}

// desarrollo de las funciones que devuelven
double multiplicar (double num1, double num2)
{
    return num1*num2;
}

double dividir (double num1, double num2)
{
    return num1/num2;
}