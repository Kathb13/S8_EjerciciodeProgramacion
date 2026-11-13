/*Realizar un programa que permita ingresar 3 notas de un alumno y calcular el promedio tambien
verificar si el alumno ha realizado recuperacion aumentar a la nota mas baja 2pts extra y
luego volver a ver el promedio con la recuperacion*/

#include <stdio.h>
#include <stdlib.h>

#define NUMNOTAS 3

// prototipos de funciones
void leernotas(float *notas, int contadornotas);
void mostrarnotas(float *notas, int contadornotas);
float calcularpromedio(float *notas, int contadornotas);
void mejorarnotamasBaja(float *notas, int contadornotas);

int main()
{

    float notas[NUMNOTAS];
    printf("===== Sistema sencillo de notas =====\n");
    // en vectores no hace falta poner el &, si no fuera vector se poner el & si o si
    leernotas(notas, NUMNOTAS);
    mostrarnotas(notas, NUMNOTAS);
    printf("El promedio original del alumno es: %.2f\n", calcularpromedio(notas, NUMNOTAS));

    mejorarnotamasBaja(notas, NUMNOTAS);

    printf("El promedio del alumno con recuperacion es: %.2f\n", calcularpromedio(notas, NUMNOTAS));

    return 0;
}

// funciones
void leernotas(float *notas, int contadornotas)
{
    for (int i = 0; i < contadornotas; i++)
    {
        printf("Ingrese la nota %d: ", i + 1);
        scanf("%f", notas + i); // aritmetica de punteros, es lo mismo que antes notas[i]
        // se esta guardando la direccion, si quisiera guardar el valor tendria que ser *()
    }
}
void mostrarnotas(float *notas, int contadornotas)
{
    printf("\n----------------------------------\n");
    for (int i = 0; i < contadornotas; i++)
    {
        printf("Nota %d: %.2f\n", i + 1, *(notas + i));
    }
    printf("\n----------------------------------\n");
}

float calcularpromedio(float *notas, int contadornotas)
{
    int suma = 0;
    for (int i = 0; i < contadornotas; i++)
    {
        suma = suma + *(notas + i);
    }
    return suma / contadornotas;
}
void mejorarnotamasBaja(float *notas, int contadornotas)
{
    int posicionBaja = 0;

    for (int i = 0; i < contadornotas; i++)
    {
        if (*(notas + i) < *(notas + posicionBaja))
        {
            posicionBaja = i;
        }
    }

    *(notas + posicionBaja) += 2;

    // validacion para que la nota no pase de 10 en caso de tener 9 y sumar dos puntos
    if (*(notas + posicionBaja) > 10)
    {
        *(notas + posicionBaja) = 10;
    }
}

//hagan la pregunta al docente si el alumno recupero

