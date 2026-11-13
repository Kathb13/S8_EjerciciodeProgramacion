// Ejercicio de Programacion S4
// Kathleen Bustos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// variable global
#define MAX 10
int filas;
float preciopromedio;
float preciototal;
char buscarproducto[50];
int encontrado;
float preciomayor;
float preciomenor;
char productoconpreciomayor[50];
char productoconpreciomenor[50];

// prototipos de funciones (o va toda la funcion antes del main o se pone solo el prototipo)
float calculopreciototal(float precio[], int cantidad);
void mostrarpreciodeproducto(int cantidad, char productos[][50], float precio[]);
int ingresarproducto(char productos[][50], float precio[], int cantidad);
void obtenerbaratoycaro(char productos[][50], float precio[], int cantidad);

int main()
{
    // variables locales
    char productos[MAX][50]; // hasta 50 caracteres de nombre de producto
    float precio[MAX];
    int op;
    int cantidad = 0;

    do
    {
        system("cls");
        printf("\n===== Sistema de Inventario =====\n");
        printf("1.- Agregar producto\n");
        printf("2.- Precio total del inventario\n");
        printf("3.- Producto mas caro y mas barato\n");
        printf("4.- Precio promedio de todos los productos\n");
        printf("5.- Mostrar precio de un producto\n");
        printf("6.- Salir \n");
        printf("Ingrese una opcion entre 1-6: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            cantidad = ingresarproducto(productos, precio, cantidad);
            break;

        case 2:
            system("cls");

            preciototal = calculopreciototal(precio, cantidad); // el resultado de la funcion se debe almacenar en una variable del main

            printf("El precio total del inventario es de $%.2f \n", preciototal);
            preciototal = 0; // para que se reinicie en caso de ejecutar el mismo case mas de una vez

            system("pause");
            break;

        case 3:
            obtenerbaratoycaro(productos, precio, cantidad);
            break;

        case 4:
            system("cls");

            if (cantidad == 0)
            {
                printf("Aun no hay productos registrados en el inventario.\n");
            }
            else
            {
            preciototal = calculopreciototal(precio, cantidad); // cuando se llama a la funcion no se necesitan corchetees
            preciopromedio = preciototal / cantidad;
            preciototal = 0;

            printf("El precio promedio de todos los productos del inventario es $%.2f. \n", preciopromedio);
            }

            system("pause");
            break;

        case 5:
            mostrarpreciodeproducto(cantidad, productos, precio);
            break;

        default:
            system("cls");
            printf("Opcion invalida, vuelva a ingresar un numero del 1 al 6.\n\n");
            system("pause");
            break;
        }

    } while (op != 6);

    return 0;
}

// funciones

float calculopreciototal(float precio[], int cantidad)
{
    preciototal = 0;

    for (filas = 0; filas < cantidad; filas++)
    {
        preciototal = preciototal + precio[filas];
    }
    return preciototal;
}

void mostrarpreciodeproducto(int cantidad, char productos[][50], float precio[])
{
    system("cls");

    printf("Ingrese el producto que desea mostrar el precio: ");
    scanf(" %[^\n]", buscarproducto);
    encontrado = 0;
    for (filas = 0; filas < cantidad; filas++)
    {
        if (strcmp(productos[filas], buscarproducto) == 0)
        {
            printf("El precio del producto %s es $%.2f \n", productos[filas], precio[filas]);
            encontrado = 1;
            break;
        }
    }
    if (encontrado == 0)
    {
        printf("Producto no encontrado\n");
    }
    system("pause");
}

int ingresarproducto(char productos[][50], float precio[], int cantidad)
{
    system("cls");
    if (cantidad < MAX)
    {
        printf("\nIngrese el nombre del producto: ");
        scanf(" %[^\n]", productos[cantidad]); // no se usa & solo cuando son vectores/arreglos de cadenas de caracteres

        printf("\nIngrese el precio del producto: ");
        scanf(" %f", &precio[cantidad]);

        cantidad++;
    }
    else
    {
        printf("No hay espacio para mas productos..");
    }
    printf("\n");
    system("pause");

    return cantidad;
}

void obtenerbaratoycaro(char productos[][50], float precio[], int cantidad)
{
    system("cls");

    if (cantidad == 0)
    {
        printf("No hay productos registrados para comparar.\n");
    }
    else
    {
        preciomenor = precio[0]; // inicializar con el primer precio
        preciomayor = precio[0];
        strcpy(productoconpreciomayor, productos[0]);
        strcpy(productoconpreciomenor, productos[0]);

        // ahora el for inicia en 1 porque ya no necesitamos comparar con la posicion 0 ya que se la inicializo arriba
        for (filas = 1; filas < cantidad; filas++) // para recorrer posiciones
        {
            if (preciomayor < precio[filas])
            {
                preciomayor = precio[filas];
                strcpy(productoconpreciomayor, productos[filas]);
            }
            if (preciomenor > precio[filas])
            {
                preciomenor = precio[filas];
                strcpy(productoconpreciomenor, productos[filas]);
            }
        }

        printf("El producto mas caro es %s con un precio de $%.2f.\n", productoconpreciomayor, preciomayor);
        printf("El producto mas barato es %s con un precio de $%.2f.\n", productoconpreciomenor, preciomenor);
    }

    system("pause");
}