#include <stdio.h>
#include <string.h>

  
    int main() {
  /*(MiniCalculadoraInt) Fer un programa que demani dos nombres enters a
    l’usuari i mostri per pantalla la seva suma, resta, multiplicació, divisió sencera
    i el residu.*/

    int num1, num2;

    printf("Introdueix dos nombres enters deixan un espai: ");
    scanf("%d %d", &num1, &num2);

    printf("\n%d + %d = %d", num1, num2, num1 + num2);
    printf("\n%d - %d = %d", num1, num2, num1 - num2);
    printf("\n%d * %d = %d", num1, num2, num1 * num2);
    printf("\n%d / %d = %d", num1, num2, num1 / num2);
    printf("\n%d %% %d = %d", num1, num2, num1 % num2);

    getch();
    return 0; 

}