#include <stdio.h>

/* (Factorial): Calcula el factorial del número natural introduit per teclat.
Exemple:
Número:6
Resultat: 720
Aclariment:
Res=1
Res=1*1=1
Res=1*2=2
Res=2*3=6
Res=6*4=24
Res=24*5=120
Res=120*6=720*/

int main(){

    /*el factorial es el numero introducido multiplicado por 
    los numeros que esta detras de el  hasta  el 1*/

    //primero le pedimos al usuario el numero, despues hacemos un for y imprimimos el resultado final. 

    int numero_usuari = 0;
    int resultat_numero = 1;
    int resultat_total; 

    printf("Introdueix un numero natural: ");
    scanf("%d", &numero_usuari);

    for (int i = 1; i <= numero_usuari; i++){ // i  llega hasta el  numero usuario lo recorre

        printf("\nRes = %d * %d = %d", resultat_numero, i, resultat_numero * i); //imprime todos los pasos

        resultat_numero *= i; // operacion para el factorial 
        

    } printf("\n resultat final %d", resultat_numero);



    getch();
    return 0;
}