#include <stdio.h>


/*(TaulaBinari): Escriu un programa que mostri una taula amb les 11 primeres
potències de base 2 (començant amb l’exponent 0 i acabant amb l’exponent
10). Al marge del seu valor decimal, caldrà mostrar també el seu valor en
binari.
Exemple:
2^0 = 1 base 10 = 1 base 2
2^1 = 2 base 10 = 10 base 2
2^2 = 4 base 10 = 100 base 2
2^3 = 8 base 10 = 1000 base 2
...
2^10 = 1024 base 10 = 10000000000 base 2*/

int main(){

    int base = 2,  resultat = 1;
    int binari[50];
    int index, memoria; 

    for(int i = 0; i <= 10; i++){//bucle  para las potencias del 0 al  10

        if(i > 0){
            resultat *= base; //multiplica  el resultado anterior por dos,  si es i = 0 el  resultado  es  1. 
        }

        printf("%d^%d = %d = ",  base, i, resultat);

        //pasamos el numero a binario.  resto  de la division hasta 1/2. 

        memoria = resultat;
        index = 0; // importante restablecer el indice en cada vuelta del primer for
    
        while(memoria > 0){  //si  memoria es  mayor que 0 se ejecuta el  bucle
            binari[index] = memoria % 2;  //se guarda el resto en un  array
            memoria /= 2;  //se divide  el numero
            index++; //pasamos al siguiente indice del array
        }

        for(int j = index - 1; j >= 0; j--){ //se recorre  el  array  del final al  principio
           
            printf("%d", binari[j]);
        }

         printf("\n"); //salto de  linea para la siguiente vuelta. 


    
    }

    getch();
    return 0;
}