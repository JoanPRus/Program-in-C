#include <stdio.h>
void pedirficha(const char *mensaje, int vector[], int vficha[]);
void comparacionfichas(int vficha1[], int vficha2[]);

/*1. Demanar dues fitxes del dominó i
determinar si es poden ajuntar o no. Una
fitxa del dominó consta de dos números que
estan compresos entre 1 i 6. Les dues fitxes
no poden ser iguals; en cas que ho siguin es
demanarà novament la segona fitxa fins que
no siguin iguals. Cal resoldre l’exercici amb
dues variables per a cada una de les fitxes.
Resolt l’exercici desant cada una de les fitxes en un vector de dues caselles*/



int main(){
   
    int vficha1[2] = {};
    int vficha2[2] = {};
    
    pedirficha("primera", vficha1, vficha1);
    pedirficha("segunda", vficha1, vficha2);
    comparacionfichas(vficha1, vficha2);



    getch();
    return 0;
}


void comparacionfichas(int vficha1[], int vficha2[]){

    //si coincide un numero de una ficha con la otra se pueden juntar. 

    if(vficha1[0] == vficha2[0] || vficha1[0] == vficha2[1] || vficha1[1] == vficha2[0] || vficha1[1] == vficha2[1]){

        printf("Las fichas [%d|%d] y [%d|%d] si se pueden juntar.", vficha1[0], vficha1[1], vficha2[0], vficha2[1]);
    }else printf("Las fichas [%d|%d] y [%d|%d] no se pueden juntar.", vficha1[0], vficha1[1], vficha2[0], vficha2[1]);

  
}

void pedirficha(const char *mensaje, int vector[], int vficha[]){ //estructura para escribir mensajes como parametro  en una funcion

   int numero1, numero2;
    do{
        printf("Introduce la %s ficha del domino: ", mensaje);
        scanf("%d %d", &numero1, &numero2);
    }while(numero1 > 6 || numero1 < 1  || numero2 > 6 || numero2 < 1 ||
        (vector[0] == numero1 &&  vector[1] == numero2) || (vector[0] == numero2 && vector[1] == numero1));
    vficha[0] = numero1;
    vficha[1] = numero2;
}
