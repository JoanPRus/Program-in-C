#include <stdio.h>

/*Donat un nombre positiu, es demana calcular la
quantitat de dígits que té
Introdueix el numero: 4567
El numero te 4 caracters
Prem una tecla per finalitzar*/

int main(){

    //tenemos que pedir  un numero al usuario y debemos de saber los digitos que  tiene. 
    //podemos dividir el numero introducido  entre 10 y contar  las veces que ha hecho la operacion

    int numeros;
    int contador = 0;

    printf("Introdueix un nombre positiu: ");
    scanf("%d", &numeros);

    while (numeros != 0){
        
        numeros /= 10;
        contador++;
    }  
    {
        printf("El numero te %d caracteres", contador);
        printf("\nPrem una tecla per finalitzar");
    }







    getch();
    return 0;
}