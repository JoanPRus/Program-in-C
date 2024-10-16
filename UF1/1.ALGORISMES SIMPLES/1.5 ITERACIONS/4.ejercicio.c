#include <stdio.h>
#include <string.h>


/*. (><) Fer un algoritme que demani a l'usuari dos nombres naturals i un
caràcter, que pot ser ‘>’ o ‘<’. Llavors, l'algoritme ha de mostrar per pantalla
tots els nombres naturals entre els dos introduïts, ordenats de menor a major
si el caràcter és ‘>’ o de major a menor si el caràcter és ‘<’
Per exemple:
Caràcter: ‘>’
Primer número: 10 Segon Número: 2
Resultat: 2 3 4 5 6 7 8 9 10*/

int main() {

    /*Demanar dos  nombres  naturals  y un caracter "<" o ">". 
    si ">" ordenats de menor a major
    si "<" ordenats de major  a  menor*/

    int num1, num2, aux; 
    char c;

    do {
    printf("Introdueix un caracter '> o <': "); 
    scanf(" %c", &c); 
    } while (c != '>' && c != '<'); //el bucle se  para cuando la condicion es falsa

    printf("Introdueix el primer numero: ");
    scanf("%d", &num1);
    printf("Introdueix el segon numero: ");
    scanf("%d", &num2); 

    //puedo asignar que el num1 sea siempre el valor mas grande

    if (num1 < num2) {
        aux = num1; //Columna izquierda variables y la derecha los valores
        num1 = num2;
        num2 = aux;
    }

    //puedo hacer un for sabiendo que el  num1 es el valor mas grande y  el num2 el menor 
    //puedo poner condiciones segun el caracter para imprimir el orden correcto   

    if (c == '>'){    
        for (int i = num2; i <= num1; i++){ //incrementa de menor a mayor 
            printf("%d ", i);
        }
    } else if (c == '<'){

        for (int i = num1; i >= num2; i--){ //decrece de mayor a menor
            printf("%d ", i);
        }
    } else printf("Caracter incorrecte");

    getch();
    return 0;
}