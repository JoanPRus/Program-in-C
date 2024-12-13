#include <stdio.h>
#include <rlutil.h>
#include <stdlib.h>


/*(Taules de multiplicar Columnes) Fer un algoritme que mostri per pantalla
les taules de multiplicar de l’1 al 10, fent una pausa a cada taula. Cal utilitzar la funció gotoxy, a través del següent codi:
*/


    
    
  int main(){

    //tengo que imprimir las tablas en  columnas. 
    
  
     int x  = 1, y = 1;  //iniciamos variables para el  gotoxy

    for (int i = 1; i <= 10; i++){  //bucle  para las tablas
       
       

        for (int j = 1; j <= 10; j++){ // numeros del 1 al 10
        

            gotoxy(x, y);//posiciona
            printf("%d x %d = %d", i, j, i * j);  //operacion
            y++;//aumenta 1 la y, asi baja a la siguiente fila
        }

        x += 15; // la siguiente  tabla estara desplazada a la derecha un poco
        y = 1; // la siguiente  tabla  estara a la misma altura que la anterior

        if(i == 5){ // la  x toma nuevo valor y la y igual. columna 1 fila 15
            x = 1; // 
            y = 15;
        }
        if(i > 5){  // si i es superior a 5 mantenemos la fila
            
            y = 15;
        }
        }
    


    getch();
    return 0;
}