#include <stdio.h>

/*(Serie): Calcular les 10 primeres potències de 4.*/

int main(){


    //Para  calcular las 10 primeras potencias de 4 puedo hacer un bucle. 

    int base = 4;
    int resultats = 1;
    

    for (int i = 1; i <= 10; i++){ // i nos sirve para ir marcando la potencia
        
        printf("\n%d^%d = %d", base, i, base * resultats);  //calculamos y imprimimos
        resultats  *= base; //actualiza los resultados pasa de 1 a 4 y de 4 a 16...
    }




    getch();
    return 0;
}


