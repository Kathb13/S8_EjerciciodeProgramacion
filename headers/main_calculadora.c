//aqui llamamos a la funciones ya creadas anteriormente, es el cuerpo del programa
// ctrl + shift + alt + flecha para abajo para el multicursor


#include <stdio.h>
#include <stdlib.h>
#include <string.h> //como no esta utilizada anda opaca, y en este caso no la vamos a utilizar
#include "calculadora.h"

int main()
{
    int op;
    double num1, num2, resultado;

    do
    {
        system("cls");
        printf("===== Calculadora con Headers =====\n");
        printf("1.- Sumar\n");
        printf("2.- Restar\n");
        printf("3.- Multiplicar\n");
        printf("4.- Dividir\n");
        printf("5.- Salir\n");
        printf("Ingrese una opcion entre 1-5: ");
        scanf("%d", &op);

        //para evitar errores en el .exe
        if (op >= 1 && op < 5)
        {
            printf("Ingrese el primer numero: ");
            scanf("%lf", &num1);
            printf("Ingrese el segundo numero: ");
            scanf("%lf", &num2);

            switch (op)
            {
            case 1: //este no devuelve nada
                system("cls");
                sumar(num1, num2);
                system("pause");
                break;
            case 2:
                system("cls");
                restar(num1, num2);
                system("pause");
                break;
            case 3: //este si devuelve y se lo debe guardar el dato en un variable y hacer el print aparte
                system("cls");
                resultado = multiplicar(num1, num2);
                printf("El resultado de la multiplicacion es: %.2lf\n", resultado);
                system("pause");
                break;
            case 4:
                system("cls");
                resultado = dividir(num1, num2);
                printf("El resultado de la division es: %.2lf\n", resultado);
                system("pause");
                break;
            
            default:
                break;
            }
        }
        else if (op == 5)
        {
            printf("Saliendo del sistema...\n"); //es casi lo mismo que el default
        }
        else
        {
            printf("Opcion incorrecta...\n");
        }

    } while (op != 5);
    
    return 0;
}