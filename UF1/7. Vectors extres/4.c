#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define MAX 56
void generarfichas(int vfichas[], int *contador_de_fichas, int *indice);
void comprobarfichas(int vfichas[], int num1, int num2, int *contador_de_fichas, int *indice);
void mensaje_ficha(int vfichas[], int *indice, int *contador_de_fichas);

/*Utilitzant un vector de 56 caselles genera les
28 fitxes del dominó aleatòriament, tenint en
compte que cada dues caselles forma una fitxa.
El procediment serà:
1. Generar una fitxa utilitzant un
vector de dues caselles
2. Comprovar si la fitxa ja existeix
dins de les fitxes que ja tenim
desades
3. En el cas que la fitxa sigui nova,
l’afegirem dins del vector.
4. Un cop s’han desat totes les
fitxes, mostrar-les per pantalla.*/


int main(){
    int vfichas[MAX] = {};  //las dos primeras posiciones las ponemos manualmente para sobreescribirlas  y evitar problemas.
    int contador_de_fichas = 1;
    int indice = 0;
    srand(time(NULL));
    generarfichas(vfichas, &contador_de_fichas, &indice);



    getch();
    return 0;
}

/*Guardar en un vector las 28 fichas = 56 casillas, generar los numeros aleatoriamente. Comprobar si la ficha ya existe,
imprimir cada vez que se añade una ficha nueva. Cuando esten todas las fichas se imprimen todas juntas.*/

//genera los numeros
void generarfichas(int vfichas[], int *contador_de_fichas, int *indice){
    
    //ponemos todo  el vector a -1  para poder generar la ficha 0-0

    for (int i = 0; i < MAX; i++) {
        vfichas[i] = -1;
    }

    while(*contador_de_fichas <= 28){  //se incluye la 28 porque el  contador empieza en 1

        int num1 = rand() % 7; //genera numeros del 0 - 6
        int num2 = rand() % (num1 + 1); //genera  un numero del  0 - num1 

        comprobarfichas(vfichas, num1, num2, contador_de_fichas, indice); //pasamos la funcion para comprobar los  numeros
    }
}

//comprueba el vector y guarda  los nuevos  numeros si no estan  en  el vector

void comprobarfichas(int vfichas[], int num1, int num2, int *contador_de_fichas, int *indice){
    bool se_repite = false;
    
    for(int i = 0;  i < *indice;  i += 2){ //el indice nos dice los elementos que hay

        if(vfichas[i] == num1 && vfichas[i + 1] == num2){
            se_repite = true;
            break;
        }    
    }
// si no repite guardamos los numeros en el vector, aumentamos indice para guardarlo bien y aumentamos el  contador de fichas para while
    if(se_repite == false){
        vfichas[*indice] = num1;
        (*indice)++;
        vfichas[*indice] = num2;
        (*indice)++;
        mensaje_ficha(vfichas, indice, contador_de_fichas);
        (*contador_de_fichas)++;
    }

}

//imprimir  mensaje cuando se guarda una nueva ficha

void mensaje_ficha(int vfichas[], int *indice, int *contador_de_fichas){
    //imprime  el numero  de  pasada
    printf("\nPasada numero %d\n", *contador_de_fichas);

        for(int j = 0; j < *indice; j += 2){ //imprime las fichas que llevamos, suma j +=2 para imprimir bien el vector

            printf("(%d-%d) ", vfichas[j],  vfichas[j + 1]);
        }
}
