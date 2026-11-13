#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//variables globales
//cuando declaramos globales podemos declarar toda funcion como void

#define MAX 5

char nombres [MAX][50];
direcciones [MAX][50];
int edades [MAX];
int contadorpersonas = 0;
//Nombres, direcciones y edades
//O Juan    Norte    20
//1 Pedro   Centro   30

/*char nombre [5][30]; //%s
int edad[5]; 
char nom;
float promedio;                          3,141516321354
double variable 1; //%lf                 3,141516321354687986546513213215465879*/

//prototipos de funciones
void resgitro_personal(char nombres[MAX][50], char direcciones [MAX][50], int edades [MAX]);
void mostrar_informacion();
void promedio_edades();
void persona_mas_joven();

int main()
{
    //variables locales
    int op;

     system("cls");
        printf("========== Menu de Opciones ==========\n");
        printf("1.- Registro del Personal\n");
        printf("2.- Mostrar informacion\n");
        printf("3.- Promedio de edades\n");
        printf("4.- Persona mas joven ingresada\n");
        printf("5.- Salir\n");
        printf("Ingrese una opcion entre 1-5: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            system("cls");

            system("pause");
            break;

           case 2:
            system("cls");

            system("pause");
            break;

            case 3:
            system("cls");

            system("pause");
            break;

            case 4:
            system("cls");

            system("pause");
            break;

            case 5:
            system("cls");

            system("pause");
            break;
        
        default:
            break;
        }

    return 0;
}

void registro_personal(char nombres[MAX][50], char direcciones [MAX][50], int edades [MAX])
{
    if (contadorpersonas < MAX)
    {
        printf
        scanf
        printf
        scanf
        printf
        scanf
        contadorpersonas++;
    }
    else
    {
        printf
    }
}

void mostrar_informacion(char nombres[MAX][50], char direcciones[])

if (condition)
{
    printf
    return; //para que termine aqui el proceso y ya regrese el resultado a la funcion.
}


void promedio_edades (int edades[MAX])