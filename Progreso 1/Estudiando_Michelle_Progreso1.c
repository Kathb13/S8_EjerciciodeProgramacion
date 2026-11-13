#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

// Prototipos de funciones
int registrarLibro(char titulo[][50], char autor[][50], char genero[][50], int anio[], int estado[], int cantidad);
void mostrarLibros(char titulo[][50], char autor[][50], char genero[][50], int anio[], int estado[], int cantidad);
void editarAnioYEstado(char titulo[][50], int anio[], int estado[], int cantidad);
void buscarPorTitulo(char titulo[][50], char autor[][50], char genero[][50], int anio[], int estado[], int cantidad);
void libroMasAntiguoYReciente(char titulo[][50], int anio[], int cantidad);
void resumenPrestamos(int estado[], int cantidad);
void mostrarClasificacionPorEstado(char titulo[][50], int estado[], int cantidad);

int main()
{
    // Matrices para texto (titulo, autor, genero) y vectores para numeros (anio, estado)
    char titulo[MAX][50];
    char autor[MAX][50];
    char genero[MAX][50];
    int anio[MAX];
    int estado[MAX]; // 0: Disponible, 1: Prestado

    int cantidad = 0;
    int op;

    do
    {
        system("cls");
        printf("========== Sistema de Biblioteca ==========\n");
        printf("1.- Registrar libro\n");
        printf("2.- Mostrar libros\n");
        printf("3.- Editar anio y estado de un libro\n");
        printf("4.- Buscar por titulo\n");
        printf("5.- Mostrar libro mas antiguo y mas reciente\n");
        printf("6.- Mostrar resumen de prestamos\n");
        printf("7.- Mostrar clasificacion por estado\n");
        printf("8.- Salir\n");
        printf("Ingrese una opcion entre 1-8: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            cantidad = registrarLibro(titulo, autor, genero, anio, estado, cantidad);
            break;

        case 2:
            mostrarLibros(titulo, autor, genero, anio, estado, cantidad);
            break;

        case 3:
            editarAnioYEstado(titulo, anio, estado, cantidad);
            break;

        case 4:
            buscarPorTitulo(titulo, autor, genero, anio, estado, cantidad);
            break;

        case 5:
            libroMasAntiguoYReciente(titulo, anio, cantidad);
            break;

        case 6:
            resumenPrestamos(estado, cantidad);
            break;

        case 7:
            mostrarClasificacionPorEstado(titulo, estado, cantidad);
            break;

        case 8:
            printf("\nSaliendo del programa...\n");
            break;

        default:
            printf("\nOpcion invalida, intente de nuevo.\n");
            system("pause");
            break;
        }

    } while (op != 8);

    return 0;
}

// FUNCIONES

// 1. Registrar Libro
int registrarLibro(char titulo[][50], char autor[][50], char genero[][50], int anio[], int estado[], int cantidad)
{
    system("cls");

    if (cantidad < MAX)
    {
        printf("=== Registro de Libro %d ===\n", cantidad + 1);

        printf("Ingrese el titulo del libro: ");
        scanf(" %[^\n]", titulo[cantidad]);

        printf("Ingrese el autor del libro: ");
        scanf(" %[^\n]", autor[cantidad]);

        printf("Ingrese el genero del libro: ");
        scanf(" %[^\n]", genero[cantidad]);

        // Validacion de anio positivo (> 0)
        do
        {
            printf("Ingrese el anio de publicacion (mayor a 0): ");
            scanf("%d", &anio[cantidad]);
            if (anio[cantidad] <= 0)
            {
                printf("Error: El anio debe ser un numero positivo.\n");
            }
        } while (anio[cantidad] <= 0);

        // Validacion de estado (0 o 1)
        do
        {
            printf("Ingrese el estado del libro (0 para Disponible, 1 para Prestado): ");
            scanf("%d", &estado[cantidad]);
            if (estado[cantidad] != 0 && estado[cantidad] != 1)
            {
                printf("Error: Ingrese solo 0 (Disponible) o 1 (Prestado).\n");
            }
        } while (estado[cantidad] != 0 && estado[cantidad] != 1);

        cantidad++;
        printf("\nLibro registrado exitosamente.\n");
    }
    else
    {
        printf("No hay espacio disponible para mas de 5 libros.\n");
    }

    system("pause");
    return cantidad;
}

// 2. Mostrar todos los libros
void mostrarLibros(char titulo[][50], char autor[][50], char genero[][50], int anio[], int estado[], int cantidad)
{
    int i;
    system("cls");

    if (cantidad == 0)
    {
        printf("No hay libros registrados en la biblioteca.\n");
    }
    else
    {
        printf("=== Lista de Libros Registrados ===\n\n");
        for (i = 0; i < cantidad; i++)
        {
            printf("Libro %d:\n", i + 1);
            printf("  Titulo: %s\n", titulo[i]);
            printf("  Autor: %s\n", autor[i]);
            printf("  Genero: %s\n", genero[i]);
            printf("  Anio de publicacion: %d\n", anio[i]);
            if (estado[i] == 0)
            {
                printf("  Estado: Disponible\n");
            }
            else
            {
                printf("  Estado: Prestado\n");
            }
            printf("----------------------------------------\n");
        }
    }

    system("pause");
}

