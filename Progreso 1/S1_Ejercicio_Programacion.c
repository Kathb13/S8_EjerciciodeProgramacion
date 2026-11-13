//Ejercicio de Programacion S1
//Kathleen Bustos

#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    //variables
    char ID [10], nombre[15];
    float cantidad_en_stock = 0 , precio_venta, cantidad_a_vender = 0, cantidad_comprada = 0, precio_compra, ganancia, unidades_vendidas = 0;
    int op;

    do {
        
        printf("\n\n");
        printf("==== MENU DEL USUARIO ==== \n");
        printf("-------------------------- \n");
        printf("1. Ingreso de producto \n");
        printf("2. Venta de productos \n");
        printf("3. Consulta de informacion actualizada \n");
        printf("4. Calculo de ganancias \n");
        printf("5. Salir del programa \n");
        printf("-------------------------- \n");
    
        printf("Ingrese una opcion (1-5)\n\n");
        scanf("%i", &op);

        switch (op)
        {
        case 1:
            
            printf("Ingrese el ID del producto:\n");
            scanf("%s",ID);
            printf("Ingrese el nombre del producto:\n");
            scanf(" %[^\n]", nombre);
            printf("Ingrese la cantidad de la compra:\n");
            scanf("%f",&cantidad_comprada);
            printf("Ingrese el precio de compra unitario:\n");
            scanf("%f",&precio_compra);
            
            cantidad_en_stock = cantidad_en_stock + cantidad_comprada;
            precio_venta = precio_compra + precio_compra*0.3; //ganacia del 30% para cada venta
            break;

            case 2:
            printf("Ingrese la cantidad de la venta:\n");
            scanf("%f",&cantidad_a_vender);
            
            if (cantidad_a_vender > cantidad_en_stock)
                printf("\nNo existe el stock suficiente para realizar la venta.\n\n");
            else
                {
                cantidad_en_stock = cantidad_en_stock - cantidad_a_vender;
                printf("Venta realizada con exito, se vendieron %.2f unidades\n\n", cantidad_a_vender);
                unidades_vendidas = unidades_vendidas + cantidad_a_vender;
                }
                system("pause");
                break;

            case 3:
            printf("INFORMACION ACTUALIZADA DEL PRODUCTO \n\n");
            printf("ID: %s\n", ID);
            printf("Nombre del producto: %s\n", nombre);
            printf("Unidades vendidas: %.2f\n", unidades_vendidas);
            printf("Precio de compra unitario: %.2f\n", precio_compra);
            printf("Precio de venta unitario: %.2f\n", precio_venta);
            printf("Stock: %.2f\n\n", cantidad_en_stock);

            system("pause");
            break;

            case 4:
            ganancia = unidades_vendidas*0.3;
            printf("La ganancia obtenida de vender %.2f unidades es de $%.2f\n\n", unidades_vendidas, ganancia);
            system("pause");
            break;
        
            case 5:
            printf("Saliendo del programa. Vuelva pronto.\n\n");
            break;

            default:
            printf("Opcion invalida, vuelva a ingresar un numero del 1 al 5.\n\n");
            break;
        }

    } while(op!=5);

    return 0;
}