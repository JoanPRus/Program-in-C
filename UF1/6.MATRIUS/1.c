#include <stdio.h>
#include <stdlib.h>
#define horasdeldia 24
#define tempminima -10
#define tempmaxima 45

int demanardies();
void generartemperatures(int dies);
/*1. L’usuari ens indicarà quants dies vol introduir. Com a màxim podrà guardar
una setmana. Les temperatures es generaran aleatòriament, seguint el mateix
criteri que a l’exercici 1. Mostra les temperatures per a cada un dels dies.
RESOLDRE AMB MATRIUS
*/
//no  se los criterios  de las temperaturas asi que me los invento, -10 hasta 45 grados. 


int main(){
    int dies;

    dies = demanardies();
    generartemperatures(dies);

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

void generartemperatures(int dies){

    //primero [fila] despues [columna]
    int matriz[dies][horasdeldia];

    //tengo que llenar la matriz aleatoriamente 

    for(int i = 0;  i < dies;  i++){ //imprime las filas

        printf("\nDia[%d] ", i + 1);

        for(int j = 0; j < horasdeldia; j++){ //imprime las columnas
            int tempaleatoria = tempminima  + rand() % (tempmaxima - tempminima + 1);
            matriz[i][j] = tempaleatoria;  //en  la misma fila se guarda la temperatura luego aavanza  una columna y guarda otro valor
            printf("%3d ", matriz[i][j]);
        }
    }
}