// 3. Editar anio y estado de un libro (basado en la logica de tu ejemplo de contactos)
void editarAnioYEstado(char titulo[][50], int anio[], int estado[], int cantidad)
{
    char tituloABuscar[50];
    int encontrar = 0;
    int i;

    system("cls");

    if (cantidad == 0)
    {
        printf("No hay libros registrados para editar.\n");
    }
    else
    {
        printf("Ingrese el titulo del libro que desea editar: ");
        scanf(" %[^\n]", tituloABuscar);

        for (i = 0; i < cantidad; i++)
        {
            if (strcmp(titulo[i], tituloABuscar) == 0)
            {
                printf("\nLibro encontrado.\n");

                // Editar anio con validacion
                do
                {
                    printf("Ingrese el nuevo anio de publicacion (mayor a 0): ");
                    scanf("%d", &anio[i]);
                    if (anio[i] <= 0)
                    {
                        printf("Error: El anio debe ser mayor a 0.\n");
                    }
                } while (anio[i] <= 0);

                // Editar estado con validacion
                do
                {
                    printf("Ingrese el nuevo estado (0 para Disponible, 1 para Prestado): ");
                    scanf("%d", &estado[i]);
                    if (estado[i] != 0 && estado[i] != 1)
                    {
                        printf("Error: Solo se permite 0 o 1.\n");
                    }
                } while (estado[i] != 0 && estado[i] != 1);

                printf("\nDatos del libro editados con exito.\n");
                encontrar = 1;
                break;
            }
        }

        if (encontrar == 0)
        {
            printf("\nLibro no encontrado.\n");
        }
    }

    system("pause");
}

// 4. Buscar por titulo utilizando strcmp
void buscarPorTitulo(char titulo[][50], char autor[][50], char genero[][50], int anio[], int estado[], int cantidad)
{
    char buscar[50];
    int encontrar = 0;
    int i;

    system("cls");

    if (cantidad == 0)
    {
        printf("No hay libros registrados para buscar.\n");
    }
    else
    {
        printf("Ingrese el titulo a buscar: ");
        scanf(" %[^\n]", buscar);

        for (i = 0; i < cantidad; i++)
        {
            if (strcmp(titulo[i], buscar) == 0)
            {
                printf("\n--- Libro Encontrado ---\n");
                printf("Titulo: %s\n", titulo[i]);
                printf("Autor: %s\n", autor[i]);
                printf("Genero: %s\n", genero[i]);
                printf("Anio: %d\n", anio[i]);
                if (estado[i] == 0)
                {
                    printf("Estado: Disponible\n");
                }
                else
                {
                    printf("Estado: Prestado\n");
                }
                encontrar = 1;
                break;
            }
        }

        if (encontrar == 0)
        {
            printf("\nLibro no encontrado.\n");
        }
    }

    system("pause");
}

// 5. Libro mas antiguo y mas reciente
void libroMasAntiguoYReciente(char titulo[][50], int anio[], int cantidad)
{
    int i;
    int anioMin, anioMax;
    char libroMin[50], libroMax[50];

    system("cls");

    if (cantidad == 0)
    {
        printf("No hay libros registrados para comparar.\n");
    }
    else
    {
        anioMin = anio[0];
        anioMax = anio[0];
        strcpy(libroMin, titulo[0]);
        strcpy(libroMax, titulo[0]);

        for (i = 1; i < cantidad; i++)
        {
            if (anio[i] < anioMin)
            {
                anioMin = anio[i];
                strcpy(libroMin, titulo[i]);
            }
            if (anio[i] > anioMax)
            {
                anioMax = anio[i];
                strcpy(libroMax, titulo[i]);
            }
        }

        printf("=== Comparacion por Anio de Publicacion ===\n");
        printf("Libro mas antiguo: %s (%d)\n", libroMin, anioMin);
        printf("Libro mas reciente: %s (%d)\n", libroMax, anioMax);
    }

    system("pause");
}

// 6. Mostrar resumen de prestamos (contar disponibles y prestados)
void resumenPrestamos(int estado[], int cantidad)
{
    int i;
    int disponibles = 0;
    int prestados = 0;

    system("cls");

    if (cantidad == 0)
    {
        printf("No hay libros registrados para calcular el resumen.\n");
    }
    else
    {
        for (i = 0; i < cantidad; i++)
        {
            if (estado[i] == 0)
            {
                disponibles++;
            }
            else
            {
                prestados++;
            }
        }

        printf("=== Resumen de Prestamos ===\n");
        printf("Cantidad de libros disponibles: %d\n", disponibles);
        printf("Cantidad de libros prestados: %d\n", prestados);
        printf("Total de libros en inventario: %d\n", cantidad);
    }

    system("pause");
}

// 7. Mostrar clasificacion por estado
void mostrarClasificacionPorEstado(char titulo[][50], int estado[], int cantidad)
{
    int i;

    system("cls");

    if (cantidad == 0)
    {
        printf("No hay libros registrados para clasificar.\n");
    }
    else
    {
        printf("=== Clasificacion de Libros por Estado ===\n\n");
        for (i = 0; i < cantidad; i++)
        {
            printf("Libro: %s -> Estado: ", titulo[i]);

            if (estado[i] == 0)
            {
                printf("Disponible\n");
            }
            else
            {
                printf("Prestado\n");
            }
        }
    }

    system("pause");
}