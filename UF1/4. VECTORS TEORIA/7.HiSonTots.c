#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define MAXV1 5
#define MAXV2 10
void calcularCantidadDeElementos(int v1[],  int v2[], int *cantidadv1, int *cantidadv2);
void rellenarVectores(int v1[], int  v2[], int *cantidadv1, int *cantidadv2);
void comprobarSisonIguales(int v1[], int v2[], int *cantidadv1, int *cantidadv2);

/*(HiSonTots) Defineix dos vectors, un de 5 elements i l’altre de 10 elements i
cal comprovar si tots els valors del primer vector estan dins del segon vector.
Per tal de generar els dos vectors, aleatòriament el programa calcularà quants 
elements ha d’omplir de cadascun dels vectors. Com tenir en compte que com
a mínim els vectors contindran 1 element.
Seguidament, el programa haurà d’omplir els dos vectors, amb les capacitats
corresponents, amb valors aleatoris compresos entre 0 i 10.
En finalitzar el programa cal que informi de si tots els element del primer
vector estan dins del segon.*/

/*Definir  dos vectores,  de 5 y  de 10 elementos.  Calcular aleatoriamente cuantos elementos tendra cada vector
minimo uno  y llenarlos aleatoriamente valores entre 0 i 10. Imprimir los dos vectores y decir si todos los  elementos  del
primer vector estan en  el segundo*/

int main(){

   int v1[MAXV1] = {};
   int v2[MAXV2] = {};
   int  cantidadv1  = 0, cantidadv2 = 0;

    srand(time(NULL));
    calcularCantidadDeElementos(v1, v2, &cantidadv1, &cantidadv2);
    rellenarVectores(v1, v2, &cantidadv1, &cantidadv2);
    comprobarSisonIguales(v1, v2, &cantidadv1, &cantidadv2);



    getch();
    return 0;
}

void calcularCantidadDeElementos(int v1[],  int v2[], int *cantidadv1, int *cantidadv2)
{
    int min = 1;

    *cantidadv1 = min + rand() % (MAXV1 - min + 1);
    *cantidadv2 = min + rand() % (MAXV2 - min + 1);

}

void rellenarVectores(int v1[], int  v2[], int *cantidadv1, int *cantidadv2)
{  
    printf("Primer vector:");
    for(int i = 0; i < *cantidadv1; i++){

        int numero = rand() % 11;
        v1[i] = numero; 

        printf("\n[%02d]:%d", i, v1[i]);

    }

    printf("\n\nSegundo vector:");
    for(int j = 0; j < *cantidadv2; j++){

        int numero = rand() % 11;
        v2[j] = numero;
        printf("\n[%02d]:%d", j, v2[j]);

    }
}


void comprobarSisonIguales(int v1[], int v2[], int *cantidadv1, int *cantidadv2)
{
    bool iguales = false;


    for(int i = 0; i < *cantidadv1; i++){

        iguales = false; //se restablece el bool

        for(int j = 0;  j < *cantidadv2; j++){

            if(v1[i] == v2[j]){ //si algun elemento es igual se  le asiga  true
                iguales = true;
            }

        }

        if(iguales == false){
            printf("\n\nNo son iguales");
            break;
        }
    }

    if(iguales == true){
        printf("\n\nSi son iguales");
    }

}