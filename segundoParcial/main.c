#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "Numeros.h"

int main()
{
    char seguir = 's';
    int opcion = 0;
    int index;
    int i;
    ArrayList* numeros;
    numeros = al_newArrayList();



    while(seguir=='s')
    {
        system("cls");
        printf("1- Altas\n");
        printf("2- Completar campos\n");
        printf("3- Generar salida\n");
        printf("4- Listar numeros\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                index = parserReadNumeros("datos.csv",numeros);
                if(index==0)
                {
                    printf("\nSe leyo archivo correctamente\n");
                }
                else
                {
                    printf("\nError al leer archivo");
                }
                system("pause");
                break;

            case 2:
                index = numero_completarCampos(numeros);
                if(index==0)
                {
                    printf("\nSe completaron los campos correctamente\n");
                }
                else
                {
                    printf("\nError al completar campos");
                }
                system("pause");
                break;

            case 3:
                index = parserWriteNumeros("info.csv",numeros);
                if(index==0)
                {
                    printf("\nSe guardo archivo correctamente\n");
                }
                else
                {
                    printf("\nError al guardar archivo");
                }
                system("pause");
                break;

            case 4:
                printf("ID -- Numero -- Nombre -- Par -- Impar -- Primo\n");
                for(i=0;i<10;i++)
                {
                    numero_print(numeros->pElements[i]);
                }
                system("pause");
                for(i=0;i<numeros->len(numeros);i++)
                {
                    numero_print(numeros->pElements[i]);
                }
                system("pause");
                break;

            case 5:
                seguir = 'n';
                break;

            default:
                printf("Opcion incorrecta\n\n");
                system("pause");
                break;
        }
    }

    return 0;
}
