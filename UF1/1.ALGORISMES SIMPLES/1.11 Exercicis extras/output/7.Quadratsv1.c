#include <stdio.h>
#include <rlutil.h>
#include <time.h>


/*(Quadrats) Es demana a partir de la posició (1,1) fer quadres cada cop més
grans. El primer quadre tindrà 1 casella (1 X 1), el segon quadre tindrà 4
caselles (2 X2); el tercer quadre 9 caselles (3 X 3) i así succesviament fins a
obtener un quadrat de (25 x 25)
Cal tenir en compte que dos requadres consecutius no poden tenir el mateix
color, ja que sino no es pot apreciar bé l’efecte que volem fer. Caldrà prèmer
una tecla cada cop que volem fer un nou requadre. */


int main(){

    /*Hacer cuadrados de 1x1 hasta 25x25, siempre  parte desde la posicion (1,1), getch para hacer los siguientes cuadros.
    generar colores, no se repita el color al cuadrado anterior.
    Tengo que  hacer   un  bucle para  que empiece siempre  en (1,1).*/
    

    int x_inicio = 1, y_inicio = 1;
    int x_inc = 1,  y_inc = 1, cuadrado = 1;
    int color_anterior = -1, color; //-1 por dar un  valor  que no sea igual la primera vez
    //primer bucle para empezar la posicion inicial

    srand(time(NULL));

    for(int i = 1; i <= 25; i++){
        
        do{
            color = rand() % 15 + 1;

        }while(color == color_anterior);
        color_anterior = color;

        setBackgroundColor(color);
        gotoxy(x_inicio, y_inicio); //cada vez que imprima un  cuadro  volvera el cursor al inicio. 
        
        x_inc = x_inicio; //reinicia el valor de los incrementos
        y_inc = y_inicio;
        //tengo que hacer que  imprima y ir cambiando  la direccion y posicion  segun unas normas. 

        cuadrado = i * i; // area  del cuadrado,  equivale a las  casillas  que ocupara. 

        for(int j = 1; j <= cuadrado;  j++){//este bucle cumple con las  veces  que tendra que  imprimir


            gotoxy(x_inc,  y_inc);
            printf(" ");
            x_inc += 1;

            if(x_inc > i){ //si  llega al valor de  la columna la posicon de la x va a la primera  columna y baja  una fila
                x_inc = 1;
                y_inc += 1;
            }

        }

        getch();//pulsar para dar siguiente vuelta al bucle
        Sleep(50);
    }

    return 0;
}



