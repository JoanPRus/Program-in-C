#include <stdio.h>
char demanarcarta();
int demanarnumero();
void imprimircarta(int num, char lletra);
/*(DemanaCarta) Fes una funció que retorni una carta de
la baralla espanyola. Cal tenir en compte que els números
van des de l’1 fins al 12 i que els pals poden ser Ors,
Copes, Bastos i Espases (‘O’,’C’,’B’,’E*/

//Resumen: Pedir numero 1-12  y palo O,C,B,E.

int main(){
    int num;
    char lletra;

    num = demanarnumero();
    lletra = demanarcarta();
    imprimircarta(num, lletra);


    getch();
    return 0;
}


void imprimircarta(int num, char lletra)
{
    printf("La teva carta es: %d%c", num, lletra);
}


int demanarnumero()
{
    int num; 
    do{
        printf("Introdueix un numero de  la carta (1-12): ");
        scanf("%d", &num);
    }while(num > 12 || num < 1);

    return num;
}

char demanarcarta()
{   
    char lletra;
    do{
        printf("Introdueix el pal de la carta (O,C,B,E): ");
        scanf(" %c", &lletra);
    }while(lletra != 'O' && lletra != 'C' && lletra != 'B' && lletra != 'E');

    return lletra;
}