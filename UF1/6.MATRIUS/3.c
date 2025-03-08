#include <stdio.h>
void diferenciatemperatura(int matriu[3][3]);
/*Indica la diferència entre la temperatura màxima i la mínima per a cada dia.
Per tal de resoldre l’exercici, has de generar matriu, on el la primera columna
desarem el mínim i el màxim en la segona columna. Mostra posteriorment la
matriu; així com la màxima diferència.*/

int main(){

    int matriu[3][3] =  {

        {-8, 20,},
        {-3, 20,},
        {-10, 20,}
    };

    diferenciatemperatura(matriu);


    getch();
    return 0;
}

void diferenciatemperatura(int matriu[3][3]){

    int diferencia;
    printf("        Minim  Maxim  Diferencia:");
    for(int i = 0; i < 3;  i++){

        printf("\nDia[%d]: ", i + 1);

        for(int j = 0; j < 3; j++){

            if(j == 1){
                diferencia = matriu[i][j] - matriu[i][j - 1];
                matriu[i][j + 1] = diferencia;
            }
            
            printf("%5d ", matriu[i][j]);
        }
    }
}