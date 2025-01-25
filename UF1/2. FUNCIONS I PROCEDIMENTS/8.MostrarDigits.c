#include <stdio.h>
void demanarNumero(char numero[50]);
void numerocapadelant(char numero[50]);

/*(MostraDigits) Fer un programa que demani un nombre i mostri per pantalla
els dígits des de davant cap endarrera.*/

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
    for(int i = 0; numero[i] != '\0'; i++){  
       if(numero[i + 1] == '\0'){
       printf("%c", numero[i]); 
       }else printf("%c-", numero[i]);
    } 
}
