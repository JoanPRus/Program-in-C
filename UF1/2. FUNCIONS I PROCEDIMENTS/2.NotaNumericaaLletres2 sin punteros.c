#include <stdio.h>
//declaramos  los prototipos
int demanarnota(int alumnes);
void transformarNota(int nota);
int quantitatAlumnes();

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

    int nota, alumnes;

    alumnes = quantitatAlumnes();  //la variable es igual al valor que retorne la funcion
    nota = demanarnota(alumnes);
  
    getch();
    return 0;
}
//pedir cuantos  alumnos hay
int quantitatAlumnes()
{
    int  alumnes;
    printf("Quants alumnes te la clase? ");
    scanf("%d", &alumnes);

    return alumnes;
}
//pedimos las notas
int demanarnota(int alumnes)//pasamos el  parametro alumnes.
{
    int nota, contador = 1;  
    while(contador <= alumnes){ 
    
        printf("\nNota alumne [%d]: ", contador); 
        scanf("%d", &nota);
        
        printf("El alumne [%d] ha tret ", contador); transformarNota(nota); //llamamos ha  esta  funcion dentro de una funcion.
        (contador)++;
        if(nota > 10 || nota < 0){
            (contador)--;
        } 
    }   
    return nota; 
}

void  transformarNota(int nota)
{
    if (nota > 10)  printf("Nota no valida");
    else if (nota < 0)  printf("Nota no valida");
    else if(nota >= 9) printf("Excelent");
    else if(nota >= 7) printf("Notable");
    else if(nota >= 5) printf("Be");
    else if(nota >= 0) printf("Insuficient");
}

