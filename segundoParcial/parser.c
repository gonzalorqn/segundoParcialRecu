#include<string.h>
#include<stdio.h>
#include "parser.h"
#include "Numeros.h"

int parserReadNumeros(char* archivo,ArrayList* this)
{
    int ret = -1;
    int numero;
    char nombre[51];
    int par;
    int impar;
    int primo;
    int id=1;
    int leidos;
    int i;
    int index;
    int flag = 1;
    Numero* aux;
    FILE* pFile;

    if(archivo!=NULL && this!=NULL)
    {
        ret = -2;
        pFile=fopen(archivo,"r");

        if(pFile!=NULL)
        {
            ret = 0;
            fseek(pFile,29L,SEEK_SET);
            for(i=0;!feof(pFile);i++)
            {
                leidos=fscanf(pFile,"%d,%[^,],%d,%d,%d\n",&numero,nombre,&par,&impar,&primo);
                if(leidos==5)
                {
                    aux=numero_new();
                    if(aux!=NULL)
                    {
                        index = numero_setNumero(aux,numero);
                        if(index==-1)
                        {
                            flag = 0;
                        }
                        index = numero_setNombre(aux,nombre);
                        if(index==-1)
                        {
                            flag = 0;
                        }
                        index = numero_setPar(aux,par);
                        if(index==-1)
                        {
                            flag = 0;
                        }
                        index = numero_setImpar(aux,impar);
                        if(index==-1)
                        {
                            flag = 0;
                        }
                        index = numero_setPrimo(aux,primo);
                        if(index==-1)
                        {
                            flag = 0;
                        }
                        if(flag == 1)
                        {
                            numero_setIsEmpty(aux,0);
                            numero_setId(aux,id);
                            id++;
                            this->add(this,aux);
                        }
                        flag = 1;
                    }
                }
            }
        }
        fclose(pFile);
    }
    return ret;
}

int parserWriteNumeros(char* archivo,ArrayList* this)
{
    int ret = -1;
    int i;
    Numero* aux;
    FILE* pFile;

    if(this!=NULL)
    {
        ret = -2;
        pFile=fopen(archivo,"w");

        if(pFile!=NULL)
        {
            ret = 0;
            for(i=0;i<this->len(this);i++)
            {
                aux = (Numero*) this->get(this,i);
                fprintf(pFile,"%d,%s,%d,%d,%d\n",numero_getNumero(aux),numero_getNombre(aux),numero_getPar(aux),numero_getImpar(aux),numero_getPrimo(aux));
            }
        }
        fclose(pFile);
    }
    return ret;
}






/*ArrayList* depurar(ArrayList* destinatarios,ArrayList* listaNegra)
{
    ArrayList* listaDepurada;
    listaDepurada=al_newArrayList();
    empleado* aux;
    empleado* auxBlack;
    int flag;
    int i;
    int j;
    if(destinatarios!=NULL&&listaNegra!=NULL)
    {
        for(i=0;i<destinatarios->len(destinatarios);i++)
        {
            flag=0;
            aux=destinatarios->get(destinatarios,i);
            for(j=0; j<listaNegra->len(listaNegra); j++)
            {
                auxBlack=listaNegra->get(listaNegra,j);
                if((strcmp(aux->profesion,auxBlack->profesion))==0)
                {
                    flag=1;
                }
            }
            if(flag==0)
            {
                listaDepurada->add(listaDepurada,aux);
            }
        }
    }
    return listaDepurada;
}

void listar(ArrayList* listaDepurada)
{
    int contador=0;
    empleado* aux;
    int i;
    for(i=0;i<listaDepurada->len(listaDepurada);i++)
    {
        aux=listaDepurada->get(listaDepurada,i);
        if(aux!=NULL)
        {
            printf("\n%s %s",aux->nombre,aux->profesion);
            contador=contador+1;
        }
    }
    printf("\nTotal Printeados %d",contador);
}
*/
