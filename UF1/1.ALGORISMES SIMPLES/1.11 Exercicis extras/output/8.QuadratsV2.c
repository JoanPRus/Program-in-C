#include <stdio.h>
#include <rlutil.h>
#include <time.h>


/*Fer el mateix exercici que l’anterior, però només es pintaran d’un nou color les
caselles que no formen part dels quadrats anteriors. Cal també controlar que
no tinguem dos requdres consecutius amb el matei color. Es farà un quadrat
màxim de 25 X 25. Entre quadrat i quadrat es deixarà un temps de 100 ms*/
int main(){

    /*Generar cuadros  despues de pulsar  una  tecla. Generar color diferente al anterior.
    Usar getch para pulsar  la tecla. Tiene que partir de 1,1  hacer cuadros  hasta el 25 x  25. 
    es decir el primer cuadro aumenta  uno  la  x y despues uno la y, despues vuelta a la  posicon inicial  pero baja uno. */

    srand(time(NULL));

    int x_inicio = 0,  y_inicio = 0, y_memoria = 0,  color_anterior = -1; 
   
    int  color =  rand() % 15 + 1;
    setBackgroundColor(color);
    gotoxy(1, 1);
    printf(" "); //el primer  cuadrado
    

    for(int  i = 1;  i <= 25; i++){
        x_inicio = 1;//siempre inicia en 1
        y_inicio += 1; //baja uno  en  cada  vuelta
        gotoxy(x_inicio, y_inicio);
       
        do{
            color = rand() % 15 + 1;
        }while(color == color_anterior);
        color_anterior = color; // Actualiza el color anterior
        setBackgroundColor(color);

        //puedo usar  dos  bucles para pintar los  cuadrados.  

        while(x_inicio < i){

            gotoxy(x_inicio, y_inicio);
            printf(" ");
            Sleep(150);
            x_inicio += 1;
            
        }
        y_memoria = y_inicio;

        while(i > 1  && y_inicio > 0){

            gotoxy(x_inicio, y_inicio);
            printf(" ");
            Sleep(150);
            y_inicio -= 1;
        }
        y_inicio = y_memoria;

        getch();//pulsar cualquier tecla para dar la siguiente vuelta. 
    }

    return 0;
}