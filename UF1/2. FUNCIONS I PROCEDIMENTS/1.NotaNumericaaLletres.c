#include <stdio.h>
//declaramos los prototipos
int demanarNumero(int *numero);
void  transformarNota(int *numero);

/* (NotaNumericaaLLetres) Fer un programa que demani una nota compresa
entre 1 i 10 i posteriorment transformi la nota en la seva qualificació en lletres.
int demanarNumero(void);
void transformarNota(int);
Exemple: nota=2
Resultat: Insuficient*/


//main para correr las funciones
int main(){
    int numero; //declaramos la variable, indicamos & la direccion de memoria
    demanarNumero(&numero);
    transformarNota(&numero);



    getch();
    return 0;
}
//primera funcion, usamos punteros
int demanarNumero(int *numero){
    do{    
        printf("Introdueix un numero del 1-10: ");
        scanf("%d", numero);
    }while(*numero > 10 || *numero < 1);
    
}

void  transformarNota(int *numero)
{
    if(*numero >= 9) printf("Nota = %d\nResultat: Excelent", *numero);
    else if(*numero >= 7) printf("Nota = %d\nResultat: Notable", *numero);
    else if(*numero >= 5) printf("Nota = %d\nResultat: Be", *numero);
    else if(*numero >= 1) printf("Nota = %d\nResultat: Insuficient", *numero);
}

