#include <stdio.h>


int main() {

    /*(DiaSetmana) Fer un programa, que demani a l’usuari un número que
    representa un dia de la setmana i ens mostri per pantalla quin dia de la
    setmana és. Caldrà controlar del fet que el dia introduït per l’usuari no sigui
    vàlid.
    */

   int dia;

   printf("Introdueix un numero (representa el dia de la setmana): ");
   scanf("%d", &dia);
   switch (dia)
   {
    case 1:
        printf("Resultat: El dia %d es Dilluns", dia);
        break;
  
    case 2:
        printf("Resultat: El dia %d es Dimarts", dia);
        break;
    
    case 3:
        printf("Resultat: El dia %d es Dimecres", dia);
        break;
    
    case 4:
        printf("Resultat: El dia %d es Dijous", dia);
        break;
    
    case 5:
        printf("Resultat: El dia %d es Divendres", dia);
        break;

    case 6:
        printf("Resultat: El dia %d es Disabte", dia);
        break;

    case 7:
        printf("Resultat: El dia %d es Diumenge", dia);
        break;
    
    default:
        printf("Resultat: El dia %d no es valid", dia);
        break;
    }
    return 0;
}