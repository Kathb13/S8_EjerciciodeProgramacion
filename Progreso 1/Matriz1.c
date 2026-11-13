#include <stdio.h> //entrada y salida de datos
#include <stdlib.h> //limpiar pantalla y pause comandos del Sistema Operativo
#include <string.h> //manipulacion de cadenas

int main()
{

int matriz[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
// posiciones     0,0 0,1 0,2

for (int f = 0; f < 3; f++)
{
    for (int c = 0; c < 3; c++)
    {
        printf("%d ", matriz[f][c]);
    }
    printf("\n");

}


    return 0;
}