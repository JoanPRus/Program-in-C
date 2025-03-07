#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define MAXV1 10
#define MAXV2 10
int PedirCantidadDeElementos();
void rellenarVectores(int v1[], int  v2[], int cantidadv1, int cantidadv2);
void comprobarSisonIguales(int v1[], int v2[], int cantidadv1, int cantidadv2);


/*. (HiSonTots) Defineix dos vectors i cal comprovar si tots els valors del primer
vector estan dins del segon vector. Els dos vectors tindran una capacitat
màxima de 10 elements. Es demanarà a l’usuari quants elements vol omplir
tant del primer com del segon vector. Els valors que s’introduiran són valors
aleatoris entre el 0 i el 10.*/

/*Igual que el anterior pero  con  la diferencia que hay que pedir al usuario el numero de elementos que quiere*/

int main(){

    int v1[MAXV1] = {};
    int v2[MAXV2] = {};
    int  cantidadv1  = 0, cantidadv2 = 0;
 
    srand(time(NULL));
    cantidadv1 = PedirCantidadDeElementos();
    cantidadv2 = PedirCantidadDeElementos();
    rellenarVectores(v1, v2, cantidadv1, cantidadv2);
    comprobarSisonIguales(v1, v2, cantidadv1, cantidadv2);

 

    getch();
    return 0;
}
 
 int PedirCantidadDeElementos()
 {  
    int numeroelementos;
    
    do{
        printf("Introduce la cantidad de elementos: ");
        scanf("%d", &numeroelementos);
    }while(numeroelementos < 1 || numeroelementos > 10);

    return numeroelementos;
 }
 
 void rellenarVectores(int v1[], int  v2[], int cantidadv1, int cantidadv2)
 {  
     printf("Primer vector:");
     for(int i = 0; i < cantidadv1; i++){
 
         int numero = rand() % 11;
         v1[i] = numero; 
 
         printf("\n[%02d]:%d", i, v1[i]);
 
     }
 
     printf("\n\nSegundo vector:");
     for(int j = 0; j < cantidadv2; j++){
 
         int numero = rand() % 11;
         v2[j] = numero;
         printf("\n[%02d]:%d", j, v2[j]);
 
     }
 }
 
 
 void comprobarSisonIguales(int v1[], int v2[], int cantidadv1, int cantidadv2)
 {
     bool iguales = false;
 
 
     for(int i = 0; i < cantidadv1; i++){
 
         iguales = false; //se restablece el bool
 
         for(int j = 0;  j < cantidadv2; j++){
 
             if(v1[i] == v2[j]){ //si algun elemento es igual se  le asiga  true
                 iguales = true;
             }
 
         }
 
         if(iguales == false){
             printf("\n\nNo son iguales");
             break;
         }
     }
 
     if(iguales == true){
         printf("\n\nSi son iguales");
     }
 
 }