/*
Realizar un programa que permita almacenar 5 productos de una empresa en el cual almacene la siguiente informacion
nombre del producto, descripcion, stock y precio. El programa debe realizar los siguientes procesos:

1. Ingresar productos
2. Mostrar productos
3. Buscar productos
4. Producto mas barato y caro
5. Promedio de precios
6. Salir
*/

 /* deber aumentar la opcion de ordenar en forma albabeticamente (strcmp) un submenu
    1. A-Z
    2. Z-A
    3. Regresar*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

// Variables globales
char nombre[MAX][50]; // puedo guardar n numero de usuarios, dependiendo del limite de la memoria de la compu
char descripcion[MAX][50];
int stock[MAX];
float precio[MAX];
int conteodeproductos = 0;
char aux[MAX];

// Funciones
void titulo(void) // el void inicial es para el tipo de funcion y el otro es para los parametros que no se necesitan
{
    printf("Programa de productos...\n");
}

// Prototipos
void ingresarproductos(char nombre[MAX][50], char descripcion[MAX][50], int stock[MAX], float precio[MAX]);
void mostrarproductos(char nombre[MAX][50], char descripcion[MAX][50], int stock[MAX], float precio[MAX]);
void buscarproductos(char nombre[MAX][50], int stock[MAX], float precio[MAX]);
void productomasbaratoymascaro(char nombre[MAX][50], float precio[MAX]);
void promedioprecios(float precio[MAX]);
void ordenarAZ(char nombre[MAX][50], char aux[MAX], int conteodeproductos);
void ordenarZA(char nombre[MAX][50], char aux[MAX], int conteodeproductos);

int main()
{
    int op;
    int op2;

    do
    {
        system("cls");
        printf("===== Sistema de Registro de Productos =====\n");
        printf("1.- Ingresar productos\n");
        printf("2.- Mostrar productos\n");
        printf("3.- Buscar productos\n");
        printf("4.- Producto mas barato y mas caro\n");
        printf("5.- Promedio productos\n");
        printf("6.- Ordenar alfabeticamente\n");
        printf("7.- Salir\n");
        printf("Ingrese una opcion entre 1-7: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            system("cls");
            ingresarproductos(nombre, descripcion, stock, precio);
            system("pause");
            break;
        case 2:
            system("cls");
            mostrarproductos(nombre, descripcion, stock, precio);
            system("pause");
            break;
        case 3:
            system("cls");
            buscarproductos(nombre, stock, precio);
            system("pause");
            break;
        case 4:
            system("cls");
            productomasbaratoymascaro(nombre, precio);
            system("pause");
            break;
        case 5:
            system("cls");
            promedioprecios(precio);
            system("pause");
            break;
        case 6:
            do
            {
                system("cls");
                printf("1.- Ordenar de la A-Z\n");
                printf("2.- Ordenar de la Z-A\n");
                printf("3.- Regresar al menu principal\n");
                scanf("%d", &op2);

                switch (op2)
                {
                case 1:
                    system("cls");
                    ordenarAZ(nombre, aux, conteodeproductos);
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    ordenarZA(nombre, aux, conteodeproductos);
                    system("pause");
                    break;
                case 3:
                    break;
                default:
                    system("cls");
                    printf("Opcion invalida, intente de nuevo.\n");
                    system("pause");
                    break;
                }
            } while (op2 != 3);
            break;

        case 7:
            system("cls");
            printf("\nSaliendo del programa...\n");
            system("pause");
            break;

        default:
            system("cls");
            printf("\nOpcion invalida, intente de nuevo.\n");
            system("pause");
            break;
        }
    } while (op != 7);

    return 0;
}

void ingresarproductos(char nombre[MAX][50], char descripcion[MAX][50], int stock[MAX], float precio[MAX])
{
    if (conteodeproductos < MAX)
    {
        printf("Ingresa el nombre del producto...\n");
        scanf(" %[^\n]", nombre[conteodeproductos]);
        printf("Ingresa la descripcion del producto...\n");
        scanf(" %[^\n]", descripcion[conteodeproductos]);
        printf("Ingresa el stock del producto...\n");
        scanf(" %d", &stock[conteodeproductos]);
        printf("Ingresa el precio del producto...\n");
        scanf(" %f", &precio[conteodeproductos]);
        conteodeproductos++;
        // conteodeproductos = conteodeproductos +1
    }
    else
    {
        printf("No hay mas espacio para productos\n");
    }
}
void mostrarproductos(char nombre[MAX][50], char descripcion[MAX][50], int stock[MAX], float precio[MAX])
{
    if (conteodeproductos == 0)
    {
        printf("No hay productos registrados...\n");
        return;
    }

    printf("#   Nombre |    Descripcion    |    Stock   |   Precio\n");
    for (int i = 0; i < conteodeproductos; i++)
    {
        printf("%d   %s |    %s    |    %d   |   %.2f\n", i + 1, nombre[i], descripcion[i], stock[i], precio[i]);
    }
}
void buscarproductos(char nombre[MAX][50], int stock[MAX], float precio[MAX])
{
    char nombrebuscado[50];
    int encontrar = 0;

    if (conteodeproductos == 0)
    {
        printf("No hay productos registrados...");
        return;
    }
    printf("Ingrese un producto a buscar: ");
    scanf(" %[^\n]", nombrebuscado);

    for (int i = 0; i < conteodeproductos; i++)
    {
        if (strcmp(nombre[i], nombrebuscado) == 0)
        {
            printf("El producto encontrado es: Nombre %s | Stock: %d | Precio: %.2f\n", nombre[i], stock[i], precio[i]);
            encontrar = 1;
            break;
        }
    }
    if (encontrar == 0)
    {
        printf("Dato no existen\n");
    }
}

void productomasbaratoymascaro(char nombre[MAX][50], float precio[MAX])
{
    int productobarato = 0;
    int productocaro = 0;

    if (conteodeproductos == 0)
    {
        printf("No hay productos registrados...");
        return;
    }
    for (int i = 1; i < conteodeproductos; i++)
    {
        if (precio[i] > precio[productocaro])
        {
            productocaro = i;
        }
        if (precio[i] < precio[productobarato])
        {
            productobarato = i;
        }
    }
    printf("El producto mas caro es: %s - $%.2f\n", nombre[productocaro], precio[productocaro]);
    printf("El producto mas barato es: %s - $%.2f\n", nombre[productobarato], precio[productobarato]);
}
void promedioprecios(float precio[MAX])
{
    float suma = 0;

    if (conteodeproductos == 0)
    {
        printf("No hay productos registrados...");
        return;
    }
    for (int i = 0; i < conteodeproductos; i++)
    {
        suma += precio[i];
    }
    printf("El promedio de precio es: $%.2f\n", suma / conteodeproductos);
}

void ordenarAZ(char nombre[MAX][50], char aux[MAX], int conteodeproductos)
{
    for (int i = 0; i < conteodeproductos; i++)
    {
        for (int j = 0; j < conteodeproductos ; j++)
        {

            if (strcmp(nombre[j], nombre[j + 1]) > 0)
            {
                strcpy(aux, nombre[j + 1]);
                strcpy(nombre[j + 1], nombre[j]);
                strcpy(nombre[j], aux);
            }
        }
    }
    printf("\nProductos ordenados exitosamente:\n");
    for (int i = 0; i <= conteodeproductos; i++)
    {
        printf("%s\n", nombre[i]);
    }
}

void ordenarZA(char nombre[MAX][50], char aux[MAX], int conteodeproductos)
{
    for (int i = 0; i < conteodeproductos; i++)
    {
        for (int j = 0; j < conteodeproductos ; j++)
        {

            if (strcmp(nombre[j], nombre[j + 1]) < 0)
            {
                strcpy(aux, nombre[j + 1]);
                strcpy(nombre[j + 1], nombre[j]);
                strcpy(nombre[j], aux);
            }
        }
    }
    printf("\nProductos ordenados exitosamente:\n");
    for (int i = 0; i <= conteodeproductos; i++)
    {
        printf("%s\n", nombre[i]);
    }
}

   