#include <stdio.h>


/* (Comptador-Suma parell-senar) Fer un algoritme que demani 10 números
enters a l’usuari. El programa ha de mostrar per pantalla la quantitat i la suma
de tots els números parells i la quantitat i la suma de tots els números senars
introduïts per l’usuari
Introdueix el numero (1):34
Introdueix el numero (2):1
Introdueix el numero (3):3
Introdueix el numero (4):5
Introdueix el numero (5):-3
Introdueix el numero (6):5
Introdueix el numero (7):2
Introdueix el numero (8):6
Introdueix el numero (9):7
Introdueix el numero (10):4
Total de numeros parells 4
Suma dels numeros parells 46
Total de numeros senars 6
Suma de numeros senars 18*/

int main(){

    //pedir  10 numeros, mostrarlos en pantalla, contar los numeros pares y impares.
    //Sumar los numeros  pares  y sumar los numeros impares. 

    int valors[10]; //usamos un  array para guardar los valores
    int suma_parells = 0;
    int suma_senars = 0;
    int senars = 0;
    int parells = 0;

    for (int i = 0; i < 10;  i++){
        printf("\nIntrodueix el numero (%d): ", i+1); //introducimos los 10 numeros i+1 para el formato
        scanf("%d", &valors[i]); //guardamos los valores
        
    }

    for (int i = 0; i < 10; i++){   //recorremos el indice, que siempre empieza  en 0
        
        if (valors[i] % 2 == 0){ //condicion que determina si es par con  el resto = 0

           suma_parells += valors[i]; //suma los pares
           parells++; //cuenta los numeros que hay pares, por las veces que cumple la  condicion 
           
     
            
        } else if (valors[i] % 2 != 0){ //condicion para impar 
            suma_senars += valors[i]; //suma los  impares
            senars++; //cuenta  los numeros que  hay impares por las veces que cumple la condicion
        }
    
    }
    {
        printf("\nTotal de numeros parells %d", parells);
        printf("\nSuma dels numeros parells %d", suma_parells);
        printf("\nTotal de numeros senars %d", senars );
        printf("\nSuma dels numeros senars %d", suma_senars);
        printf("\nPrem una tecla per finalitzar");
       }
         

    getch();
    return 0;
}