#include <stdio.h>


/* (MitjaAritmetica): Calcula la mitjana aritmètica de n valors introduïts per
l’usuari. Finalitzarem d’introduir nombres quan l’usuari introdueixi un -1. El
número -1 no s’ha de tenir en compte per a fer els càlculs. Considerarem que
tots els números introduïts són enters.
Introdueix el numero: -1
No s'ha introduit cap numero valid
Prem una tecla per finalitzar
Introdueix el numero: -5
Introdueix el numero: 6
Introdueix el numero: 4
Introdueix el numero: 9
Introdueix el numero: -1
El promig es 3.50
Prem una tecla per finalitzar*/


int main(){

    /*calcular  la media de los valores introducidos, dejar de pedir numeros escribiendo -1. Consideramos que todos los numeros son enteros. 
    Puedo hacer un for, para pedir numeros hasta que introduzca el -1. 
    Tengo que guardar esos valores, sumarlos  y dividirlos entre el numero de numeros introducidos. Para eso tengo que usar array 
    el problema es que no se usar array dinamico, entonces lo hare con un array fijo para no complicar de momento*/

    int sortida = -1;
    int numero[50];
    int suma_numero =  0;
    float resultat;
    int contador_de_numeros = 0;

  
    for (int i = 0; i < 50; i++){
        printf("Introdueix el numero: "); //pedimos los numeros
        scanf("%d", &numero[i]);  //guardamos los datos

        if (numero[i] == -1){
            printf("Sortida de introduir numeros");
            break; //si  cumple la condicon paramos el for
        }
    
        suma_numero += numero[i];  //operaciones que se ejecutan  despues del if, asi evitamos que sume el -1 y que el  contador sume +1. 
        contador_de_numeros++;
    
    } {
        resultat =  ((float)suma_numero / contador_de_numeros);  //convertimos una variable en float para evitar errores
        printf("\nEl promig es %.2f", resultat);
    }

    getch();
    return 0;
}