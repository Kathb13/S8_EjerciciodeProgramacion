#include <stdio.h> //entrada y salida de datos
#include <stdlib.h> //limpiar pantalla y pause comandos del Sistema Operativo
#include <string.h> //manipulacion de cadenas

int main()
{
    int edades[10] = {10,11,12};
    //posiciones      0   1  2 - 9

    edades[3] = 50; //crea un nuevo registro si esta vacia la posicion (asigna el 50 a la tercera posicion que está vacía)
    edades[0] = 100; //edita el elemento dependiendo de la posicion (remplaza el 10 con el 100 en la posicion 0)

    //como debe investigar como eliminar un dato en vectores y matrices


    //imprimir el vector en el siguiente formato [v1,v2,v3,etc]
    printf("[ ");
    for (int i = 0; i < 10; i++) //donde inicia, donde finaliza y donde incrementa
    //primero se declara la variable directamente en i, y se designa el maximo
    {
        if (i <= 8)
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
