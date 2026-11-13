// Examen Progreso 1
// Kathleen Bustos
// 21 de octubre de 2026

/*Indicación
   Desarrolle el programa en lenguaje C utilizando stdio.h, stdlib.h y string.h, funciones, matrices,
   vectores, estructuras de control y un menú repetitivo.   Trabaje con un máximo de 5 pasajeros.
   Use matrices para nombres y destinos; use vectores para distancia y valor del pasaje.
   Todos los viajes se realizarán en bus.
   Valide que la distancia y el valor del pasaje sean mayores que cero.
   Limpie la pantalla al iniciar el menú y después de seleccionar cada opción.
   Utilice una pausa antes de volver al menú.  */

   /*Problema   
   Una empresa de transporte desea registrar los viajes de sus pasajeros. Todos los viajes se realizarán en bus. 
   Para cada viaje se debe almacenar el nombre del pasajero, el destino, la distancia recorrida y el valor pagado. 
   El programa debe registrar hasta 5 pasajeros, mostrar la información, mostrar la distancia promedio recorrida, 
   identificar los dos viajes de mayor distancia y calcular la recaudación total.   
   El menú debe incluir: registrar viajes, mostrar viajes, distancia promedio de viajes, mostrar los dos viajes más largos, 
   mostrar recaudación total, clasificar las rutas y salir.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

// Prototipos
int registrarPasajero(char nombres[][50], char destinos[][50], float distancia[], float valor[], int cantidad);
void mostrarViajes(char nombres[][50], char destinos[][50], float distancia[], float valor[], int cantidad);
int distanciapromedioviajes(float distancia[], int cantidad);
void viajesmaslargosycortos(char nombres[][50], float distancia[], int cantidad);
void mostrarRecaudacionTotal(float valor[], int cantidad);
void clasificarRutas(char destinos[][50], float distancia[], int cantidad);
float calculodistanciatotal(float distancia[], int cantidad);

int main()
{
    char nombres[MAX][50];
    char destinos[MAX][50];
    float distancia[MAX];
    float valor[MAX];
    int cantidad = 0;
    int op;
    float distanciapromedio = 0;

    do
    {
        system("cls");
        printf("\n===== Sistema de Registro de Viajes =====\n");
        printf("1.- Registrar pasajero\n");
        printf("2.- Mostrar viajes\n");
        printf("3.- Distancia promedio de viajes\n");
        printf("4.- Mostrar el viaje mas largo y el viaje mas corto\n");
        printf("5.- Mostrar recaudacion total\n");
        printf("6.- Clasificar las rutas\n");
        printf("7.- Salir\n");
        printf("Ingrese una opcion entre 1-7: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1: // esta ya esta
            cantidad = registrarPasajero(nombres, destinos, distancia, valor, cantidad);
            break;

        case 2: // este tambien
            mostrarViajes(nombres, destinos, distancia, valor, cantidad);
            break;

        case 3:
            distanciapromedio = distanciapromedioviajes(distancia, cantidad);
            break;

        case 4:
            viajesmaslargosycortos(nombres, distancia, cantidad);
            break;

        case 5: // este ya esta
            mostrarRecaudacionTotal(valor, cantidad);
            break;

        case 6: // este ya esta
            clasificarRutas(destinos, distancia, cantidad);
            break;

        case 7:
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

// Funciones

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

        do
        {
            printf("Ingrese la distancia recorrida (en km, mayor a 0): ");
            scanf("%f", &distancia[cantidad]);
            if (distancia[cantidad] <= 0)
            {
                printf("\nError: La distancia debe ser mayor que cero.\n");
            }
        } while (distancia[cantidad] <= 0);

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

void mostrarViajes(char nombres[][50], char destinos[][50], float distancia[], float valor[], int cantidad)
{
    int i;
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

int distanciapromedioviajes(float distancia[], int cantidad)
{
    int i;
    float distanciatotal = 0;
    float distanciapromedio = 0;
    system("cls");

    if (cantidad == 0)
    {
        printf("Aun no hay distancias de viaje registradas.\n");
    }
    else
    {
        distanciatotal = calculodistanciatotal(distancia, cantidad);
        distanciapromedio = distanciatotal / cantidad;

        printf("La distancia promedio de todos los viajes es %.2f. \n", distanciapromedio);
    }

    system("pause");
    return distanciapromedio;
}

void viajesmaslargosycortos(char nombres[][50], float distancia[], int cantidad)
{
    int i;
    float maxDist;
    float minDist;
    char pasajeromax[50];
    char pasajeromin[50];

    system("cls");

    if (cantidad == 0)
    {
        printf("No hay viajes registrados para comparar.\n");
    }
    else
    {
        maxDist = distancia[0];
        minDist = distancia[0];
        strcpy(pasajeromax, nombres[0]);
        strcpy(pasajeromin, nombres[0]);

        for (i = 1; i < cantidad; i++)
        {
            if (distancia[i] > maxDist)
            {
                maxDist = distancia[i];
                strcpy(pasajeromax, nombres[i]);
            }
            if (distancia[i] < minDist)
            {
                minDist = distancia[i];
                strcpy(pasajeromin, nombres[i]);
            }
        }

        printf("=== Comparacion de Distancias ===\n");
        printf("Viaje mas largo: Pasajero %s con %.2f km\n", pasajeromax, maxDist);
        printf("Viaje mas corto: Pasajero %s con %.2f km\n", pasajeromin, minDist);
    }

    system("pause");
}

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
            total += valor[i];
        }
        printf("La recaudacion total acumulada es: $%.2f\n", total);
    }

    system("pause");
}

void clasificarRutas(char destinos[][50], float distancia[], int cantidad)
{
    int i;
    char tipoRuta[10];

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
            if (distancia[i] <= 5)
            {
                strcpy(tipoRuta, "CORTA");
            }
            else if (distancia[i] <= 20)
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

float calculodistanciatotal(float distancia[], int cantidad)
{
    int i;
    float distanciatotal = 0;

    for (i = 0; i < cantidad; i++)
    {
        distanciatotal = distanciatotal + distancia[i];
    }
    return distanciatotal;
}