#include <stdio.h>
void demanarNumero(char numero[50]);
void numeroinvers(char numero[50]);

/*(MostraDigitsDesDeDarrera) Fer un programa que demani un nombre i
mostri per pantalla els seus dígits des de darrera cap endavant
*/

int main(){
    char numero[50];
    
    demanarNumero(numero);
    numeroinvers(numero);

    getch();
    return 0;
}


//reutilizamos funciones
void demanarNumero(char numero[50]) //el numero es una cadena de  caracteres
{
    printf("Introdueix un numero positiu: ");
    scanf("%s", numero);  //al ser una  cadena no  usamos &
}

void numeroinvers(char numero[50])
{   
    //importante saber la longitud de la cadena para poder recorrerla  hacia atras
   int longitud = 0;
    for(int i = 0; numero[i] != '\0'; i++){ //i++ da otra vuelta  si no vale = \0
        longitud++; //cada  vuelta aumenta la longitud
    } 

    for(int j = longitud - 1; j >= 0; j--){ //longitud - 1,  pork el indice empieza en 0. 
        printf("%c-", numero[j]);
    }
  
}
