#include <stdio.h>
#define MAX 8
void imprimirvectororiginal(char vector[]);
void moverelementos(char vector[]);


/*(Elimina) Definir un vector de 8 caselles, i omplir només les 6 primeres.
Posteriorment eliminar el contingut de la casella 2; tot desplaçant el contingut
de la resta de caselles cap a l’esquerra. Cal controlar el cas que el vector
estigui buit*/

int main(){

    char vector[MAX] = "123456"; //defino el vector con 8 elementos pero  solo introduzco 6
    imprimirvectororiginal(vector);
    moverelementos(vector);

    getch();
    return 0;
}

void imprimirvectororiginal(char vector[])
{

    for(int i = 0;  vector[i] != '\0'; i++){

        printf("\n[%d]: %c", i, vector[i]);
    }
}

void moverelementos(char vector[])
{   
    printf("\nVector modificado");
    
    for(int j = 0; vector[j] != '\0'; j++){
        
        //la casilla  dos tendra el  indice 1, ya que empezamos con indice 0.

        //estoy modificando y imprimiendo en el mismo  for, es mejor hacerlo por separado.  
        if(j >= 1){
            vector[j] = vector[j + 1];

        }
        if(vector[j] != '\0'){
            printf("\n[%d]: %c", j, vector[j]);
        }
        
    }
}

