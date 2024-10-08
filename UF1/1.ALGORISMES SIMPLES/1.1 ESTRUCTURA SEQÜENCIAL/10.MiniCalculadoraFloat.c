#include <stdio.h>
#include <string.h>


int main() {

/*(MiniCalculadoraFloat) Fer un programa que demani dos nombres amb
decimals a l’usuari i mostri per pantalla la seva suma, resta, multiplicació i
divisió.
*/

float num1, num2;

printf("Introdueix dos nombres deixan un espai: ");
scanf("%f %f", &num1, &num2);

printf("\n%.2f + %.2f = %.2f", num1, num2, num1 + num2);
printf("\n%.2f - %.2f = %.2f", num1, num2, num1 - num2);
printf("\n%.2f * %.2f = %.2f", num1, num2, num1 * num2);
printf("\n%.2f / %.2f = %.2f", num1, num2, num1 / num2);

getch();
return 0; 

}