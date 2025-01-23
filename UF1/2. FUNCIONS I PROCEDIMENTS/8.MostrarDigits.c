

/*(MostraDigits) Fer un programa que demani un nombre i mostri per pantalla
els dígits des de davant cap endarrera.*/
#include <stdio.h>
void demanarNumero(char numero[50]);
void numerocapadelant(char numero[50]);

/*(MostraDigitsDesDeDarrera) Fer un programa que demani un nombre i
mostri per pantalla els seus dígits des de darrera cap endavant
*/

int main(){
    char numero[50];
    
    demanarNumero(numero);
    numerocapadelant(numero);

    getch();
    return 0;
}


//reutilizamos funciones
void demanarNumero(char numero[50]) //el numero es una cadena de  caracteres
{
    printf("Introdueix un numero positiu: ");
    scanf("%s", numero);
}

void numerocapadelant(char numero[50])
{   
    for(int i = 0; i < numero[i]; i++){  
       printf("%c-",  numero[i]);
    } 
}
