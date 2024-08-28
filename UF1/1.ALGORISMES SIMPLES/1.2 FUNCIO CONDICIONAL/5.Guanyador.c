#include <stdio.h>

/*(Guanyador) Fer un programa que demani el resultat d’un partit de futbol. El
programa informarà de l’equip guanyador (el primer o el segon). Caldrà
informar del cas que hagin empatat. Cal demanar els dos resultat en el mateix
scanf. Caldrà validar que les els gols siguin vàlids.
*/

int main() {

int gols,gols2;

printf("Resultat del partit (exemple: 5-9): ");
scanf("%d-%d",  &gols, &gols2);
printf("EquipA:%d EquipB:%d",gols,gols2);

if (gols<0 || gols2<0) {
    printf("\nDades inicials incorrectes");
}

 else if (gols > gols2) {
    printf("\nA guanyat el equip A");
} else if (gols < gols2) {
    printf("\nA guanyat el equip B");
} else if (gols == gols2) {
    printf("\nHi ha un empat");

    getch(); 
    return 0;
}
}