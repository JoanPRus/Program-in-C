#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {

    /*(Laborable) Fer un programa, que demani a l’usuari un número que
    representa un dia de la setmana i ens mostri per pantalla si és dia laboral o
    no. Suposarem que el número introduït està acotat entre 1 i 7.*/

    // Declaro variables y tipo de dato. 
    int dia;
    bool preguntaDeNuevo = false;
    //Le pregunto un numero y si esta en el rango 1-5 es laboral, 6-7 festivo.

    do{
        printf("Introduce un numero del 1-7: ");
        scanf("%d", &dia);
        if(dia <1 || dia >7) {preguntaDeNuevo = true; printf("Tienes que poner un dia habil\n");}
        else { preguntaDeNuevo = false; }
    }while (preguntaDeNuevo); // En el do while mientras se cumpla la condicion se repetira el bucle

    if (dia>0 && dia<6) {    
        printf("Resultat: El dia %d es laboral", dia);
    } else if (dia>0 && dia<8) {  
        printf("Resultat: El dia %d es festiu", dia);
    }

    getch();
    return 0;
}