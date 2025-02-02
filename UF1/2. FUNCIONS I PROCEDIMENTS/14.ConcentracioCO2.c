#include <stdio.h>
#include <rlutil.h>
#include <time.h>
#include <stdlib.h>
void diadelmes();
int horadeldia(j);
int concentracioCO2();
void imprime(int j, int i, int numeroConcentracio);

/*(Concentracions de CO2)
Volem simular les lectures de concentració de CO2 de l’ambient, durant el mes
de gener; tenint en compte que es pren una mesura cada hora. La
concentració és un paràmetre que oscil·la entre els valors: 10 i 100.
Es demana, mostrar les concentracions hora a hora i dia rere dia del mes de
gener.
Per a poder visualitzar millor la informació, mostrarem un dia amb les seves
24 hores, i per a continuar, caldrà prémer una tecla i netejar la pantalla.
El programa també ens haurà de mostrar en color vermell aquelles
concentracions que superin el llindar de 50, però només les que es produeixen
dins del periòde que va des de les 10h del dia 12 fins a les 15h del dia 20
(ambdues incloses)*/

/*Simular lecturas de CO2  se miden  cada hora, durante el mes de enero. Valores 10-100 generar. Mostrar las 24 horas, 
para pasar pulsar tecla y  limpiar pantalla. Marcar de color rojo los resultados  mas de 50 en el periodo de 10h del dia 12
hasta las 15h del dia 20. */

int main(){
    
    srand(time(NULL));
    diadelmes();
    
    getch();
    return 0;
}

//bucle para  los dias de enero, llamamos a otra funcion que tiene un bucle para las horas
void diadelmes()
{
    
    for(int j = 1; j <= 31; j++){
        printf("\n\nDia %d\n", j);
        horadeldia(j);
        getch();
        cls();
    }

       
}

//controla  la hora,  la  concentracion de  CO2 y imprime el mensaje
int horadeldia(j)
{   
    int numeroConcentracio;  
    for(int i = 0; i <= 23; i++){
        numeroConcentracio = concentracioCO2();
        imprime(j, i, numeroConcentracio);
    }

    return imprime;
}

//genera la concentracion CO2
int concentracioCO2()
{   

    int max = 100, min = 10;   
    int numeroConcentracio = min + rand() % (max - min + 1); //genera  los numeros en un  rango. 
    
    return numeroConcentracio; 
}

//imprime el mensaje con ciertas  condiciones
void imprime(int j, int i, int numeroConcentracio)
{   
    //Nota:  j = dia, i = hora
    if(((j > 12 && j < 20 ) || (j == 12 && i >= 10) || (j == 20  && i <= 15)) && numeroConcentracio > 50){
        setColor(RED);
        printf("\n[%02d]: %02d", i, numeroConcentracio);
    }else{
        setColor(WHITE); 
        printf("\n[%02d]: %02d", i, numeroConcentracio);
    }
}