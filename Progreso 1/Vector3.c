#include <stdio.h> //entrada y salida de datos
#include <stdlib.h> //limpiar pantalla y pause comandos del Sistema Operativo
#include <string.h> //manipulacion de cadenas

int main()
{
    int tamanio = 0;
    //posiciones      0   1  2 - 9

   printf("Ingresa la dimension del vector: ");
   scanf("%d", &tamanio);

   int edades[tamanio];

   for (int i = 0; i < tamanio; i++)
   {
        printf("Ingrese la edad %d:", i +1);
        scanf("%d", &edades[i]);
   }
   
   system("cls");

    printf("[ ");
    for (int i = 0; i < tamanio; i++) //donde inicia, donde finaliza y donde incrementa
    //primero se declara la variable directamente en i, y se designa el maximo
    {
        if (i <= tamanio - 2)
        {
            printf("%d, ", edades[i]);
        }
        else
        {
            printf("%d ", edades[i]);
        }
        
    }
    printf("]");

    return 0;
}
