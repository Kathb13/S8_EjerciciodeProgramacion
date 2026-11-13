// S8 - Ejercicio de Programación
// Integrantes: Kathleen Bustos, Scarleth Farías y Samantha Soxo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

// Prototipos de funciones
void ingresarProducto(char nombres[MAX][50], float *tiempoUnitario, float *recursoUnitario, int *cantidadDemandada, int *totalProductos);
void mostrarProductos(char nombres[MAX][50], float *tiempoUnitario, float *recursoUnitario, int *cantidadDemandada, int totalProductos);
int buscarProducto(char nombres[MAX][50], int totalProductos, char nombreBuscado[50]);
void editarProducto(char nombres[MAX][50], float *tiempoUnitario, float *recursoUnitario, int *cantidadDemandada, int totalProductos);
void eliminarProducto(char nombres[MAX][50], float *tiempoUnitario, float *recursoUnitario, int *cantidadDemandada, int *totalProductos);
void calcularProduccion(float *tiempoUnitario, float *recursoUnitario, int *cantidadDemandada, int totalProductos);

int main()
{

    char nombres[MAX][50];
    float tiempoUnitario[MAX];
    float recursoUnitario[MAX];
    int cantidadDemandada[MAX];

    int totalProductos = 0;
    int op;

    system("cls");
    do
    {
        printf("===== OPTIMIZACION DE PRODUCCION - FABRICA ELECTRONICA =====\n");
        printf("1.- Ingresar producto\n");
        printf("2.- Mostrar productos registrados\n");
        printf("3.- Editar producto\n");
        printf("4.- Eliminar producto\n");
        printf("5.- Calcular tiempo, recursos y viabilidad\n");
        printf("6.- Salir\n");
        printf("Ingrese una opcion (1-6): ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            system("cls");
            ingresarProducto(nombres, tiempoUnitario, recursoUnitario, cantidadDemandada, &totalProductos);
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            mostrarProductos(nombres, tiempoUnitario, recursoUnitario, cantidadDemandada, totalProductos);
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            editarProducto(nombres, tiempoUnitario, recursoUnitario, cantidadDemandada, totalProductos);
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            eliminarProducto(nombres, tiempoUnitario, recursoUnitario, cantidadDemandada, &totalProductos);
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            calcularProduccion(tiempoUnitario, recursoUnitario, cantidadDemandada, totalProductos);
            system("pause");
            system("cls");
            break;
        case 6:
            system("cls");
            printf("Saliendo del sistema...\n");
            break;
        default:
            system("cls");
            printf("Opcion invalida, vuelva a ingresar un numero del 1 al 6.\n\n");
            system("pause");
            system("cls");
            break;
        }
    } while (op != 6);

    return 0;
}

// FUNCIONES
// 1. Ingresar un nuevo producto
void ingresarProducto(char nombres[MAX][50], float *tiempoUnitario, float *recursoUnitario, int *cantidadDemandada, int *totalProductos)
{
    if (*totalProductos < MAX)
    {
        int posicion = *totalProductos;
        char nombreValidacion[50];
        int encontrado = 0;

        printf("--- INGRESO DE PRODUCTO %d ---\n", posicion + 1);
        printf("Nombre del producto: ");
        scanf(" %[^\n]", nombreValidacion);

        // Validacion de que no exista otro producto con el mismo nombre
        for (int f = 0; f < *totalProductos; f++)
        {
            if (strcmp(nombres[f], nombreValidacion) == 0)
            {
                encontrado = 1;
                break;
            }
        }

        if (encontrado == 1)
        {
            printf("\nError: Ya existe un producto con ese nombre.\n");
            return;
        }

        strcpy(nombres[posicion], nombreValidacion);

        do
        {
            printf("Tiempo de fabricacion por unidad (horas): ");
            scanf("%f", (tiempoUnitario + posicion));
            if (*(tiempoUnitario + posicion) <= 0)
            {
                printf("Error: El tiempo debe ser mayor a 0.\n");
            }
        } while (*(tiempoUnitario + posicion) <= 0);

        do
        {
            printf("Recursos necesarios por unidad en dolares ($): ");
            scanf("%f", (recursoUnitario + posicion));
            if (*(recursoUnitario + posicion) <= 0)
            {
                printf("Error: Los recursos deben ser mayor a 0.\n");
            }
        } while (*(recursoUnitario + posicion) <= 0);

        do
        {
            printf("Cantidad demandada (unidades): ");
            scanf("%d", (cantidadDemandada + posicion));
            if (*(cantidadDemandada + posicion) <= 0)
            {
                printf("Error: La cantidad debe ser mayor a 0.\n");
            }
        } while (*(cantidadDemandada + posicion) <= 0);

        (*totalProductos)++;
    }
    else
    {
        printf("No hay espacio para mas productos (%d maximo).\n", MAX);
    }
}

