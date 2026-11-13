#include <stdio.h>

int main()

{
    /*realizar un programa que permita dar diferentes opciones a un usuario
    1. Saludo, 2. Mensaje, 3. Despedida*/

    //variables
    int op;

    printf("==== MENU DEL USUARIO ==== \n");
    printf("-------------------------- \n");
    printf("1. Saludo \n");
    printf("2. Mensaje \n");
    printf("3. Despedida \n");
    printf("4. Salir \n");
    printf("-------------------------- \n");
    
    printf("Ingrese una opcion (1-4)\n\n");
    scanf("%i", &op);

    switch (op)
    {
    case 1:
        printf("Bienvenido a programacion I...\n");
        break;
    case 2:
        printf("Este es un mensaje para que repasen progra...\n");
        break;
    case 3:
        printf("Bye...\n");
        break;
    case 4:
        printf("Saliendo del sistema...\n");
        break;
    
    default:
        printf("Opcion incorrecta...");
        break;
    }
    return 0;
}