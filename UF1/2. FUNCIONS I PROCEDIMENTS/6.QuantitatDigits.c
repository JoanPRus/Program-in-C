#include <stdio.h>
int demanarNumero();
void pinta(int numero, int contador);
int calculaQuantitatDigits(int numero);
/*(QuantitatDigits) Fer un programa que demani un nombre positiu i ens
mostri quants dígits té.
int demanarNumero(void);
int calculaQuantitatDigits(int );
void pinta(int,int);
*/


//para saber los digitos que tiene puedo  dividir entre 10  hasta que el  numero sea 0. 
//Otra forma es convertir los numeros en  cadena de texto y recorrerlo en un array, sprintf. 

//damos valor a las variables del  main.
int main(){
    int numero, contador;

    numero = demanarNumero();
    contador = calculaQuantitatDigits(numero);
    pinta(numero, contador);
    
    getch();
    return 0;
}

//calculamos el numero de digitos
int calculaQuantitatDigits(int numero)
{
    int contador = 0;
    
    while(numero > 0){
        numero /= 10;
        contador++;
    }

    return contador;
}


//reutilizamos funciones
int demanarNumero()
{
    int numero;
    do{
        printf("Introdueix un numero positiu: ");
        scanf("%d", &numero);
    }while(numero < 0);

    return numero;
}

void pinta(int numero, int contador)
{
    printf("El numero es %d i te %d digits", numero, contador);
}