// 2. Mostrar productos ingresados
void mostrarProductos(char nombres[MAX][50], float *tiempoUnitario, float *recursoUnitario, int *cantidadDemandada, int totalProductos)
{
    if (totalProductos == 0)
    {
        printf("No hay productos registrados en el sistema.\n");
        return;
    }

    printf("--- LISTA DE PRODUCTOS ---\n\n");
    for (int f = 0; f < totalProductos; f++)
    {
        printf("%d.- %s\n", f + 1, nombres[f]);
        printf("    Tiempo de fabricacion unitario: %.2f horas\n", *(tiempoUnitario + f));
        printf("    Recursos necesarios unitarios: $%.2f\n", *(recursoUnitario + f));
        printf("    Cantidad demandada: %d unidades\n", *(cantidadDemandada + f));
        printf("----------------------------------------\n");
    }
}

// Función extra para buscar productos
int buscarProducto(char nombres[MAX][50], int totalProductos, char nombreBuscado[50])
{
    int encontrado = 0;
    int posicion = -1;

    for (int f = 0; f < totalProductos; f++)
    {
        if (strcmp(nombres[f], nombreBuscado) == 0)
        {
            encontrado = 1;
            posicion = f;
            break;
        }
    }

    if (encontrado == 1)
    {
        return posicion;
    }
    else
    {
        return -1;
    }
}

// 3. Editar un producto
void editarProducto(char nombres[MAX][50], float *tiempoUnitario, float *recursoUnitario, int *cantidadDemandada, int totalProductos)
{
    if (totalProductos == 0)
    {
        printf("No hay productos para editar.\n");
        return;
    }

    char nombreBuscado[50];
    char nuevoNombre[50];

    printf("Ingrese el nombre exacto del producto a editar: ");
    scanf(" %[^\n]", nombreBuscado);

    int posicion = buscarProducto(nombres, totalProductos, nombreBuscado);

    if (posicion != -1)
    {
        printf("\nProducto encontrado en la posicion %d.\n\n", posicion + 1);

        printf("Ingrese el nuevo nombre: ");
        scanf(" %[^\n]", nuevoNombre);
        strcpy(nombres[posicion], nuevoNombre);

        do
        {
            printf("Nuevo tiempo de fabricacion por unidad (horas): ");
            scanf("%f", (tiempoUnitario + posicion));
            if (*(tiempoUnitario + posicion) <= 0)
            {
                printf("Error: El tiempo debe ser mayor a 0.\n");
            }
        } while (*(tiempoUnitario + posicion) <= 0);

        do
        {
            printf("Nuevos recursos por unidad en dolares ($): ");
            scanf("%f", (recursoUnitario + posicion));
            if (*(recursoUnitario + posicion) <= 0)
            {
                printf("Error: Los recursos deben ser mayor a 0.\n");
            }
        } while (*(recursoUnitario + posicion) <= 0);

        do
        {
            printf("Nueva cantidad demandada (unidades): ");
            scanf("%d", (cantidadDemandada + posicion));
            if (*(cantidadDemandada + posicion) <= 0)
            {
                printf("Error: La cantidad debe ser mayor a 0.\n");
            }
        } while (*(cantidadDemandada + posicion) <= 0);

        printf("\nProducto editado con exito.\n");
    }
    else
    {
        printf("\nProducto no encontrado.\n");
    }
}

