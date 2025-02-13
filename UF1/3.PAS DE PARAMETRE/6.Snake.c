#include <stdio.h>
#include <rlutil.h>
#include <stdlib.h> //rand()
#include <time.h>
#include <stdbool.h>
void marco();
void PrintSerpiente();
void serpientemovimiento(int *x,  int *y, int ColumnaIzquierda, int ColumnaDerecha, int FilaInferior, int FilaSuperior, int  *tecla, int *posicionesY, int *contadorY, int *posicionesX, int *contadorX, int *contadormanzanas, int *x_manzana, int *y_manzana, int *longitud, bool *colision);
void guardarposicion(int *x, int *posicionesX, int *contadorX, int  *contadorY, int *y, int *posicionesY, int *longitud);
void borrarrastro(int *posicionesX, int *posicionesY, int *contadorX, int *contadorY, int *longitud);
void  manzana(int *x, int *y, int *contadormanzanas, int *x_manzana, int *y_manzana,  int *longitud);
void mensajecontador(int *contadormanzanas);
void colisionserpiente(int *contadorX, int *contadorY, int *longitud, int *posicionesX, int *posicionesY, bool *colision);
void gameOver();
void mensajedeincio();
/*Voy hacer el  juego del Snake, no voy ha seguir las  instrucciones del  ejercicio.
Crear un marco que sera limite de la serpiente, si lo toca muere. Si choca con sigo misma tambien muere. 
Cada vez que coma una  manzana aumentara su tamaño, generar "Manzanas" de manera aleatoria y poner un contador. 
usar: 
kbhit detecta  si  una  *tecla es presionada sin pulsar enter,
getkey permite leer las *teclas en ASCII(flechas tambien), 
gotoxy  posiciona el cursor. 

El movimiento de la serpiente es  automatico, nosotros marcamos la direccion,  es  decir, avanza sola  pero le damos instrucciones 
hacia  donde  tiene  que ir. Esto  esta sujeto a limitaciones del movimiento porque si va hacia la derecha no puedo pulsar la flecha de la izquierda 
me comeria a mi mismo, en este caso ir hacia adelante podria aumentar la velocidad un poco. Lo mismo si  va hacia arriba o hacia abajo.*/


int main(){
    int x = 40, y = 10;
    int FilaSuperior = 5, FilaInferior = 25;
    int ColumnaIzquierda = 20, ColumnaDerecha = 100;
    int tecla;
    int posicionesX[500];
    int contadorX = 0;
    int posicionesY[500];
    int contadorY = 0;
    int contadormanzanas = 0;
    int x_manzana = 60, y_manzana = 14; 
    int  longitud = 1;
    int colisionX, colisionY;
    bool colision = false;
    mensajedeincio();
    marco();
    serpientemovimiento(&x, &y, ColumnaIzquierda, ColumnaDerecha, FilaInferior, FilaSuperior, &tecla, posicionesY, &contadorY, posicionesX, &contadorX, &contadormanzanas, &x_manzana, &y_manzana, &longitud, &colision);
    gameOver();
    Sleep(5000);
    return 0;

}

//mensaje  de inicio

void mensajedeincio(){
    printf("\n");
    printf("  ______   _                                           _   _           \n");
    printf(" |  ____| | |                                         (_) | |          \n");
    printf(" | |__    | |     __ _   _   _   ___    __ _   _ __    _  | |_    ___  \n");
    printf(" |  __|   | |    / _` | | | | | / __|  / _` | | '_ \\  | | | __|  / _ \\ \n");
    printf(" | |____  | |   | (_| | | |_| | \\__ \\ | (_| | | | | | | | | |_  | (_) |\n");
    printf(" |______| |_|    \\__, |  \\__,_| |___/  \\__,_| |_| |_| |_|  \\__|  \\___/ \n");
    printf("                  __/ |                                                \n");
    printf("                 |___/                                                 \n");
    printf("\n");
    Sleep(5000);
    cls();
}

//mensaje final

