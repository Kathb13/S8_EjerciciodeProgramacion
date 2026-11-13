#include <stdio.h>
#include <stdlib.h>

int main ()
{
    //programa que permite usar la estructura bucle DO WHILE
    /*no hace nada porque no insertamos el switch, solo repite una y otra vez el menu
    hasta que el usuario decida salir del programa mediante la opcion 2*/

    int op;

    do
    {
        system("cls");
        printf("==== MENU DEL OPCIONES ==== \n");
        printf("-------------------------- \n");
        printf("1. Saludar \n");
        printf("2. Salir \n");
        printf("-------------------------- \n");

        printf("Ingrese una opcion (1-2)\n\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Bienvenido al bucle...");
            system("pause");
            break;
        case 2:
            printf("Saliendo del sistema...");
            break;
        
        default:
            printf("Opcion incorrecta...");
            break;
        }

    } while (op != 2);
    

    return 0;
}