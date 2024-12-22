#include <stdio.h>
#include <rlutil.h>
#include <time.h>


/*Doble rebot
Fer un programa que reboti tant en l’eix x com en l’eix y. S’haurà d’aturar quan
es premi qualsevol tecla.
Cal executar el main.exe*/

int main(){

    //Primero tendre  que  hacer un  marco, para  que  cuando toque  rebote. Pienso  que  tengo que hacer 4  tipos.
    


    //hacemos el marco. Reutilizo de otro ejercicio
        int x, y, altura = 20, ancho = 119;
        gotoxy(1,5);


      for (int i = 1; i <= altura; i++){
        
        for  (int  j = 1; j <= ancho; j++){
            
            if ((i != 1) && (i != altura)){


                if ((j == 1) || (j == ancho)){
                    printf("#");
                } else {
                    printf(" ");
                }
            }else {
                printf("#");
            }

            
        }

        printf("\n");

    }   //tenemos que tener en cuanta que el marco se  inicia en  la  posicio x=1 y=5
        //tenemos que generar la x,  que se desplace, y que el bucle  termine  si se presiona una tecla. 
        int columna_1 = 2, columna_2 = 118, fila_1 = 6, fila_2 = 23;
        int x_inicio = 2, y_inicio = 14;
        int direccion_x = 1, direccion_y = 1;
        
    srand(time(NULL));
    while (!kbhit()) {
        
        int color = rand() % 15 + 1;
        setColor(color);
        gotoxy(x_inicio, y_inicio);
        
        x_inicio += direccion_x;
        y_inicio += direccion_y;
        
        //cuando toque uno de los dos  bordes verticales la direccion  de x.
        if (x_inicio == columna_2 || x_inicio == columna_1) {  //cambia la direccion de la x
            direccion_x = -direccion_x; 
        }
        //cuando toque uno de los dos bordes horizontales la direccion de y.
        if (y_inicio == fila_2 || y_inicio == fila_1) {
            direccion_y = -direccion_y;  //cambia la  dirección de la y
        }

        gotoxy(x_inicio, y_inicio);
        printf("X"); 
        Sleep(50);
    }


    getch();
    return 0;
}