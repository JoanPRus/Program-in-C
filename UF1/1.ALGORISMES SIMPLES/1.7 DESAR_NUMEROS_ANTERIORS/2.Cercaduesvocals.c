#include <stdio.h>
#include <rlutil.h>  //colors 
#include <stdlib.h>  //rang
#include <time.h>

/*(CercaDuesVocalsSeguides) Genera automàticament lletres compreses
entre ‘A’ i la ‘Z’ i ves mostrant-les per pantalla fins que en trobem dues vocals
consecutives. Pinta cada lletra d’un color diferent (no podem tenir dues lletres
consecutives amb el mateix color ... no queda bonic)
Per tal de generar el caràcter utilitza la instrucció:
car=65+ rand()%(90-65+1);*/



int main(){

    /*Primero tendremos que crear un bucle para que genere las  letras, antes de imprimirlas haremos  que  cambien de color de manera
    aleatoria con una condicion que es que no se  repita el ultimo color, despues  imprimimos.*/    
    //int color = rand() % 16;  genera colores aleatorios. 
    //char car=65+ rand()%(90-65+1); genera las letras aleatorias.  vocales = 65,69,73,79,85

    char car = 0, car_memoria = 0;
    int color = 0, color_anterior = 0;

    srand(time(NULL)); //nueva semilla  para numeros aleatorios. 


    while (1){  //bucle infinito
        car=65+ rand()%(90-65+1); //genera el caracter

        do {
        color = rand() % 15 + 1;  // genera valores entre el 1 y el 15, evitando el 0  que es el negro. 
        //Dividimos  un numero rand entre 15  y  nos da un resto % de 0-14 por  eso sumamos uno siempre, evitando el  negro y  llegando a 15 maximo
        setColor(color); // se añade el color
        } while (color == color_anterior); // se repite el bucle si sale  el mismo color

        color_anterior = color; // guardamos  el  ultimo color

        printf("%c ", car); //lo imprime con color



       if ((car == 'A' || car == 'E' || car == 'I' || car == 'O' || car == 'U') && (car_memoria == 'A' || car_memoria == 'E' 
       || car_memoria == 'I' || car_memoria == 'O' || car_memoria == 'U')){

            break; //si las  dos ultimas son vocales se termina porque  se cumple el if
        }

        car_memoria = car; //guarda  la car en otra variable asi nos permite compararla con car de  la siguiente  vuelta.
    }



    getch();
    return 0;
}