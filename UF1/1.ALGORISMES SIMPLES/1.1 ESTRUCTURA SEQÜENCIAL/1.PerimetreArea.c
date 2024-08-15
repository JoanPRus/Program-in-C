#include <stdio.h>
#include <string.h>

int main() {
/*1. (PerimetreArea) Demana l’amplada i la llargària d’un rectangle i calcula el
seu perímetre i la seva àrea. El perímetre és la suma dels costats i l’àrea la
multiplicació de de l’amplada per la llargària*/

float amplada, llargaria; 


printf("Introdueix l'amplada: ");
scanf("%f", &amplada);

printf("Introdueix la llargaria: ");
scanf("%f", &llargaria);

// %.2f determina el nombre de decimals
printf("La seva area es: %.2f", amplada * llargaria);

printf("\nEl seu perimetre es: %.2f", (amplada + llargaria) * 2 );

return 0; 
}