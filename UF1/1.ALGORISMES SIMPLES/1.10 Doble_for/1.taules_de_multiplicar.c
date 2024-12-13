#include <stdio.h>
#include <rlutil.h>


/*(Taules de multiplicar) Fer un algoritme que mostri per pantalla les taules
de multiplicar de l’1 al 10, fent una pausa a cada taula.*/

int main(){

    //tengo  que hacer 10 tables de  multiplicar que  lleguen  hasta el  diez,  usando un doble for. 



    for (int i = 1; i <= 10; i++){  //el numero de la tabla. 
        
        printf("\n");
        printf("\nTaula %d", i);
        Sleep(5000);

        for (int j = 1; j <= 10; j++){ //los numeros del 1 al 10 por ejemplo. 

            printf("\n  %d x %d = %d", i, j, i * j);
        }


    }


    getch();
    return 0;
}