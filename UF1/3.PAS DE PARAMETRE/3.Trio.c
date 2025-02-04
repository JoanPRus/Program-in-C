#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void combinacionUsuari(int *num1,  int *num2, int *num3);
void combinacionordinador(int *numero1, int *numero2,  int *numero3);
void imprimecombinacions(int *num1, int *num2, int *num3, int *numero1, int *numero2, int *numero3);
int calculadoraencerts(int *num1, int *num2, int *num3, int *numero1, int *numero2, int *numero3);

/*(Trio) Fer un algoritme per poder jugar al TRIO. Aquest joc tracta de triar
tres números del 0 al 9. Llavors el sistema genera la combinació guanyadora
de tres números. Cal mostrar per pantalla quants encerts ha tingut l’usuari.
S’ha de fer servir únic procediment per tal de generar la combinació
guanyadora i un altre per a obtenir els tres nombres de l’usuari. Els nombres
tant de l’usuari com de la combinació guanyadora no es poden repetir. Per a
calcular el nombre d’encerts, no cal que els nombres estiguin en la mateixa
posició, simplement cal que siguin iguals.
void combinacioGuanyadora(int *,int *,int *)
void combinacioUsuari(int *,int *,int *)
int calculaEncerts(int,int,int,int,int,int)*/

/*Resumen: Pedir al  usuario tres numeros del 0-9, generar otros tres numeros  el ordenador, no se pueden repetir numeros de la combinacion.
Calcular el  numero de  aciertos,  no importa la posicion de los numeros.*/

int main(){
    int  num1, num2, num3, numero1, numero2, numero3, numeroencerts;

    combinacionUsuari(&num1, &num2, &num3);
    combinacionordinador(&numero1, &numero2, &numero3);
    imprimecombinacions(&num1, &num2, &num3, &numero1, &numero2, &numero3);
    numeroencerts = calculadoraencerts(&num1,  &num2, &num3, &numero1, &numero2, &numero3);

    getch();
    return 0;
}



void combinacionUsuari(int *num1,  int *num2, int *num3)
{   
    do{
        printf("\nIntrodueix el  primer numero: ");
        scanf("%d", num1);
    }while(*num1 > 9 || *num1 < 0);
  

    do{
        printf("\nIntrodueix el  segon numero: ");
        scanf("%d", num2);
    }while((*num1 == *num2) || (*num2 > 9 || *num2 < 0));


    do{
        printf("\nIntrodueix el tercer numero: ");
        scanf("%d", num3);
    }while((*num1 == *num3) || (*num2 == *num3) || (*num3 > 9 || *num3 < 0));

}

void combinacionordinador(int *numero1, int *numero2,  int *numero3)
{   
    srand(time(NULL));

    *numero1 = rand() % 10; 
    do{
        *numero2 = rand() % 10;

    }while(*numero1 == *numero2);
        
   do{
        *numero3 = rand() % 10; 
   }while((*numero1 == *numero3) || (*numero2 == *numero3));
   
}

void imprimecombinacions(int *num1, int *num2, int *num3, int *numero1, int *numero2, int *numero3)
{
    printf("\nLa combinacio del usuari es: %d %d %d", *num1,  *num2, *num3);
    printf("\nLa combinacio del  ordinador es: %d %d %d", *numero1, *numero2, *numero3);
}

int calculadoraencerts(int *num1, int *num2, int *num3, int *numero1, int *numero2, int *numero3)
{
    int numeroencerts = 0;

    if(*num1 == *numero1 || *num1 ==  *numero2 || *num1 ==  *numero3){
        numeroencerts += 1;
    }if(*num2 == *numero1 ||*num2 ==  *numero2 ||*num2 ==  *numero3){
        numeroencerts += 1;
    }if(*num3 == *numero1 || *num3 == *numero2 || *num3 == *numero3){
        numeroencerts += 1;
    }

    printf("\nEl total de encerts es: %d", numeroencerts);
    return numeroencerts;
}

