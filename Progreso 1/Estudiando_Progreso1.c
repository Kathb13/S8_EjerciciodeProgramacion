/*Indicación
   Desarrolle el programa en lenguaje C utilizando stdio.h, stdlib.h y string.h, funciones, matrices,
   vectores, estructuras de control y un menú repetitivo.   Trabaje con un máximo de 5 pasajeros.
   Use matrices para nombres y destinos; use vectores para distancia y valor del pasaje.
   Todos los viajes se realizarán en bus.
   Valide que la distancia y el valor del pasaje sean mayores que cero.
   Limpie la pantalla al iniciar el menú y después de seleccionar cada opción.
   Utilice una pausa antes de volver al menú.  */

/*Problema
Una empresa de transporte desea registrar los viajes de sus pasajeros.
Todos los viajes se realizarán en bus. Para cada viaje se debe almacenar el nombre del pasajero,
el destino, la distancia recorrida y el valor pagado. El programa debe registrar hasta 5 pasajeros,
mostrar la información, buscar un pasajero por nombre, identificar el viaje de mayor y menor
distancia y calcular la recaudación total.
El menú debe incluir: registrar pasajero, mostrar viajes, buscar por nombre, mostrar viaje más
largo y más corto, mostrar recaudación total, clasificar las rutas y salir.
La búsqueda por nombre debe utilizar comparación de cadenas con strcmp.
Clasifique las rutas como corta si la distancia es menor o igual a 10 km, media si está entre 11 y 30 km
y larga si es mayor a 30 km.   Cada operación importante debe [ser una] función independiente.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

// Prototipos de funciones
int registrarPasajero(char nombres[][50], char destinos[][50], float distancia[], float valor[], int cantidad);
void mostrarViajes(char nombres[][50], char destinos[][50], float distancia[], float valor[], int cantidad);
void buscarPorNombre(char nombres[][50], char destinos[][50], float distancia[], float valor[], int cantidad);
void viajeMasLargoYCorto(char nombres[][50], float distancia[], int cantidad);
void mostrarRecaudacionTotal(float valor[], int cantidad);
void clasificarRutas(char destinos[][50], float distancia[], int cantidad);

int main()
{
    // Matrices para nombres y destinos, vectores para distancia y valor
    char nombres[MAX][50];
    char destinos[MAX][50];
    float distancia[MAX];
    float valor[MAX];

    int cantidad = 0;
    int op;

    do
    {
        system("cls");
        printf("\n===== Sistema de Registro de Viajes =====\n");
        printf("1.- Registrar pasajero\n");
        printf("2.- Mostrar viajes\n");
        printf("3.- Buscar por nombre\n");
        printf("4.- Mostrar viaje mas largo y mas corto\n");
        printf("5.- Mostrar recaudacion total\n");
        printf("6.- Clasificar las rutas\n");
        printf("7.- Salir\n");
        printf("Ingrese una opcion entre 1-7: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            cantidad = registrarPasajero(nombres, destinos, distancia, valor, cantidad);
            break;

        case 2:
            mostrarViajes(nombres, destinos, distancia, valor, cantidad);
            break;

        case 3:
            buscarPorNombre(nombres, destinos, distancia, valor, cantidad);
            break;

        case 4:
            viajeMasLargoYCorto(nombres, distancia, cantidad);
            break;

        case 5:
            mostrarRecaudacionTotal(valor, cantidad);
            break;

        case 6:
            clasificarRutas(destinos, distancia, cantidad);
            break;

        case 7:
            printf("\nSaliendo del programa...\n");
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

// FUNCIONES

// 1. Registrar Pasajero con validacion > 0
int registrarPasajero(char nombres[][50], char destinos[][50], float distancia[], float valor[], int cantidad)
{
    system("cls");

    if (cantidad < MAX)
    {
        printf("=== Registro de Pasajero %d ===\n", cantidad + 1);

        printf("Ingrese el nombre del pasajero: ");
        scanf(" %[^\n]", nombres[cantidad]);

        printf("Ingrese el destino: ");
        scanf(" %[^\n]", destinos[cantidad]);

        // Validacion de distancia > 0
        do
        {
            printf("Ingrese la distancia recorrida (en km, mayor a 0): ");
            scanf("%f", &distancia[cantidad]);
            if (distancia[cantidad] <= 0)
            {
                printf("\nError: La distancia debe ser mayor que cero.\n");
            }
        } while (distancia[cantidad] <= 0);

        // Validacion de valor del pasaje > 0
        do
        {
            printf("Ingrese el valor del pasaje ($USD, mayor a 0): ");
            scanf("%f", &valor[cantidad]);
            if (valor[cantidad] <= 0)
            {
                printf("\nError: El valor del pasaje debe ser mayor que cero.\n");
            }
        } while (valor[cantidad] <= 0);

        cantidad++;
        printf("\nPasajero registrado exitosamente en bus.\n");
    }
    else
    {
        printf("No hay espacio para mas de 5 pasajeros.\n");
    }

    system("pause");
    return cantidad;
}

// 2. Mostrar todos los viajes
void mostrarViajes(char nombres[][50], char destinos[][50], float distancia[], float valor[], int cantidad)
{
    int i; //coordenada de filas
    system("cls");

    if (cantidad == 0)
    {
        printf("Aun no hay viajes registrados.\n");
    }
    else
    {
        printf("=== Lista de Viajes Registrados (Bus) ===\n\n");
        for (i = 0; i < cantidad; i++)
        {
            printf("Pasajero %d:\n", i + 1);
            printf("  Nombre: %s\n", nombres[i]);
            printf("  Destino: %s\n", destinos[i]);
            printf("  Distancia: %.2f km\n", distancia[i]);
            printf("  Valor pagado: $%.2f\n", valor[i]);
            printf("----------------------------------------\n");
        }
    }

    system("pause");
}

// 3. Buscar por nombre utilizando strcmp
void buscarPorNombre(char nombres[][50], char destinos[][50], float distancia[], float valor[], int cantidad)
{
    char buscar[50];
    int encontrado = 0;
    int i;

    system("cls");

    if (cantidad == 0)
    {
        printf("No hay viajes registrados para buscar.\n");
    }
    else
    {
        printf("Ingrese el nombre del pasajero a buscar: ");
        scanf(" %[^\n]", buscar);

        for (i = 0; i < cantidad; i++)
        {
            if (strcmp(nombres[i], buscar) == 0) //0 significa que los dos son iguales
            {
                printf("\n--- Pasajero Encontrado ---\n");
                printf("Nombre: %s\n", nombres[i]);
                printf("Destino: %s\n", destinos[i]);
                printf("Distancia: %.2f km\n", distancia[i]);
                printf("Valor del pasaje: $%.2f\n", valor[i]);
                encontrado = 1;
                break;
            }
        }

        if (encontrado == 0) //falso es cero
        {
            printf("\nPasajero no encontrado.\n");
        }
    }

    system("pause");
}

// 4. Viaje mas largo y mas corto
void viajeMasLargoYCorto(char nombres[][50], float distancia[], int cantidad)
{
    int i;
    float maxDist;
    float minDist;
    char pasMax[50];
    char pasMin[50];

    system("cls");

    if (cantidad == 0)
    {
        printf("No hay viajes registrados para comparar.\n");
    }
    else
    {
        maxDist = distancia[0];
        minDist = distancia[0];
        strcpy(pasMax, nombres[0]); //pasajero maxima distancia
        strcpy(pasMin, nombres[0]);

        for (i = 1; i < cantidad; i++)
        {
            if (distancia[i] > maxDist)
            {
                maxDist = distancia[i];
                strcpy(pasMax, nombres[i]);
            }
            if (distancia[i] < minDist)
            {
                minDist = distancia[i];
                strcpy(pasMin, nombres[i]);
            }
        }

        printf("=== Comparacion de Distancias ===\n");
        printf("Viaje mas largo: Pasajero %s con %.2f km\n", pasMax, maxDist);
        printf("Viaje mas corto: Pasajero %s con %.2f km\n", pasMin, minDist);
    }

    system("pause");
}

// 5. Mostrar recaudacion total
void mostrarRecaudacionTotal(float valor[], int cantidad)
{
    int i;
    float total = 0;

    system("cls");

    if (cantidad == 0)
    {
        printf("Aun no hay cobros registrados.\n");
    }
    else
    {
        for (i = 0; i < cantidad; i++)
        {
            total += valor[i]; //total = total + valor[i]
        }
        printf("La recaudacion total acumulada es: $%.2f\n", total);
    }

    system("pause");
}

// 6. Clasificar rutas (Corta <= 10 km, Media 11-30 km, Larga > 30 km)
void clasificarRutas(char destinos[][50], float distancia[], int cantidad)
{
    int i;
    char tipoRuta[10]; // Variable para guardar el texto ("CORTA", "MEDIA" o "LARGA")

    system("cls");

    if (cantidad == 0)
    {
        printf("No hay rutas registradas para clasificar.\n");
    }
    else
    {
        printf("=== Clasificacion de Rutas ===\n\n");
        for (i = 0; i < cantidad; i++)
        {
            // Primero determinamos el texto según la distancia
            if (distancia[i] <= 10)
            {
                strcpy(tipoRuta, "CORTA"); //tipoRuta = Corta
            }
            else if (distancia[i] <= 30) //en ifs anidados tengo que poner puro else if hasta el final solo else
            {
                strcpy(tipoRuta, "MEDIA");
            }
            else
            {
                strcpy(tipoRuta, "LARGA");
            }

            printf("Destino: %s (%.2f km) -> Ruta %s\n", destinos[i], distancia[i], tipoRuta);
        }
    }

    system("pause");
}
