#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
struct
{
    int id;
    int numero;
    char nombre[51];
    int par;
    int impar;
    int primo;
    int isEmpty;

}typedef Numero;


Numero* numero_new(void);
void numero_print(Numero* this);
int numero_completarCampos(ArrayList* this);
void numero_completarPar(Numero* this);
void numero_completarPrimo(Numero* this);

int numero_setNumero(Numero* this, int number);
int numero_setNombre(Numero* this, char* nombre);
int numero_setPar(Numero* this, int number);
int numero_setImpar(Numero* this, int number);
int numero_setPrimo(Numero* this, int number);
int numero_setIsEmpty(Numero* this, int isEmpty);
int numero_setId(Numero* this, int id);

int numero_getNumero(Numero* this);
char* numero_getNombre(Numero* this);
int numero_getPar(Numero* this);
int numero_getImpar(Numero* this);
int numero_getPrimo(Numero* this);
int numero_getId(Numero* this);

/*void employee_print(Employee* this);
int funcionQueFiltra(void* item);


int employee_compare(void* pEmployeeA,void* pEmployeeB);*/
#endif // _EMPLOYEE_H



