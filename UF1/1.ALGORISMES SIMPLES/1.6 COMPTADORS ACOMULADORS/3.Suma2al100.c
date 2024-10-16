#include <stdio.h>


/*(Suma2al100) : Sumar els números parells compresos entre el 2 i el 100.
La suma total del números parell es: 2550*/

int main(){

    
    int suma_parells = 0;

    for (int i = 2;  i <= 100; i++){

        if (i % 2 == 0){
            suma_parells += i;
            
        }

    } printf("%d", suma_parells);

    getch();
    return 0;
}
