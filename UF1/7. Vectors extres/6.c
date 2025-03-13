#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20
void tirardado(int v[]);
/*Jugarem amb un dau i un vector de 20 caselles. Tira el dau i
omple el vector amb el número que ha sortit tantes caselles
com el número ho indiqui. Si ens excedim de les caselles s’atura
el programa, i els darrers números no són introduïts. */

int main(){

    int vdado[MAX] = {};
    srand(time(NULL));
    tirardado(vdado);
    getch();
    return 0;
}

/*Tengo que llenar  el vector tirando un dado, el numero que sale se guarda en el vector el numero de veces del numero obtenido por el dado.
tengo que llevar  la cuenta de  los  espacios que he  ocupado, asi que tengo que tener un contador que sume los numeros que se  han
generado. Imprimir un mensaje con el numero que ha salido. Para guardar los numeros partimos del numero del  contador hasta el contador mas
el numero que  a salido. i = contador; i < contador + num_salido.  Luego  imprimir el vector */

void tirardado(int v[]){

    int contador = 0;
    while(contador < MAX){

        int num_dado = rand() % 6 + 1;

        printf("\nEl numero que ha salido es: %d\n", num_dado);
        
       
             
        for(int i = contador; i < (contador + num_dado); i++){

            if(i < MAX){  //evita que  se guarden mas de 20 elementos
                v[i] = num_dado;
            }
        }
        

        contador +=  num_dado;
        if(contador > MAX){ //para evitar imprimir mas numeros que el tamaño del vector
            contador = MAX;
        }

        for(int j = 0; j < contador; j++){

            printf("%d ", v[j]);
        }
    }
}