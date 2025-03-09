#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define MAX 5
void imprimefichas(int vector[]);
void generarnumeros(int varriba[], int vabajo[]);
void comprobarfichas(int varriba[], int vabajo[]);
/*Defineix dos vectors de MAX fitxes. El primer vector representarà la part de dalt
de la fitxa del dominó; mentre que l’altre vector representarà la part de sota de
la fitxa del dominó. Un cop tinguem tot el vector ple i tenint en compte que es
poden repetir les fitxes; fes una funció que ens informi si tenim totes les fitxes
dobles. Les fitxes s’han de generar aleatòriament.*/

int main(){

    int varriba[MAX] = {};
    int vabajo[MAX] = {};

    srand(time(NULL));
    generarnumeros(varriba, vabajo);
    comprobarfichas(varriba, vabajo);

    getch();
    return 0;
}

//generar los numeros de las fichas aleatoriamente y despues comprobar si todos son dobles. 

void generarnumeros(int varriba[], int vabajo[]){

    int min = 1, max = 6;

    for(int i = 0; i < MAX; i++){
        
        int numero_ficha = min + rand() % (max - min + 1);
        varriba[i] = numero_ficha;

        numero_ficha = min + rand() % (max - min + 1);
        vabajo[i] = numero_ficha;
    }
}

//para saber si todas son dobles tendre que comparar un vector con otro, 

void comprobarfichas(int varriba[], int vabajo[]){

    //en el momento que una ficha no tenga los mismos numeros, ya no son todas dobles

    bool sondobles = true;

    for(int i = 0; i < MAX; i++){

        if(varriba[i] != vabajo[i]){
            sondobles = false;
            break;
        }

    }

    printf("\nLas cartas generadas son:\n");
    imprimefichas(varriba);
    printf("\n-------------------------\n");
    imprimefichas(vabajo);


    if(sondobles == true){
        printf("\nLas fichas son dobles!!!");
    }else printf("\nLas fichas no son dobles");
}

void imprimefichas(int vector[]){

    for(int i = 0; i < MAX; i++){
        printf("%d ", vector[i]);
    }
}