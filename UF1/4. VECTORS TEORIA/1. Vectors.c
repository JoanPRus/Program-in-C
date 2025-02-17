#include <stdio.h>
#define MAX 6
void  omplirvector(int v[]);
void mostrarvector(int v[]);
void NumerosPares(int v[]);
void sumavector(int v[]);
void vectoracomulativo(int v[]);
void invertirvector(int v[]);
/*(Vectors) Definir un vector de 6 caselles buides i fer els següents exercicis:
1.1. Omplir el vector amb els valors 4,3,5,6,2 i 10
1.2. Mostrar per pantalla el vector
1.3. Indicar quants números són parells.
1.4. La suma de tots els valors del vector.
1.5. Modifica el valor de cadascuna de les caselles, de tal manera que cada
casella tingui el seu valor més el valor de la casella anterior.
1.6. Invertir el vector*/


int main(){
    int v[MAX] = {};  
    
    omplirvector(v);
    mostrarvector(v);
    NumerosPares(v);
    sumavector(v);
    vectoracomulativo(v);
    invertirvector(v);





    

    getch();
    return 0;
}

void  omplirvector(int v[])
{
    int valores[MAX] = {4, 3, 5, 6, 2, 10};//vector  valores tiene estos datos 

    for(int i = 0; i < MAX; i++){
        v[i] = valores[i];  //copiamos  los valores con  el  for, aumenta  el indice y se va copiando  en una  nueva posicion. 
    }
    
}

void mostrarvector(int v[])
{
    for(int i = 0; i < MAX; i++){
        printf("\nV[%02d]: %d", i, v[i]);//recorre el  vector y los muestra
    }
}

void NumerosPares(int v[])
{
    int contador = 0;

    for(int i = 0; i < MAX; i++){

        if(v[i] % 2 == 0){ //si  es par aumenta el  contador
            contador += 1;
        }
    }

    printf("\n\nHay %d numeros pares", contador);
}

void sumavector(int v[])
{
    int suma = 0;

    for(int i = 0; i < MAX; i++){

        suma += v[i];
    }

    printf("\n\nLa suma de todos los vectores es %d", suma);
}

//tengo que modificar el vector, sumarle el valor anterior a cada elemento del vector

void vectoracomulativo(int v[])
{
    printf("\n\nVector acomulacion");
    for(int i = 0; i < MAX; i++){
        
        if(i > 0){
            v[i] = v[i] + v[i - 1];
        }

        printf("\n[%02d]: %d", i, v[i]);
    }
}

void invertirvector(int v[])
{
    int indice = 0;
    printf("\n\nVector invertido");
    for(int i = MAX - 1; i >= 0; i--){

        printf("\n[%02d]: %d", indice, v[i]);
        indice += 1;
    }
}