#include <stdio.h>
#define MAXDIES 7
#define LECTURESDIA 24
void imprimirtemp(int temp[MAXDIES][LECTURESDIA], int numero_de_dias);
int diaeliminado();
void tempmodificado(int temp[MAXDIES][LECTURESDIA],  int dia, int numero_de_dias);
/*Demanar un dia i eliminar totes les temperatures d’aquell dia. Hauràs de
desplaçar les temperatures dels dies següents. Suposarem que la matriu està
plena amb els 7 dies.
*/


int main(){

    int temp[MAXDIES][LECTURESDIA]={
        {-7,5,12,11,10,5,-3,-8,12,1,8,10,17,16,18,11,15,20,19,7,3,10,0,6},
        {-8,12,1,8,10,17,16,18,11,15,20,19,7,3,10,0,6,3,5,-1,-1,7,-3,6},
        {18,11,15,20,19,7,3,10,0,6,3,5,-1,-1,7,-3,6,7,5,3,18,16,20},
        {10,0,6,3,5,-1,-1,7,-3,6,7,5,3,1,18,16,20,12,17,18,17,11,8,1},
        {7,-3,6,7,5,3,1,18,16,20,12,17,18,17,11,8,1,6,8,9,-9,-9,-10,-2},
        {18,16,20,12,17,18,17,11,8,1,6,8,9,-9,-9,-10,-2,-2,-2,-1,2,3,3,1},
        {11,8,1,6,8,9,-9,-9,-10,-2,-2,-2,-
        1,2,3,3,1,10,15,20,16,12,16,13}};
    int dia, numero_de_dias = 7;
    imprimirtemp(temp, numero_de_dias);
    dia = diaeliminado();
    tempmodificado(temp, dia, numero_de_dias);



    getch();
    return 0;
}


void  tempmodificado(int temp[MAXDIES][LECTURESDIA],  int dia, int  numero_de_dias){

    for(int i = 0; i < MAXDIES; i++){
        
        if(i >= dia -1){

            for(int j = 0; j < LECTURESDIA; j++){
                temp[i][j] = temp[i + 1][j];
            }
        }
    }
    
    imprimirtemp(temp, numero_de_dias - 1);

}

int diaeliminado(){
    int dia;

    do{
        printf("\n\nIntroduce el dia  que  quieres  eliminar: ");
        scanf("%d", &dia);
    }while(dia > 7 || dia < 1);

    return dia;
}


void imprimirtemp(int temp[MAXDIES][LECTURESDIA], int numero_de_dias){

    for(int i = 0; i < numero_de_dias; i++){
        
        printf("\nDia[%d]: ", i + 1);

        for(int j = 0; j < LECTURESDIA; ++j){

            printf("%3d ", temp[i][j]);
        }
    }
}