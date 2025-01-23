#include <stdio.h>
void demanarNumero(char numero[50]);
void numeroinvers(char numero[50], int longitud);

/*(MostraDigitsDesDeDarrera) Fer un programa que demani un nombre i
mostri per pantalla els seus dígits des de darrera cap endavant
*/

int main(){
    char numero[50];
    int longitud;
    
    demanarNumero(numero);
    numeroinvers(numero,longitud);

    getch();
    return 0;
}


//reutilizamos funciones
void demanarNumero(char numero[50]) //el numero es una cadena de  caracteres
{
    printf("Introdueix un numero positiu: ");
    scanf("%s", numero);
}

void numeroinvers(char numero[50], int longitud)
{   
    //importante saber la longitud de la cadena para poder recorrerla  hacia atras
    longitud = 0;
    for(int i = 0; i < numero[i]; i++){
        longitud++;
    } 

    for(int j = longitud - 1; j >= 0; j--){
        printf("%c-", numero[j]);
    }
  
}
