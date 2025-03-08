#include <stdio.h>
#define MAXDIES 7
#define LECTURESDIA 24
void imprimirtemp(int temp[MAXDIES][LECTURESDIA]);
void ordenarmatriz(int temp[MAXDIES][LECTURESDIA]);
void contarnumeros(int temp[MAXDIES][LECTURESDIA]);

/*Indica per a cada temperatura quantes vegades ha aparegut. S’hauran de
mostrar les temperatures en ordre ascendent*/

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
    

    imprimirtemp(temp);
    printf("\n\n");
    ordenarmatriz(temp);
    printf("\n\n");
    contarnumeros(temp);


    getch();
    return 0;
}

//mostrar las temperaturas en orden de menor a mayor y el numero de  veces que han aparecido en la matriz

void ordenarmatriz(int temp[MAXDIES][LECTURESDIA]){
    int total = MAXDIES * LECTURESDIA; //numero total de  indices para  convertir una matriz a  un  vector
    int aux;
    //convertir la matriz en un  vector para poder ordenar todos los numeros:

    for(int i = 0;  i <  total - 1; i++){

        for(int j = 0; j < total - i - 1; j++){

            //obtenemoa la fila y  la columna 
            int fila1 = j / LECTURESDIA, col1 = j % LECTURESDIA;
            int fila2 = (j + 1) / LECTURESDIA, col2 = (j + 1) % LECTURESDIA;

            //si se cumple la  condicion intercambiamos
            if (temp[fila1][col1] > temp[fila2][col2]) {
                aux = temp[fila1][col1];
                temp[fila1][col1] = temp[fila2][col2];
                temp[fila2][col2] = aux;
            }
        }   
    }   
    imprimirtemp(temp); //imprime la  matriz ordenada

}


void contarnumeros(int temp[MAXDIES][LECTURESDIA]){

    int contador = 1; 

    for(int i = 0; i < MAXDIES; i++){

        for(int j = 0; j < LECTURESDIA; j++){

            if(j < LECTURESDIA - 1){ //para no  salirse del indice

                if(temp[i][j] == temp[i][j + 1]){
                    contador += 1;
                }else{

                    printf("\n[%3d]: %d", temp[i][j], contador);
                    contador = 1;
                }
            }else if(i < MAXDIES - 1){  //mira que no sea la ultima fila

                if(temp[i][j] == temp[i + 1][0]){

                    contador += 1;
                }else{

                    printf("\n[%3d]: %d", temp[i][j], contador);
                    contador = 1;
                }
            }
        }
    }
}


//imprime la matriz
void imprimirtemp(int temp[MAXDIES][LECTURESDIA]){

    for(int i = 0; i < MAXDIES; i++){  //fila
        
        printf("\nDia[%3d]: ", i + 1);

        for(int j = 0; j < LECTURESDIA; ++j){//columna

            printf("%3d ", temp[i][j]);
        }
    }
}