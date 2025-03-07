#include <stdio.h>
#define MAX 100

int pedirnumeros(int v[]);
void contadorDeNumeros(int v[], int v_anteriores[], int i);


/*. (ComptaQuantesVegades) Definir un vector de 100 caselles. Posteriorment,
es demanarà números a l’usuari mentre que aquest no introdueixi un -1; això
vol dir que pot introduir la quantitat de números que vulgui. Els números
vàlids estaran compresos entre el 0 i el 99. Al finalitzar el programa, ens ha
d’indicar quantes vegades s’han introduït cadascun dels números vàlids.*/

/*Resumen: Definir  vector de 100 casillas, pedir numeros al usuario hasta que ponga -1 o llegue al final del  vector. 
Rango de numeros del 0-99. Indicar cuantas veces  se han introducido un  mismo numero.
*/


int main(){

    int v[MAX] = {};
    int i;
    int v_anteriores[MAX] = {};
    i = pedirnumeros(v); //usamos parametro  para usar i en la  siguiente funcion 
    contadorDeNumeros(v, v_anteriores, i);



    getch();
    return 0;
}

int pedirnumeros(int v[])
{
    int numero, i = 0;

    while(numero != -1 && i != MAX){

        do{
            printf("Introdueix un numero: ");
            scanf("%d", &numero);
        }while(numero > 99 && numero < 0);

        v[i] = numero;
        i++;

    }

    return i;
}

/*Tengo que contar cuantas  veces sean repetido los numeros del vector y no volver a contar el  mismo numero que  estara en algun  indice siguiente
Tengo que comparar el  primer elemento con los demas y sumar al contador, imprimir numero:numeroveces. Despues el contador otra vez a cero y
comparamos el siguiente elemento con los  que faltan, si vamos a comparar un elemento que ya esta guardado en  nuestro nuevo vector lo 
saltaremos, para no contar los numeros mal.
Primero  un bucle para el nuevo vector  y dentro otro bucle  que recorra  el vector que tiene  los numeros  introducidos */


void contadorDeNumeros(int v[], int v_anteriores[], int i)
{   
   

    for(int j = 0; j <= i; j++){ //recorre hasta  el valor de  i que es el  numero de  indices del vector

        //variables  que se reinician a   0 en cada vuelta 
        int contador = 0;
        int serepite = 0;

        //comprueva  si el elemento del vector  es igual algun anterior.
        for(int l = 0; l <= j; l++){

            if(v[j] == v_anteriores[l] || v[j] == -1){ //si el elemento del  vector es igual algun elemento anterior o es -1 decimos que se repite.
                serepite  =  1;
            }

        }
        //si no se  repite comparamos el elemento del vector con todos los indices  del vector
        if(serepite == 0){
            for(int k = 0; k <= i; k++){

                if(v[j] == v[k]){ //compara el primer elemento del  vector con los  demas.
                    contador += 1;
                }
                
            }
            v_anteriores[j] = v[j];  //se  asigna el valor  del vector  para asi poder compararlo al futuro y ver si se repite
            printf("\n%d:%d", v[j], contador); //se muestra el numero : numero de veces
        }

    }



}