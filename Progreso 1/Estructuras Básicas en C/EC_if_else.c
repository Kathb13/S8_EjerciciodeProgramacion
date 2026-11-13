#include <stdio.h>

int main()

{
    /*realizar un programa que permita verificar la 
    temperatura de una habitación donde la temperatura menor a 18 grados dara un 
    mensaje de prender calefactor, entre 18 y 25 temperatura normal y mayor a 25 prender 
    aire acondicionado*/

    //variables
    int temperatura = 0;

    printf("Ingrese la temperatura de la habitacion \n");
    scanf("%i", &temperatura); //d es entero para leer la variable

    if (temperatura < 18) //verdadero o falso
    {
        printf("Prender el calefactor...\n");
    }
    else if (temperatura >= 18 && temperatura < 25)
    {
        printf("Temperatura normal \n");
    }
    else
    {
        printf("Prender aire acondicionado \n");
    }
   
    
    return 0;
}