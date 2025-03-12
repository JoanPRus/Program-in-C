#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20
void generarfichas(int varriba[], int vabajo[]);
void mostrarfichas(int vector[]);
void fichamasgrande(int varriba[], int vabajo[]);

/*Genera 20 fitxes del dominó utilitzant dos vectors i mostra quina és la fitxa més
alta. Per a generar les fitxes, es demana generar primer la part de dalt i
posteriorment la part de sota. Per a que ens sigui més fàcil la resolució, es
demana que sempre tinguem en la part superior el número més gran o igual al
de sota. Per exemple la fitxa 3,4 no serà una carta vàlida; però la
fitxa 4,4 sí.
Una fitxa que contingui un 6 és més alta que qualsevol altre fitxa que no
contingui el 6. En el cas que dues fitxes tinguin el número 6, serà més alta
aquella que el seu segon número sigui més alt*/

int main(){

    int parte_de_arriba[MAX] = {};
    int parte_de_abajo[MAX] = {};

    srand(time(NULL));
    generarfichas(parte_de_arriba, parte_de_abajo);
    mostrarfichas(parte_de_arriba);
    mostrarfichas(parte_de_abajo);
    fichamasgrande(parte_de_arriba, parte_de_abajo);

    getch();
    return 0;
}

/*Usar dos vectores para generar 20 fichas, cada vector para una  parte de la  ficha. Primero generar la parte de arriba.
Nos  pide que  el numero de abajo sea igual o menor que el de arriba.  Mostrar todas  las  fichas  generadas y decir cual 
es la mas alta*/

void generarfichas(int varriba[], int vabajo[]){
    //al  inciar el vector a todo cero no  generara el  numero 0-0 pero  eso no  nos importa ahora. 
   int indice = 0;
    while(indice < MAX){

        int num1 = rand() % 7;
        int num2 = rand() % (num1 + 1);
        varriba[indice] = num1;
        vabajo[indice] = num2;
        indice++;
    }
}

void mostrarfichas(int vector[]){

    printf("\n");
    for(int i = 0; i < MAX; i++){

        printf("%d ", vector[i]);
    }
}


void fichamasgrande(int varriba[], int vabajo[]){

    int num_arriba_mas_grande = -1;
    int num_abajo_mas_grande = -1;
    int indice;

    for(int i = 0; i < MAX; i++){

        if(varriba[i] > num_arriba_mas_grande){ //si es mayor que el que tenemos guardado 

            num_arriba_mas_grande = varriba[i];
            indice = i; //guardamos su numero de  posicion

        }else if(varriba[i] == num_arriba_mas_grande){ //si  es  igual al que tenemos guardado

            if(vabajo[i] > vabajo[indice]){
                num_arriba_mas_grande = varriba[i];
                indice = i;//guardamos la  nueva posicion si el de abajo es mayor
                num_abajo_mas_grande = vabajo[i];
            }
        }
    }

    printf("\n\nLa ficha mas grande es (%d-%d), teniendo la posicion en el vector de %d", varriba[indice], vabajo[indice], indice);
    
}