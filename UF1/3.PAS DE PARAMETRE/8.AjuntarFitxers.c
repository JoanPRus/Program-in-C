#include <stdio.h>
void resultado(int *num1, int *num2, int *num3, int *num4);
void pedirsegundaficha(int *num1, int *num2, int *num3, int *num4);
void  pedirprimeraficha(int *num1, int *num2);


/* (AjuntarFitxes) Demanar dues fitxes del
dominó i determinar si es poden ajuntar o no.
Una fitxa del dominó consta de dos números
que estan compresos entre 0 i 6. Les dues fitxes
no poden ser iguals; en cas que ho siguin es
demanarà novament la segona fitxa fins que no
siguin iguals. Fixeu-vos que alhora de demanar
la carta es demanen simultàniament la part de
dalt i la part de sota. */


/*Resumen: Tengo que pedir dos fichas  del domino y decir si se  pueden juntar o no. 
La parte de arriba y la de abajo van en  la  misma entrada, luego se pide la segunda carta.
Condiciones, la  segunda carta no  puede  tener los dos mismos numeros que la anterior, da igual su orden.
Si pasa eso se vuelve a pedir la segunda carta. 
Si tienen un  numero en comun  si se pueden juntar.
Si no tienen ningun  numero en  comun  no  se pueden juntar*/

int main(){
    int num1,num2,num3,num4;

    pedirprimeraficha(&num1, &num2);
    pedirsegundaficha(&num1, &num2, &num3, &num4);
    resultado(&num1, &num2, &num3, &num4);

    getch();
    return 0;
}

void  pedirprimeraficha(int *num1, int *num2)
{   

    do{
        printf("Introdueix la primera ficha: ");
        scanf("%d %d", num1, num2);

    }while(*num1 > 6 || *num2 > 6);
}

void pedirsegundaficha(int *num1, int *num2, int *num3, int *num4)
{
    do{
        printf("Introdueix la segona ficha: ");
        scanf("%d %d", num3, num4);
    }while((*num3 > 6 || *num4 > 6) || (*num3 == *num1 || *num3 == *num2) && (*num4 == *num1 || *num4 == *num2)); //numeros  iguales repite  el bucle
}

void resultado(int *num1, int *num2, int *num3, int *num4)
{
    if((*num3 != *num1 && *num3 != *num2) && (*num4 != *num1 && *num4 != *num2)){ //ninguna  carta es  igual 
        printf("Las fichas no se pueden juntar.");
    }else printf("Las fichas se pueden juntar.");
}