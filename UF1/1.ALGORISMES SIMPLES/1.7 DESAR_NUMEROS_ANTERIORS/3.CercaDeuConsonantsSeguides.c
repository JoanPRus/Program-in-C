#include <stdio.h>
#include <rlutil.h>  //colors 
#include <stdlib.h>  //rang
#include <time.h>


/*. (CercaDeuConsonantsSeguides) Fes el mateix exercici que l’anterior, però
ara cal cercar deu consonants seguides. Cal utilitzar un comptador que vagi
comptant les consonants*/

int main(){

    /*Generar letras y ponerles color que no se repita, contar 10 consonantes seguidas y terminar el bucle, añadir contador*/
    //car=65+ rand()%(90-65+1); 
    //color = rand() % 15 + 1;
    //srand(time(NULL)); 

    char car = 0;
    int contador = 0;
    int color = 0, color_anterior = 0;

    srand(time(NULL)); //nueva semilla  para numeros aleatorios.
    
    while(1){ // el bucle es infinito, pero voy hacer que el contador  cuando llegue a 10 pare  el bucle, si encuentra una vocal contador a  0. 

    car=65+ rand()%(90-65+1); //genera el caracter

    do  {
        color = rand() % 15 + 1; // genera un numero para  el color
        setColor(color);
    } while( color == color_anterior);  //repite  si se cumple

    color_anterior = color; // color_anterior toma el valor de  color



    printf("%c ", car); //imprime el car

    contador++; // aumenta el contador

    if (car == 65 || car == 69 || car == 73 || car == 79 || car == 85){

        contador = 0; // el contador toma el valor  de 0  = porque aparece  una  vocal
    }

    if (contador == 10){
        
        break;// termina el bucle porque contador  es  igual  a 10 ==
    }

    }

    setColor(BLUE);
    printf("\nEl contador marca: %d", contador);
    printf("\nPulsa una tecla para finalizar");



    getch();
    return 0;
}