/*Realizar una lista de contactos, 
donde puedo buscar, agregar, editar o eliminar contactos*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//variables globales
//(sirven para todo el programa, no necesariamente para el int main)
#define MAX 100 //máximo de 100 contactos

int main()
{
    //variables locales
    char contactos[MAX][50]; 
    //maximo de 100 filas y 50 columanas (no son columnas como tal, son 50 caractreres por nombre)
    int contcontactos = 0;
    int op;
    int f; //variable para recorrer el for
    int encontrar;
    //variables vectores
    char nombreabuscar[50]; //ingresar hasta 50 caracteres por nombre
    char nuevocontacto[50]; //para editar el contacto

    //trabajo a realizar en casa eliminar contactos

    do
    {
        system("cls");
        printf("========== Sistema de Contactos ==========\n");
        printf("1.- Agregar contacto\n");
        printf("2.- Mostrar lista de contactos\n");
        printf("3.- Buscar contacto\n");
        printf("4.- Editar contacto\n");
        printf("5.- Eliminar contacto\n");
        printf("6.- Salir\n");
        printf("Ingrese una opcion entre 1-6: ");
        scanf("%d", &op);


        switch (op)
        {
        case 1:
            system("cls");
            if (contcontactos < MAX) //para validar que no se exceda del almacenamiento permitido
            {
                printf("Ingrese un nuevo contacto: ");
                scanf(" %[^\n]", &contactos[contcontactos]); //lo de corchetes no es el limite, es la posicion (0) donde se guarda la info
                //(" %[^\n]") borra el salto de linea sin la necesidad de usar un fgets (ctrl+alt+junto al lado del ñ)
                contcontactos++; //para regular tambien la posicion
                printf("Contacto agregado exitosamente\n");

                //preguntar a chat dame unas variantes, que pasaria si quiero aregar edad o email
                //en la fila cero agregame todo lo que va a ingresar
            }
            else
            {
                printf("No hay espacio disponible...\n");
            }
            
            system("pause");
            break;

        case 2:
            system("cls");
            if(contcontactos == 0) //apunta a la primera posicion, como esta en cero significa que no hay contactos guardados
            {
                printf("No hay contactos registrados\n");
            }
            else
            {
                printf("Lista de Contactos\n");
                //Imprimir asi:
                //1.- Juan
                //2.- Maria
                for (f = 0; f < contcontactos; f++) //f=o porque es la primera posicion
                {
                    printf("%d.- %s\n", f+1, contactos[f]); //[posicion]
                }
            }
            system("pause");
            break;

        case 3:
            system("cls");
            printf("Ingrese el nombre a buscar: ");
            scanf(" %[^\n]", &nombreabuscar);
            encontrar = 0; //variable si o no

            for (f = 0; f < contcontactos; f++)
            {
                if (strcmp(contactos[f], nombreabuscar) == 0) //compara dos cadenas de caracteres (el cero es verdadero)
                {
                    printf("Contacto encontrado en la posicion %d", f + 1);
                    encontrar = 1; //para indicar que si encontro
                    break; //cualquier cosa borrar si falla
                }
            }
            
            if (encontrar == 0) //doble igual es para preguntar y un igual es para asignar
            {
            printf("Dato no encontrado\n");
            }
            system("pause");
            break;

        case 4:
            system("cls");
            printf("Ingrese el contacto que desea editar: ");

            scanf(" %[^\n]", &nombreabuscar);
            encontrar = 0; //si esta 0 no lo encontro y si esta en 1 si lo encontro
            for (f = 0; f < contcontactos; f++)
            {
                if (strcmp(contactos[f], nombreabuscar) == 0) //verdadero porque lo encontro
                {
                    printf("Ingrese el nuevo nombre: ");
                    scanf(" %[^\n]", &nuevocontacto);
                    strcpy(contactos[f], nuevocontacto); //funcion para copiar el dato de nuevo contacto a contactos en la posicion f (asignacion) 
                    printf("Contacto editado con exito  \n");
                    encontrar = 1;
                    break;
                }
            }

            if (encontrar == 0)
            {
            printf("Dato no encontrado\n");
            }
            system("pause");
            break;

        case 5:
            /* eliminar */
            break;
        
        
        default:
            printf("Opcion invalida, vuelva a ingresar un numero del 1 al 6.\n\n");
            break;
        }

    } while (op!=6);
    

    return 0;
}