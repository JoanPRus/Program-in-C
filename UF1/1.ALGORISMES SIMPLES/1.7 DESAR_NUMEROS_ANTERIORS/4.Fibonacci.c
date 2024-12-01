#include <stdio.h>
#include <stdlib.h>


/* (Fibonacci) Imprimeix els 7 primers termes de la sèrie de Fibonacci. Aquesta
sèrie està composada de la següent manera:
f0 = 0
f1 = 1
fn = fn-1 + fn-2;
Això produeix els següents valors:
f2 = 1
f3 = 2
f4 = 3
f5 = 5
f6 = 8
f7 = 13
I així succesivament*/


int main(){
    
    int fibonacci[8];//definimos el array

    //damos valor a  los dos primeros para seguir  la formula

    fibonacci[0] = 0;
    fibonacci[1] = 1;

    //creamos un bucle que  recorra  los siguientes

    for (int i = 2;  i <= 7; i++){

        fibonacci[i] = fibonacci[i - 1] + fibonacci[i  - 2]; //empieza  por fibonacci[2] y aplica la formula hasta llegar a fibonacci[7]
    }

    for (int i = 0; i <= 7; i++){ //nuevo bucle para recorrer todo

        printf("\nf%d = %d", i, fibonacci[i]); //i es  el numero del indice,  fibonnaci[i] son los resultados obtenidos en el anterior bucle
    }



    getch();
    return 0;
}