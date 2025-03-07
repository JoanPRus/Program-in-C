#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <rlutil.h>
#define MAXVECTOR 24
#define HORAMINRANG1 0
#define HORAMAXRANG1 10
#define TEMMINRANG1 -10
#define TEMMAXRANG1 12
#define HORAMINRANG2 11
#define HORAMAXRANG2 18
#define TEMMINRANG2 10
#define TEMMAXRANG2 20
#define HORAMINRANG3 19
#define HORAMAXRANG3 23
#define TEMMINRANG3 0
#define TEMMAXRANG3 10
void generartemperaturas(int v[]);
void imprimirresultados(int v[]);

/*Definir un vector de 24 caselles on es desaren les temperatures d’una ciutat
durant un dia.
Les temperatures es generaran aleatòriament depenent de la franja horària,
tenint en compte que entre les 0 i les 10, les temperatures poden ser entre -
10 a 12. Entre les 11 i les 18h, les temperatures estaran entre 10 i 20ºC i
entre les 19 i les 23h, estaran entre 0 i 10ºC.
A continuació mostra les temperatures, l’hora apareixerà en color blau entre
les 0 i les 10, en color vermell entre les 11 i les 18 i en color verd entre les 19
i les 23.
Cal utilitzar els defines que s’adjunten, per tal de fer fàcilment modificable el
programa.
*/

/*Definir el vector, usar los define del ejercicio. Generar temperaturas aleatorias:
0-10 horas --> temp -10 a 12 azul G1
11-18 horas --> temp 10 a 20 rojo G2
19-23 horas --> temp 0 a 10 verde G3*/

int main(){

    int v[MAXVECTOR] = {};

    srand(time(NULL));
    generartemperaturas(v);
    imprimirresultados(v);

    getch();
    return 0;
}

void generartemperaturas(int v[])
{   
    int resultado = 0;
    for(int i = 0; i <= MAXVECTOR; i++){

        if(i >= HORAMINRANG1  &&  i <= HORAMAXRANG1){
            
            resultado = TEMMINRANG1 + rand() % (TEMMAXRANG1  - TEMMINRANG1 + 1);
            v[i] = resultado;
        }else if(i >= HORAMINRANG2  &&  i <= HORAMAXRANG2){
            
            resultado = TEMMINRANG2 + rand() % (TEMMAXRANG2  - TEMMINRANG2 + 1);
            v[i] = resultado;
        }else if(i >= HORAMINRANG3  &&  i <= HORAMAXRANG3){

            resultado = TEMMINRANG3 + rand() % (TEMMAXRANG3  - TEMMINRANG3 + 1);
            v[i] = resultado;
        }
    }
}

void imprimirresultados(int v[])
{
    for(int j = 0; j <= MAXVECTOR; j++){

        if(j <= HORAMAXRANG1){
            
            setColor(BLUE);
            printf("[%2d]: ", j);

            setColor(WHITE);
            printf("%2d", v[j]);

            printf("\n");

        }else if(j >= HORAMINRANG2  &&  j <= HORAMAXRANG2){
            setColor(RED);
            printf("[%2d]: ", j);

            setColor(WHITE);
            printf("%2d", v[j]);

            printf("\n");

        }else if(j >= HORAMINRANG3  &&  j <= HORAMAXRANG3){
            setColor(GREEN);
            printf("[%2d]: ", j);

            setColor(WHITE);
            printf("%2d", v[j]);

            printf("\n");
            
        }   
    }
}