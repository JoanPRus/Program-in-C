#include <stdio.h>
#include <rlutil.h>
void pintaTaula();


/* (TotesTaulesMultiplicar) Fer un programa que mostri totes les taules de
multiplicar des de l’1 fins al 10; cal utilitzar el procediment de l’exercici
anterior.
void pintaTaula(int);
*/

int main(){
    
    pintaTaula();

    getch();
    return 0;
}

void pintaTaula()
{
    for(int j = 1; j <= 10; j++){
        printf("\n\nTaula del %d", j);

        for(int i = 0; i <= 10; i++){
        printf("\n%d x %d = %d", j, i, j * i);
        }
        Sleep(1000);
    }
    printf("\nPrem una tecla per finalitzar");
    
}