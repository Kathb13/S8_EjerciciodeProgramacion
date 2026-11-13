#include <stdio.h>

int main ()
{
    /*Realizar un programa que permita imprimir en pantalla los 10 primeros numeros comenzando
    desde 0 e incluyendo el 10 de forma ascendente*/

    int contador = 0;

    while (contador <= 10)
    {
        printf("Elemento:%i\n", contador);
        contador++; //contador = contador + 1
    }
    

    return 0;
}