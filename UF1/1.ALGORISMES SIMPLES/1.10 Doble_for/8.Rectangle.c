#include <stdio.h>
#include <rlutil.h>
#include <time.h>


/*Fer un rectangle entre els punts (10,3) i (15,10), canviant de colors i que no
s’aturi fins que no es premi una tecla. */

int main(){

    srand(time(NULL));

    int columna1 = 10, columna2 = 15,  fila1 = 3, fila2 = 10;
    int incr_fila1 = 3, incr_columna1 = 10;

    
    

    while(!kbhit()){
    

    /*Tengo que pintar la  fila 3 y 10 enteras. Tambien las columnas 10 y 15*/
   
    while(incr_fila1 <= fila2){ //hace la primera columna
        int color = rand() % 15 + 1;   
        setColor(color);
        gotoxy(columna1, incr_fila1);
        printf("X\n");
        Sleep(200);
        incr_fila1 += 1;
    }
    
    incr_fila1 = fila1;
    gotoxy(columna2, incr_fila1);

    
    
    while(incr_fila1 <= fila2){ //hace la segunda  columna
        int color = rand() % 15 + 1;   
        setColor(color);
        gotoxy(columna2, incr_fila1);
        printf("X\n");
        Sleep(200);
        incr_fila1 += 1;
    }

    incr_fila1 = fila1;
    gotoxy(columna1, incr_fila1);

    while(incr_columna1 < columna2){ //imprime la primera fila
        int color = rand() % 15 + 1;   
        setColor(color);
        printf("X");
        Sleep(200);
        incr_columna1 += 1;
    }
    
    incr_fila1 = fila1;
    incr_columna1 = columna1;

    gotoxy(incr_columna1, fila2);

    while(incr_columna1 < columna2){ //imprime la segunda  fila
        int color = rand() % 15 + 1;   
        setColor(color);
        printf("X");
        Sleep(200);
        incr_columna1 += 1;
    }
    incr_fila1 = fila1;
    incr_columna1 = columna1;
    gotoxy(columna1, fila2);

    }


    getch();
    return 0;
}