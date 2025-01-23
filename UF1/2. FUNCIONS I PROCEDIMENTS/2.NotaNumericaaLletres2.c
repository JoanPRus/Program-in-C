#include <stdio.h>
//declaramos  los prototipos
int demanarNumero(int *numero,  int *contador, int *alumnes);
void transformarNota(int *numero);
int quantitatAlumnes(int *alumnes);



/*(NotaNumericaaLLetres2) Fer un programa que demani a l’usuari quants
alumnes te la classe i a continuació demani tantes notes com alumnes. Per a
cadascuna de les notes s’ha de transformar la nota en lletres.
Quants alumnes te la classe? 3
Nota alumne [1]: 10
L’alumne [1] ha tret excel·lent
Nota alumne [2]: 1
L’alumne [2] ha tret insuficient
Nota alumne [3]: 5
L’alumne [3] ha tret suficient
*/



//main  con las funciones
int main(){

    int numero = 0, alumnes, contador = 1;

    quantitatAlumnes(&alumnes);
    demanarNumero(&numero, &contador, &alumnes);
  
    getch();
    return 0;
}
//pedir  los   alumnos
int quantitatAlumnes(int *alumnes)
{
    printf("Quants alumnes te la clase? ");
    scanf("%d", alumnes);

    return 0;
}
//pedimos las notas
int demanarNumero(int *numero,  int *contador, int *alumnes)
{
    //repetir hasta cumplir la condicion
    while(*contador <= *alumnes){  //podria usar  un for y no un contador, sin usar punteros
    
        printf("\nNota alumne [%d]: ", *contador); 
        scanf("%d", numero);
        
        printf("El  alumne [%d] ha tret ", *contador); transformarNota(numero);
        (*contador)++;
        if(*numero > 10 || *numero < 0){
            (*contador)--;
        } 
    }   
    return 0; 
}

void  transformarNota(int *numero)
{
    if (*numero > 10)  printf("Nota no valida");
    else if (*numero < 0)  printf("Nota no valida");
    else if(*numero >= 9) printf("Excelent");
    else if(*numero >= 7) printf("Notable");
    else if(*numero >= 5) printf("Be");
    else if(*numero >= 0) printf("Insuficient");
}

