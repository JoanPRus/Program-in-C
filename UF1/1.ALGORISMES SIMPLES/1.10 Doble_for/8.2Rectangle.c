#include <stdio.h>
#include <rlutil.h>
#include <time.h>


/*Fer un rectangle entre els punts (10,3) i (15,10), canviant de colors i que no
s’aturi fins que no es premi una tecla. */


int main(){

    int c1 = 10, c2  = 15, f1 = 3, f2 = 10; //columnas y filas
    int dx = 1, dy = 1;  //direccion
    int c1_inicio = 10, f1_inicio = 3;

    //Lo  que voy hacer es que  cambie  de direccion si toma ciertas acciones.

   
    while(!kbhit()){
        
        gotoxy(c1_inicio, f1_inicio);
        
        int color = rand() %  15 + 1;
       
         

        if(c1_inicio < c2 && f1_inicio == f1){ //de izquierda a derecha. Se mantiene  la fila
            c1_inicio += dx;
        }else if(c1_inicio == c2  && f1_inicio < f2){ //de arriba a abajo. Se mantiene la columna
            f1_inicio  += dy;
        }else if(f1_inicio == f2 && c1_inicio > c1){ //de derecha a izquierda. Se mantiene la fila
            c1_inicio -= dx;
        }else if(f1_inicio > f1  && c1_inicio == c1){ //de abajo a  arriba. Se manciene la columna
            f1_inicio -= dy;
        }


        gotoxy(c1_inicio, f1_inicio);
        setColor(color);
        printf("X");
        Sleep(150);

    } 
    getch();
    return 0;
}