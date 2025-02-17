#include <stdio.h>
#include <stdlib.h> //rand()
#define MAX 6
int demanarnumero();
void promigvector(int v[], int num);
void generarvector(int num, int v[]);
void NumeroMesGranGenerat(int num, int v[]);
/*(Promig) A partir d’un vector de 6 caselles, demanar a l’usuari un nombre
comprés entre 0 i 6 i omplir tantes caselles com aquest número indiqui. El
valor de les caselles seran valors aleatoris compresos entre 0 i 10. Es demana
fer un programa que calculi el valor promig dels números aleatoris generats*/

//tambien decir que numero generado aleatoriamente es el mas  grande

int main(){
    int num;
    int v[MAX] = {};
    num = demanarnumero();
    generarvector(num, v);
    promigvector(v, num);
    NumeroMesGranGenerat(num, v);


    getch();
    return 0;
}

int demanarnumero(){

    int num;

    do{
        printf("Introdueix un  numero del 0-6: ");
        scanf("%d", &num);
    }while(num > 6 || num < 0);

    return num;
}

void generarvector(int num, int v[])
{
    int numaleatorio;
    for(int i = 0; i < num; i++){

        numaleatorio =  rand() % 11;
        v[i] = numaleatorio;

        printf("\n[%02d]: %d", i, v[i]);
    }
}

void NumeroMesGranGenerat(int num, int v[])
{
    int numerogran = 0;
    for(int i = 0; i < num; i++){
        
        if(numerogran < v[i]){
            numerogran = v[i];
        }
    }

    printf("\n\nEl numero mes  gran es %d.", numerogran);
}

void promigvector(int v[], int num)
{
    int suma = 0, promig;

    for(int i = 0; i < num; i++){

        suma += v[i];
    }

    if(num > 0){
        promig  = suma / num;
        printf("\n\nEl promig es %d",  promig);
    }

}