void gameOver() {
    cls();
    gotoxy(10,10);
    printf("\n");
    printf(" $$$$$$\\   $$$$$$\\  $$\\      $$\\ $$$$$$$$\\        $$$$$$\\  $$\\    $$\\ $$$$$$$$\\ $$$$$$$\\   \n");
    printf("$$  __$$\\ $$  __$$\\ $$$\\    $$$ |$$  _____|      $$  __$$\\ $$ |   $$ |$$  _____|$$  __$$\\  \n");
    printf("$$ /  \\__|$$ /  $$ |$$$$\\  $$$$ |$$ |            $$ /  $$ |$$ |   $$ |$$ |      $$ |  $$ | \n");
    printf("$$ |$$$$\\ $$$$$$$$ |$$\\$$\\$$ $$ |$$$$$\\          $$ |  $$ |\\$$\\  $$  |$$$$$\\    $$$$$$$  | \n");
    printf("$$ |\\_$$ |$$  __$$ |$$ \\$$$  $$ |$$  __|         $$ |  $$ | \\$$\\$$  / $$  __|   $$  __$$<  \n");
    printf("$$ |  $$ |$$ |  $$ |$$ |\\$  /$$ |$$ |            $$ |  $$ |  \\$$$  /  $$ |      $$ |  $$ | \n");
    printf("\\$$$$$$  |$$ |  $$ |$$ | \\_/ $$ |$$$$$$$$\\        $$$$$$  |   \\$  /   $$$$$$$$\\ $$ |  $$ | \n");
    printf(" \\______/ \\__|  \\__|\\__|     \\__|\\________|       \\______/     \\_/    \\________|\\__|  \\__| \n");
    printf("\n");                                                                                    
                                                                                                    
    
}


//Crear marco para el juego.
void marco()
{
    int FilaSuperior = 5, FilaInferior = 25;
    int ColumnaIzquierda = 20, ColumnaDerecha = 100;
    //va de la  columna izquierda a la derecha. Aumenta la x y se mantiene en  la misma altura. Imprime en las dos filas.
    for(int x = ColumnaIzquierda;  x <= ColumnaDerecha; x++){
        gotoxy(x,FilaSuperior);
        printf("#");
        gotoxy(x, FilaInferior);
        printf("#");
    }
    //Va de la fila de arriba hasta la de  abajo. En la  misma columna y aumenta la fila. Imprime en las dos columnas.
    for(int y = FilaSuperior; y <= FilaInferior;  y++){
        gotoxy(ColumnaIzquierda, y);
        printf("#");
        gotoxy(ColumnaDerecha, y);
        printf("#");
    }    
}

//Crear manzana
/*Criterios: No puede generarse fuera del recuadro, no  puede generarse en una  posicion que este la serpiente y tiene que generar 
otra manzana unicamente cuando la  serpiente haya pasado  por  su posicion*/
void  manzana(int *x, int *y, int *contadormanzanas, int *x_manzana, int *y_manzana,  int *longitud){

    srand(time(NULL));
    //tengo que generar dos  numeros, el de la x y el de la y. tienen  que estar dentro del recuadro. 
    int min_x_manzana = 21;
    int max_x_manzana = 99; 
    int min_y_manzana = 6;
    int max_y_manzana = 24;
    

    if(*x_manzana == *x && *y_manzana == *y){//solo genera una nueva manzana cuando la serpiente la a comido
        
        *x_manzana = min_x_manzana + rand() % (max_x_manzana - min_x_manzana + 1);
        *y_manzana = min_y_manzana + rand() % (max_y_manzana - min_y_manzana + 1);
        *contadormanzanas += 1;
        *longitud += 1;
       
    }
   
    gotoxy(*x_manzana, *y_manzana);
    setColor(RED);
    printf("O");

}
/*borrar posicones por  donde  ha pasado la serpiente, dejamos las 3 ultimas posicones sin  borrar, que despues cuando 
se coma la manzana ya no se dejaran los 3 ultimos si no los  4  ultimos y asi. 
1.Acceder a las posiciones, imprimir espacio, controlar que deje sin borrar dependiendo  las manzanas comidas.*/

/*Quiero acceder a la  primera posicio de X Y y imprimir espacio*/
void borrarrastro(int *posicionesX, int *posicionesY, int *contadorX, int *contadorY, int *longitud)//aqui  me  quede
{   
    if (*longitud > 0) {
        int indice_borrar = (*contadorX - *longitud + 500) % 500; // si contador -  longitud es negativo se  le suman 500, si se va  a salir del array % 500 para que empiece de nuevo
        gotoxy(posicionesX[indice_borrar], posicionesY[indice_borrar]);
        printf(" ");
    }
}

