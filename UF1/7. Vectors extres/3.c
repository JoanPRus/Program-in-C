#include <stdio.h>
#include <stdlib.h>
#define MAX  28
void generarfichas(int var[], int vab[]);
void imprimirfichas(int varriba[], int vabajo[]);


/* Genera les 28 fitxes del dominó consecutivament
utilitzant dos vectors (des de la més alta fins a la més
baixa). Les fitxes s’han d’introduir ordenades dins dels
vectors. Un cop estiguin generades, les imprimeixes
com mostra la imatge.
*/

int main(){

    int varriba[MAX]  = {};
    int vabajo[MAX]  = {};

    generarfichas(varriba, vabajo);
    imprimirfichas(varriba, vabajo);

    getch();
    return 0;
}

/*Tengo que generar las 28 fichas en dos vectores, empezando de  la mas alta a la mas baja, el  vector tiene  que estar ordenado
despues de estar ordenadas las imprimimos.*/

void generarfichas(int var[], int vab[]){

    int indice = 0;
        
        for(int i = 6; i >= 0; i--){//fichas de arriba 6,5,4,3,2,1

            for(int j = i; j >= 0; j--){ //fichas de  abajo desde i hasta 0
                
                var[indice] = i;   
                vab[indice] = j;

                indice++;
            }
        }
}

void imprimirfichas(int varriba[], int vabajo[]){

    //cuando el valor  de arriba  vaya  a cambiar se salta de  linea

    for(int i = 0; i < MAX; i++){

        printf("(%d-%d)  ", varriba[i],  vabajo[i]);

        if(i < MAX - 1 && varriba[i] != varriba[i + 1]){
            printf("\n");
        }
    }
}