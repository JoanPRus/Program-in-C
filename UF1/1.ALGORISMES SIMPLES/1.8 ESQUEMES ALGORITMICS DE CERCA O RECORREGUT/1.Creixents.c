#include <stdio.h>
#include <stdlib.h>

/*(Creixents) Demana números a l’usuari fins que ens introdueixi tres números
creixents consecutius. En el cas que sigui el mateix número; no considerem
que sigui creixent.
Introdueix un numero: 4
Introdueix un numero: 5
Introdueix un numero: 2
Introdueix un numero: 1
Introdueix un numero: 2
Introdueix un numero: 2
Introdueix un numero: 4
Introdueix un numero: 6*/

int main(){

    //Tenemos que  hacer  un programa que pida numeros, y que pare cuando se  hayan  introducido 3 numeros crecientes consecutivamente no iguales

    /*Vamos a crear un array para guardar los numeros y  poder acceder a ellos, un bucle para  pedir los numeros y dos condiciones
    una para comprobar si los numeros son de menor a mayor y otra para  que pare.*/

    int numeros[50]; //array para  guardar los numeros

    for (int i = 0; i < 50; i++){ //bucle para correr el array

        printf("Introdueix un numero: ");
        scanf("%d", &numeros[i]); //guardamos los numeros con su indice en  el array

        if ((numeros[i - 2]) < (numeros[i - 1]) && (numeros[i - 1]) < (numeros[i])){ //condicion que permite verificar los tres ultimos numeros

            printf("Els ultims 3 numeros han  sigut creceixents");
            break;
        }
    }


    getch();
    return 0;
}