/*Colision de la serpiente, para que termine el juego. Si la ultima  posicion de x y es igual alguna anterior hay colision */
void colisionserpiente(int *contadorX, int *contadorY, int *longitud, int *posicionesX, int *posicionesY, bool *colision)
{
    //posicion donde esta  la cabeza de la serpiente
    int cabezaX = posicionesX[*contadorX - 1];  
    int cabezaY = posicionesY[*contadorY - 1];

    for(int i = 1; i < *longitud; i++){ //i=1 porque i=0 es la primera posicion de  la  cabeza
                
        // restamos uno  para estar en la  cabeza y i para ir a las posciones anteriores del  array de las posiciones
        int cuerpo_serpiente = (*contadorX - 1 - i + 500) % 500; //bufer circular

        if(posicionesX[cuerpo_serpiente] == cabezaX && posicionesY[cuerpo_serpiente] == cabezaY){
            
            *colision = true; 
        }

    }
}

//Posiones  por  donde  pasa la serpiente guardadas en arrays
void guardarposicion(int *x, int *posicionesX, int *contadorX, int  *contadorY, int *y, int *posicionesY, int *longitud)
{
    posicionesX[*contadorX] = *x;//se asiga el valor en la  posicon del contador y luego se aumenta. 
    posicionesY[*contadorY] = *y;
   

    // Evitar el desbordamiento usando módulo
    *contadorX = (*contadorX + 1) % 500;
    *contadorY = (*contadorY + 1) % 500;
}

/*Puedo enfocar esto de dos formas, la mas sencilla creo que es imprimir  un  unico caracter, porque si no cuando cambia de direccion
la impresion se hace en horizontal y los cambios para  solucionar eso es mas dificil que hacer lo siguiente.
La serpiente, solo va ha imprimir un unico caracter. La serpiente pasa por diferentes posicones y imagina que  tiene en un contador
5 manzanas comidas,  entonces yo voy a borrar todas las posicones por donde  ha pasado menos  esas ultimas 5 + la  primera 6.  */
void PrintSerpiente(){
    setColor(BLUE);
    printf("S");
}

//Mensaje contador
void mensajecontador(int *contadormanzanas){
    gotoxy(3,2);
    setColor(MAGENTA);
    printf("Manzanas comidas: %d", *contadormanzanas);

}



//Movimiento de la  serpiente
void serpientemovimiento(int *x,  int *y, int ColumnaIzquierda, int ColumnaDerecha, int FilaInferior, int FilaSuperior, int  *tecla, int *posicionesY, int *contadorY, int *posicionesX, int *contadorX, int *contadormanzanas, int *x_manzana, int *y_manzana, int *longitud, bool *colision)
{   
    int nuevaTecla, teclaAnterior;
    borrarrastro(posicionesX, posicionesY, contadorX, contadorY, longitud);
    guardarposicion(x, posicionesX, contadorX, contadorY, y, posicionesY, longitud);

    while((*x > ColumnaIzquierda && *x < ColumnaDerecha) && (*y > FilaSuperior &&  *y < FilaInferior  &&  *colision == false)) {  //controla las paredes  
        
        if (kbhit()) {
            nuevaTecla = getkey();

            if ((nuevaTecla == KEY_UP && teclaAnterior != KEY_DOWN) ||
                (nuevaTecla == KEY_DOWN && teclaAnterior != KEY_UP) ||
                (nuevaTecla == KEY_LEFT && teclaAnterior != KEY_RIGHT) ||
                (nuevaTecla == KEY_RIGHT && teclaAnterior != KEY_LEFT)) {
                *tecla = nuevaTecla;
                teclaAnterior = nuevaTecla;
            }
        }

        switch (*tecla) {
            case KEY_UP:
                *y -= 1;
                break;
            case KEY_DOWN:
                *y += 1;
                break;
            case KEY_LEFT:
                *x -= 1;
                break;
            case KEY_RIGHT:
                *x += 1;
                break;
        }

        gotoxy(*x, *y);
        PrintSerpiente();
        Sleep(150); 
        borrarrastro(posicionesX, posicionesY, contadorX, contadorY, longitud);
        guardarposicion(x, posicionesX, contadorX, contadorY, y, posicionesY, longitud);
        manzana(x, y, contadormanzanas, x_manzana, y_manzana, longitud);
        mensajecontador(contadormanzanas);
        colisionserpiente(contadorX, contadorY, longitud, posicionesX, posicionesY, colision);
    }
}
