//Calculadora de dos numeros

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//variables globales

//prototipos de funciones
void resta(float a, float b) //como es void no retorna dato (declarar como parametros, recepta informacion del num1 y num 2) son un puente
{
    system("cls");
    printf("El resultado de la resta es: %.2f ", (a-b));  //el print va a calcular nada      
    system("pause");
}

//funciones
float suma(float a, float b)
{
    return a+b; //regresa el resultado de la suma
}

int main()
{
    //variables locales
    int op;
    float num1, num2, resultado;

    do
    {
        printf("========== Calculadora ==========\n");
        printf("1.- Suma\n");
        printf("2.- Resta\n");
        printf("3.- Salir\n");
        printf("Ingrese una opcion entre 1-3: ");
        scanf("%d", &op);

        printf("Ingrese el primer numero: ");
        scanf("%f", &num1);
        printf("Ingrese el segundo numero: ");
        scanf("%f", &num2);

        switch (op)
        {
        case 1:
            system("cls");
            resultado = suma(num1, num2); //llamar a la funcion suma
            printf("El resultado de la suma es: %.2f ", resultado);
            system("pause");
            break;

        case 2:
            system("cls");
            resta(num1, num2);
            system("pause");
            break;

        case 3:
            system("cls");
            
            system("pause");
            break;
        
        default:
            break;
        }


    } while (op!=3); //haz el menu mientras no seas la opcion 3
    
    

    return 0;
}