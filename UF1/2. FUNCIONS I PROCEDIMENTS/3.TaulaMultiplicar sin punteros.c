#include<stdio.h>
int demanarNumero();
void pintaTaula(int numero);

/*(TaulaMultiplicar) Fer un programa que
demani a l’usuari quina taula vols mostrar. A
continuació mostra la taula corresponent. La
taula ha d’estar controlada entre 1 i 10.
int demanarNumero(void);
void pintaTaula(int);*/

//Ejercicio sin usar punteros

int main(){
    int numero;
    numero = demanarNumero();// la  variable numero es igual a la funcion, luego guardamos el numero en  el scanf y ya trabaja con el dato. 
    pintaTaula(numero);

    getch();
    return 0;
}

int demanarNumero()
{   
    int numero;
    do{
        printf("Introdueix la taula que vols veure (1-10): ");
        scanf("%d", &numero);

    }while(numero < 1 || numero > 10);
    
    return numero;
}

void pintaTaula(int numero)
{
    for(int i = 0; i <= 10; i++){
        printf("\n%d x %d = %d", numero, i, numero * i);
    }
}