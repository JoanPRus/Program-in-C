#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <rlutil.h>
#include <stdbool.h>
#define MAX 10
void inicio_juego();
void mostrar_resultados_partida(int resultat_usuari[], int resultat_ordinador[], int *index, int *punts_usuari, int *punts_ordinador, int *numero_partida, char *opcions[]);
void resultat_partida(int resultat_usuari[],  int resultat_ordinador[], int *numero_partida,  int *index, int *punts_usuari, int *punts_ordinador, char *opcions[]);
void opcions_ordinador(int resultat[], int *index);
void opcions_usuari(int resultat[],  int *index);
void taula_final(int resultat_usuari[], int resultat_ordinador[], int *index, int *punts_usuari, int *punts_ordinador, char *opcions[], int *numero_partida);

/*Jugar al  piedra, papel y tijera  contra una  maquina,  gana el que  gane tres  puntos.
Cada partida ganada se  suma un punto,  el empate  no suma punto.

Recordar las  normas: 
1. Pedra guanya a tisora 
2. Paper guanya a pedra
3. Tisora guanya a paper

Opciones para jugar: 
− 1: Pedra
− 2: Paper
− 3: Tisora

Para cada partida hay que limpiar la pantalla, pedir que opcion escoge,  mostrar  quien  ha ganado y  que  ha sacado   cada   uno.
Pulsar una tecla para visualizar la siguiente partida.  
Cuando  se  ha  llegado a tres puntos se  muestra quien  ha ganado, las partidas que se han   jugado   y  quien  ha  gando  de  color 
verde y rojo quien  ha  perdido. Como maximo  haremos  10  jugadas
*/

int main(){
    int resultat_usuari[MAX] = {};
    int resultat_ordinador[MAX] = {};
    char *opcions[] = {"", "pedra", "paper", "tisora"};
    int index = 0;
    int punts_usuari = 0;
    int punts_ordinador = 0;
    int numero_partida = 1;
    srand(time(NULL));
    inicio_juego();
    mostrar_resultados_partida(resultat_usuari, resultat_ordinador, &index, &punts_usuari, &punts_ordinador, &numero_partida, opcions);
    taula_final(resultat_usuari, resultat_ordinador, &index, &punts_usuari, &punts_ordinador, opcions, &numero_partida);


    getch();
    return 0;
}


/*Pasos: Presentar el juego, y  mostrar las normas, pulsar un boton para iniciar el juego. Menu de  opciones  para   el usuario, 
generar un numero  del 1 al  3 para la  maquina, mostrar quien ha ganado esa partida y sumar un punto al ganador,
guardar las opciones del usuario  y del ordenador en dos vectores. Pulsar boton para la siguiente partida,
limpiar pantalla.  cuando  se llega a tres puntos se muestran las partidas y el ganador en color verde,  perdedor de color rojo. 
Como maximo se pueden jugar 10 partidas*/

void taula_final(int resultat_usuari[], int resultat_ordinador[], int *index, int *punts_usuari, int *punts_ordinador, char *opcions[], int *numero_partida){

    if(*punts_ordinador > *punts_usuari){
        printf("\n\nGuanyador ordinador!!!");
    }else printf("\n\nGuanyador usuari!!!");

    printf("\n\nResum del joc:"); 
    printf("\nTirada      Jugador     Ordinador");
    for(int i = 0; i < *index; i++){
        printf("\n");
        printf("%d ", i + 1); 
        
        if(resultat_usuari[i] == resultat_ordinador[i]){
            setColor(WHITE);
            printf("%16s", opcions[resultat_usuari[i]]);
            printf("%13s", opcions[resultat_ordinador[i]]);
            
        }else if(
            resultat_usuari[i] == 1 && resultat_ordinador[i] == 3 ||
            resultat_usuari[i] == 2 && resultat_ordinador[i] == 1 ||
            resultat_usuari[i] == 3 && resultat_ordinador[i] == 2){
            
            setColor(GREEN);
            printf("%16s", opcions[resultat_usuari[i]]);
            setColor(RED);
            printf("%13s", opcions[resultat_ordinador[i]]);
            setColor(WHITE);
        }else{
            setColor(RED);
            printf("%16s", opcions[resultat_usuari[i]]);
            setColor(GREEN);
            printf("%13s", opcions[resultat_ordinador[i]]);
            setColor(WHITE);
        }
    }
}


void mostrar_resultados_partida(int resultat_usuari[], int resultat_ordinador[], int *index, int *punts_usuari, int *punts_ordinador, int *numero_partida, char *opcions[]){

    while(*numero_partida <= MAX){
        printf("\n\nPartida %d", *numero_partida);
        opcions_usuari(resultat_usuari, index);
        opcions_ordinador(resultat_ordinador, index);
        resultat_partida(resultat_usuari, resultat_ordinador, numero_partida,  index, punts_usuari, punts_ordinador, opcions);
        (*numero_partida)++;
        (*index)++;
        if(*punts_ordinador == 3 || *punts_usuari == 3){
            break;
        }
    }

}

void resultat_partida(int resultat_usuari[],  int resultat_ordinador[], int *numero_partida,  int *index, int *punts_usuari, int *punts_ordinador, char *opcions[]){

    int usuari = resultat_usuari[*index];
    int ordinador = resultat_ordinador[*index];

    if(usuari == ordinador){
        printf("\nResultat de la partida %d: Empat", *numero_partida);
    }else if(
        usuari == 1 && ordinador == 3 ||
        usuari == 2 && ordinador == 1 ||
        usuari == 3 && ordinador == 2){
        
        printf("\nResultat de la partida %d: Punt pel usuari", *numero_partida);
        *punts_usuari += 1;

    }else{
        printf("\nResultat de la partida %d: Punt pel ordinador", *numero_partida);

        *punts_ordinador += 1;
    }

    printf("\nUsuari ha tret: %s", opcions[usuari]);
    printf("\nOrdinador ha tret: %s", opcions[ordinador]);
}

void opcions_ordinador(int resultat[], int *index){

    int num = rand() % 3 + 1; 
    resultat[*index] = num;
}

void opcions_usuari(int resultat[],  int *index){
    int opcio;

    do{
        printf("\nIntrodueix a que vols jugar (1: Pedra 2: Paper 3: Tisora): ");
        scanf("%d", &opcio);
    }while(opcio > 3 || opcio < 1);

    resultat[*index] = opcio;
}

void inicio_juego(){

    printf("\n                                                      *******Benvingut*******");
    printf("\n                                                      *********Pedra*********");
    printf("\n                                                      *********Paper*********");
    printf("\n                                                      *********Tisora********");
    printf("\n\nCombinaciones guanyadores:");
    printf("\n1. Pedra guanya a tisora");
    printf("\n2. Paper guanya a pedra");
    printf("\n3. Tisora guanya a paper");  
    printf("\nPrem una tecla per jugar");
    getch();
    cls(); 
}

