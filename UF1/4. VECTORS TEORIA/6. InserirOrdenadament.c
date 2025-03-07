#include <stdio.h>
#define MAX 10
void vectorordenat(int v[]);

/* (InserirOrdenadament) Definir un vector de n caselles. Posteriorment,
l’usuari introduirà nombres i aquests s’introduiran ordenadament dins del
vector. Finalitza el programa quan tot el vector estigui ple. En cada passada
mostrarem el vector amb els seus valors
*/


/*Vector de 10 casillas, ordenar  el  vector conforme se van haciendo las entradas de  pedir el numero. Parar cuando el vector este  lleno*/

int main(){

    int v[MAX] = {};

    vectorordenat(v);

    getch();
    return 0;
}

void vectorordenat(int v[])
{
    int numero = 0, aux = 0, j = 0;

    for(int i = 0; i < MAX; i++){

        printf("\nIntrodueix un numero: ");
        scanf("%d", &numero);

        v[i] = numero;  //guardamos el numero en el vector

        j = i; //copiamos el numero de indice

        /*// 🔹 Aplicamos Bubble Sort hasta la posición `i`
        for(int p = 0; p < i; p++){
            for(int j = 0; j < i - p; j++){
                if(v[j] > v[j + 1]){
                    // Intercambiamos los valores si están desordenados
                    int aux = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = aux;
                }
            }
        }*/
       
        /*Metodo de  insercion directa: Bucle con condicion que j > 0 para  no  salirnos del array, si el  ultimo  elemento es 
        mas pequeño que el anterior se ejecuta el  bucle, se cambian las variables y se resta j para ir una  posicion atras y volver
        a  mirar si se cumple el while, asi hasta que no  se cumpla. */
        while (j > 0 && v[j] < v[j - 1]) { //si  j es mayor a 0 y el  ultimo  elemento es mas pequeño que  el anterior se repite el bucle
            int aux = v[j];
            v[j] = v[j - 1];
            v[j - 1] = aux;
            j--; // Retrocedemos en el array para seguir ordenando hasta que encuentre su posicion 
        }


        //imprimir vector

        for(int k = 0; k <= i; k++){
            printf("\t%d", v[k]);
        }

    }
    


}