#include <stdio.h>
#include <string.h>

/*(Reduccio) Escriu un programa que demani a l’usuari un nombre i li resti el
15%. El número ha de quedar modificat amb aquest 15% menys. A
continuació mostra el resultat per pantalla.
*/

int main(){

float num,descompte;

printf("Introdueix un numero: ");
scanf("%f", &num);

descompte = num * (1.00 - 0.15); //podem posar directament el 0.85

printf("Descomptant el 15%% queda: %.2f", descompte);






    return 0;

}  