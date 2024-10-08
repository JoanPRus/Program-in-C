#include <string.h>
#include <stdio.h>

//Orden tres numeros de mayor a  menor

int main(){

    //variables per intercanviar el numeros y ordenar-los

    int num1, num2, num3, aux;

    printf("Introdueix tres numeros: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    /* Si la condicion se cumple hacemos lo siguiente: El numero mas bajo se almacena en aux.
    Intercanviamos el valor de la variable que tenia el numero mas bajo con la variable 
    que tenia el numero mas alto. La variable que al principio tenia el numero mas alto ahora
    obtiene un nuevo numero que es el aux */
    if (num1 < num2 ) {
        aux = num1;
        num1 = num2;
        num2 = aux;
    }
    if (num2 < num3) {
        aux = num2;
        num2 = num3;
        num3 = aux;
    }
    if (num1 < num2) {
        aux = num1;
        num1 =num2;
        num2 = aux;
    }

    printf("%d %d %d", num1, num2, num3);

    getch();
    return 0;
}