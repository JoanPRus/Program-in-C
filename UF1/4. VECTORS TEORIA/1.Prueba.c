#include <stdio.h>
#define MAX 10

void vectorordenat(int v[]);

int main(){
    int v[MAX] = {0};  // Inicializamos el vector en 0
    vectorordenat(v);
    return 0;
}

void vectorordenat(int v[])
{
    int numero;

    for(int i = 0; i < MAX; i++){

        printf("\nIntrodueix un numero: ");
        scanf("%d", &numero);

        // Insertamos el número en la siguiente posición libre del array
        v[i] = numero;

        // 🔹 Aplicamos Bubble Sort hasta la posición `i`
        for(int p = 0; p < i; p++){
            for(int j = 0; j < i - p; j++){
                if(v[j] > v[j + 1]){
                    // Intercambiamos los valores si están desordenados
                    int aux = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = aux;
                }
            }
        }

        // 🔹 Imprimir el vector ordenado
        printf("Vector ordenado: ");
        for(int k = 0; k <= i; k++){
            printf("%d ", v[k]);
        }
        printf("\n");
    }
}
