#include <stdio.h>
#define MAX 10

int main(){

    int v[MAX] =  {4, 2, 7, 10, 1, 8, 9, 3, 5, 6};  //vector  desordenado
    int  aux; //aux para el intercanvio de variables
    

    /*Primer bucle (for (int i = 0; i < MAX - 1; i++)):
    Este bucle realiza las pasadas necesarias para ordenar el array.
    Cada pasada coloca el valor más grande en su lugar correcto, por lo que el número de comparaciones disminuye en cada iteración.

    Segundo bucle (for (int j = 0; j < MAX - i - 1; j++)):
    Al finalizar cada pasada, el último valor está ordenado, por lo que no es necesario compararlo en la siguiente iteración.
    Así que MAX - i - 1 garantiza que no se comparen elementos ya ordenados.

    Intercambio de valores:
    Si el valor v[j] es mayor que v[j + 1], entonces los valores se intercambian, 
    asegurando que los elementos más grandes se "suban" al final del array.*/
    
    //bubble sort:
    for(int i = 0; i < MAX - 1; i++){ 

        for(int j = 0; j < MAX - i - 1; j++){ 

            //intercanvio de posiciones 
            if(v[j] > v[j + 1]){
                aux = v[j];
                v[j] = v[j  + 1];
                v[j + 1] = aux;
            }
            
        }

    }

    for(int k = 0; k < MAX; k++){
        printf("\t%d", v[k]);
    }





    getch();
    return 0;
}