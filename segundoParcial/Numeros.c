#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Numeros.h"

Numero* numero_new(void)
{
    Numero* returnAux = NULL;
    returnAux = (Numero*) malloc(sizeof(Numero));

    return returnAux;
}

int numero_setNumero(Numero* this, int number)
{
    int ret = -1;
    if(this!=NULL && number>=0)
    {
        ret = 0;
        this->numero = number;
    }
    return ret;
}

int numero_setNombre(Numero* this, char* nombre)
{
    int ret = -1;
    if(this!=NULL && nombre!=NULL && strlen(nombre)>2 && strlen(nombre)<51)
    {
        ret = 0;
        strcpy(this->nombre, nombre);
    }
    return ret;
}

int numero_setPar(Numero* this, int number)
{
    int ret = -1;
    if(this!=NULL && number<=1 && number>=0)
    {
        ret = 0;
        this->par = number;
    }
    return ret;
}

int numero_setImpar(Numero* this, int number)
{
    int ret = -1;
    if(this!=NULL && number<=1 && number>=0)
    {
        ret = 0;
        this->impar = number;
    }
    return ret;
}

int numero_setPrimo(Numero* this, int number)
{
    int ret = -1;
    if(this!=NULL && number<=1 && number>=0)
    {
        ret = 0;
        this->primo = number;
    }
    return ret;
}

int numero_setIsEmpty(Numero* this, int isEmpty)
{
    int ret = -1;
    if(this!=NULL && isEmpty>=0)
    {
        ret = 0;
        this->isEmpty = isEmpty;
    }
    return ret;
}

int numero_setId(Numero* this, int id)
{
    int ret = -1;
    if(this!=NULL && id>0)
    {
        ret = 0;
        this->id = id;
    }
    return ret;
}

void numero_print(Numero* this)
{
    if(this!=NULL && this->isEmpty==0)
    {
        printf("%d -- %d -- %s -- %d -- %d -- %d\n",this->id,this->numero,this->nombre,this->par,this->impar,this->primo);
    }
}

int numero_completarCampos(ArrayList* this)
{
    int ret = -1;
    int i;
    if(this!=NULL)
    {
        ret = 0;
        for(i=0;i<this->len(this);i++)
        {
            numero_completarPar(this->pElements[i]);
            numero_completarPrimo(this->pElements[i]);
        }
    }
    return ret;
}

void numero_completarPar(Numero* this)
{
    int numero;
    if(this!=NULL)
    {
        numero = numero_getNumero(this);
        if(numero%2 == 0)
        {
            this->par = 1;
            this->impar = 0;
        }
        else
        {
            this->par = 0;
            this->impar = 1;
        }
    }
}

void numero_completarPrimo(Numero* this)
{
    int numero;
    int i;
    int a = 0;

    if(this!=NULL)
    {
        numero = numero_getNumero(this);
        for(i=1;i<=numero;i++)
        {
            if(numero%i == 0)
            {
                a++;
            }
        }

        if(a==2)
        {
            this->primo = 1;
        }
        else
        {
            this->primo = 0;
        }
    }
}


int numero_getNumero(Numero* this)
{
    int ret = -1;
    if(this!=NULL)
    {
        ret = this->numero;
    }
    return ret;
}

char* numero_getNombre(Numero* this)
{
    char* ret = NULL;
    if(this!=NULL)
    {
        ret = this->nombre;
    }
    return ret;
}

int numero_getPar(Numero* this)
{
    int ret = -1;
    if(this!=NULL)
    {
        ret = this->par;
    }
    return ret;
}

int numero_getImpar(Numero* this)
{
    int ret = -1;
    if(this!=NULL)
    {
        ret = this->impar;
    }
    return ret;
}

int numero_getPrimo(Numero* this)
{
    int ret = -1;
    if(this!=NULL)
    {
        ret = this->primo;
    }
    return ret;
}

int numero_getId(Numero* this)
{
    int ret = -1;
    if(this!=NULL)
    {
        ret = this->id;
    }
    return ret;
}


/*
int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    int retorno;
    Employee* e1 = (Employee*) pEmployeeA;
    Employee* e2 = (Employee*) pEmployeeB;

    retorno = strcmp(e1->nombre, e2->nombre);

    return retorno;
}

void employee_print(Employee* this)
{
    printf("%d -- %s -- %.2f -- %d -- %s\n",this->id,this->nombre,this->sueldo,this->edad,this->profesion);
}


int funcionQueFiltra(void* item)
{
    Employee* aux = NULL;
    int ret = 0;
    if(item!=NULL)
    {
        aux = (Employee*) item;
        if(aux->edad > 30 && strcmp(aux->profesion, "programador")==0)
        {
            ret = 1;
        }
    }
    return ret;
}
*/
