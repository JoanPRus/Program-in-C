#include <stdio.h>
#define MAX 10
void demanarnumeros(int v[]);
/*(VectorSenseRepetits) Defineix un vector de
10 caselles i demana números a l’usuari fins
que el vector estigui ple.
Introduirem el nou números dins del vector,
sempre i quan, aquest no estigui ja introduït
prèviament. Al finalitzar caldrà mostrar el
vector amb els 10 números diferents. */

int main(){

    int v[MAX] = {};

    demanarnumeros(v);


    getch();
    return 0;
}

void demanarnumeros(int v[])
{   
    //para saber  si el numero que introduce ya  ha sido introducido anteriormente tengo que recorrer el vector  desde el principio
    
    int  numero;
    for(int i = 0; i  < MAX; i++){
    
        int repite;
        do{
            repite  = 0; //variable   para repetir si se repite numero
            printf("Introdueix un numero %d: ", i);
            scanf("%d", &numero);

            for(int j = 0; j < i; j++){ //recorremos  el vector comparando cada  elemento del indice con  el  numero, si es igual repite es  1

                if(v[j] == numero){
                    repite = 1;
                    break; //paramos el for para no  seguir comparando, porque  ya hemos visto que se ha repetido
                }
            }

        }while(repite == 1);

        //si repite = 0  guardamos el  numero en el vector, aumenta el indice i por el for principal.
        v[i] = numero;
    }
}