#include <stdio.h>


/*(ComptaEndavant) Mostra per pantalla els números des del 0 fins al 10,
utilitzant cadascun dels bucles : while, for i do while. Fixa’t que tots els
números estan separats per guions exceptuant el darrer.
Resultat:
0 - 1 – 2 – 3 – 4 – 5 – 6 – 7 – 8 – 9 – 10*/

// hay una manera mas facil y es poniendo una condicion para que imprima el guion si no es el ultimo numero
int main() {

    int num1 = 0;
    int num2 = 10;

   /* while (num1 <= 9) {
        printf("%d-", num1);
        num1++;
    } while (num1 <= 10){
        printf("%d", num1);
        num1++;
    }*/

   /* for (int i = num1; i < num2; i++){
        printf("%d-", i);
        num1++;
    } for(int i = num1; i <= num2; i++){
        printf("%d", i);
    }*/

   do {
    printf("%d-", num1); 
    num1++;
   } while (num1 < num2);
   
   do {
    printf("%d", num1);
    num1++;
   } while (num1 <= num2);








    getch();
    return 0;
}