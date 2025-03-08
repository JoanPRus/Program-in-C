#include <stdio.h>
#define MAXDIES 7
#define LECTURESDIA 24
void temperaturamitjanacadadia(int temp[MAXDIES][LECTURESDIA], int dies);
int demanardies();
/*.2.Indica la temperatura mitja de cada dia. Hauràs de tenir en compte quants
dies tens. RESOLDRE AMB MATRIUS. Cal desar tots els valors i posteriorment
mostrar-los.
Per tal de facilitar la correcció dels resultats utilitzarem la següent matriu.
int temp[MAXDIES][LECTURESDIA]={
{-7,5,12,11,10,5,-3,-8,12,1,8,10,17,16,18,11,15,20,19,7,3,10,0,6},
{-8,12,1,8,10,17,16,18,11,15,20,19,7,3,10,0,6,3,5,-1,-1,7,-3,6},
{18,11,15,20,19,7,3,10,0,6,3,5,-1,-1,7,-3,6,7,5,3,18,16,20},
{10,0,6,3,5,-1,-1,7,-3,6,7,5,3,1,18,16,20,12,17,18,17,11,8,1},
{7,-3,6,7,5,3,1,18,16,20,12,17,18,17,11,8,1,6,8,9,-9,-9,-10,-2},
{18,16,20,12,17,18,17,11,8,1,6,8,9,-9,-9,-10,-2,-2,-2,-1,2,3,3,1},
{11,8,1,6,8,9,-9,-9,-10,-2,-2,-2,-
1,2,3,3,1,10,15,20,16,12,16,13}};*/

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
    
    int dies;

    dies = demanardies();
    temperaturamitjanacadadia(temp, dies);


    getch();
    return 0;
}


int demanardies(){
    int dies;

    do{
        printf("Introdueix els dies que vols visualitzar: ");
        scanf("%d", &dies);
    }while(dies > 7 || dies < 1);

    return dies;
}


void temperaturamitjanacadadia(int temp[MAXDIES][LECTURESDIA], int dies){

    float Vmitjana[MAXDIES] = {};
    float suma = 0;

    for(int i = 0; i < MAXDIES; i++){
        suma = 0;

        for(int j = 0; j < LECTURESDIA; j++){

            suma += temp[i][j];
        }

        Vmitjana[i] = (suma / LECTURESDIA);
    }

    printf("\nEl promig de les temperatures per cada dia ha sigut:");

    for(int k = 0; k <= dies; k++){

        printf("\nDia[%d]: %.2f", k, Vmitjana[k]);
    }
}