// 4. Eliminar un producto
void eliminarProducto(char nombres[MAX][50], float *tiempoUnitario, float *recursoUnitario, int *cantidadDemandada, int *totalProductos)
{
    if (*totalProductos == 0)
    {
        printf("No hay productos para eliminar.\n");
        return;
    }

    char nombreBuscado[50];

    printf("Ingrese el nombre exacto del producto a eliminar: ");
    scanf(" %[^\n]", nombreBuscado);

    int posicion = buscarProducto(nombres, *totalProductos, nombreBuscado);

    if (posicion != -1)
    {
        for (int i = posicion; i < (*totalProductos) - 1; i++)
        {
            strcpy(nombres[i], nombres[i + 1]);
            *(tiempoUnitario + i) = *(tiempoUnitario + i + 1);
            *(recursoUnitario + i) = *(recursoUnitario + i + 1);
            *(cantidadDemandada + i) = *(cantidadDemandada + i + 1);
        }

        (*totalProductos)--;
        printf("\nProducto eliminado con exito.\n");
    }
    else
    {
        printf("\nProducto no encontrado.\n");
    }
}

// 5. Calcular tiempo, recursos y verificar la viabilidad
void calcularProduccion(float *tiempoUnitario, float *recursoUnitario, int *cantidadDemandada, int totalProductos)
{
    if (totalProductos == 0)
    {
        printf("No hay productos registrados para calcular ni verificar.\n");
        return;
    }

    float tiempoTotalRequerido = 0;
    float recursosTotalesRequeridos = 0;
    float tiempoDisponible, recursosDisponibles;

    for (int f = 0; f < totalProductos; f++)
    {
        tiempoTotalRequerido += (*(tiempoUnitario + f)) * (*(cantidadDemandada + f));
        recursosTotalesRequeridos += (*(recursoUnitario + f)) * (*(cantidadDemandada + f));
    }

    printf("--- REQUERIMIENTOS DE PRODUCCION ---\n");
    printf("Tiempo total requerido: %.2f horas\n", tiempoTotalRequerido);
    printf("Recursos totales requeridos: $%.2f\n\n", recursosTotalesRequeridos);

    do
    {
        printf("Ingrese el tiempo de produccion disponible en la fabrica (horas): ");
        scanf("%f", &tiempoDisponible);
        if (tiempoDisponible <= 0)
        {
            printf("Error: El tiempo disponible debe ser mayor a 0.\n");
        }
    } while (tiempoDisponible <= 0);

    do
    {
        printf("Ingrese la cantidad de recursos disponibles en la fabrica en dolares ($): ");
        scanf("%f", &recursosDisponibles);
        if (recursosDisponibles <= 0)
        {
            printf("Error: Los recursos disponibles deben ser mayor a 0.\n");
        }
    } while (recursosDisponibles <= 0);

    printf("\n--- RESULTADO DEL ANALISIS ---\n");
    if (tiempoTotalRequerido <= tiempoDisponible && recursosTotalesRequeridos <= recursosDisponibles)
    {
        printf("VIABLE: La fabrica SI puede cumplir con toda la demanda.\n");
    }
    else
    {
        printf("NO VIABLE: La fabrica NO puede cumplir con la demanda.\n");
        if (tiempoTotalRequerido > tiempoDisponible)
        {
            printf("- Faltan %.2f horas de tiempo.\n", tiempoTotalRequerido - tiempoDisponible);
        }
        if (recursosTotalesRequeridos > recursosDisponibles)
        {
            printf("- Faltan $%.2f de recursos.\n", recursosTotalesRequeridos - recursosDisponibles);
        }
    }
}