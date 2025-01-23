#include <stdio.h>
int demanarNumero();
int calculaSumaNumerosAnteriors(int numero);
void pinta(int numero, int resultat);

/*(SumaNumerosAnterior) Fer un programa que demani un número positiu i
ens mostri la suma dels n números anteriors.
int demanarNumero(void);
int calculaSumaNNumerosAnterior(int );
void pinta(int,int)
Introdueix el numero? 5
La suma dels 5 números es : 15*/

int main(){
    int numero, resultat; //iniciamos las variables en el main

    //asignamos las variables a  las funciones no void
    numero = demanarNumero();
    resultat = calculaSumaNumerosAnteriors(numero);
    pinta(numero, resultat);

    getch();
    return 0;
}

//pedimos  el numero
int demanarNumero()
{
    int numero;
    do{
        printf("Introdueix un numero positiu: ");
        scanf("%d", &numero);
    }while(numero < 0);

    return numero;
}

//calculamos la suma  de los anteriores
int calculaSumaNumerosAnteriors(int numero)
{   
    int resultat = 0;
    for(int i = 0; i <= numero; i++){
        resultat += i;
    }

    return resultat;
}

//mensaje con el resultado
void  pinta(int numero, int resultat)
{
    printf("La suma dels %d numeros es: %d", numero, resultat);
}