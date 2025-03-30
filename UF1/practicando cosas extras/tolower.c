#include <stdio.h>
#include <ctype.h>

int main(){

    char letra = 'A';
    char palabra[] = "HOLA";
    char frase[] = "      Hola  que  tal  estas?      ";
    int contador = 0;
    
    printf("Letra en minuscula %c", tolower(letra));

    printf("\nPasar una cadena de texto a minuscula: ");
    for(int i = 0; palabra[i] != '\0'; i++){

        printf("%c", tolower(palabra[i]));
    }

    printf("\nContador de palabras:");

    for(int j = 0; frase[j] != '\0'; j++){

        if(frase[j] != ' ' && frase[j + 1] == ' ' ||  frase[j] != ' ' && frase[j + 1] == '\0'){
            contador++;
        }
    }
    printf("\nLa frase '%s' tiene %d palabras", frase, contador);

    getch();
    return 0;
}