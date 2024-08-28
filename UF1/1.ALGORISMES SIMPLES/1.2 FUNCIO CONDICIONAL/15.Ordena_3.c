#include <stdio.h>
#include <string.h>

/*(Ordena_3) Fer un algoritme que demani a l’usuari tres números naturals. El
programa ha de mostrar els tres números ordenats de menor a major. 
*/

int main() {

    int num1 = 0, num2 = 0, num3 = 0;

    printf("Introdueix tres nombres naturals: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    //Hi ha moltes opcions posibles. En aquest cas es fact(3) == 3!=3×2×1=6
    /*Hi ha 6 posibilitats: Para no perdernos fijamos el primer elemento y permutamos los demas,
    despues cambiamos  el primer elementendo y volvemos a permutar los demas. 

    Opcions: 
        num1, num2, num3
        num1, num3, num2
        num2, num1, num3
        num2, num3, num1
        num3, num1, num2
        num3, num2, num1
    */

   //los ordena de mayor a menor (no lo voy a cambiar). Se puede mejorar el codigo

   if ( num1 > num2 && num2 > num3) {
    printf("%d %d %d", num1, num2, num3);
   } else  if ( num1 > num3 && num3 > num2) {
    printf("%d %d %d", num1, num3, num2);
   } else  if ( num2 > num1 && num1 > num3) {
    printf("%d %d %d", num2, num1, num3);
   } else  if ( num2 > num3 && num3 > num1) {
    printf("%d %d %d", num2, num3, num1);
   } else  if ( num3 > num1 && num1 > num2) {
    printf("%d %d %d", num3, num1, num2);
   } else  if ( num3 > num2 && num2 > num1){
    printf("%d %d %d", num3, num2, num1);
   }

    getch();
    return 0;
}