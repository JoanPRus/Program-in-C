#include <stdio.h>
char demanarcarta();
int demanarnumero();
void compararcartes(int PrimeraCarta, char demanarcarta1, int SegonaCarta,  char demanarcarta2, int TerceraCarta, char demanarcarta3);
void imprimecarta(int PrimeraCarta, char demanarcarta1, int SegonaCarta,  char demanarcarta2, int TerceraCarta, char demanarcarta3);
/*(SonIguals): Fer una funció que passant-li dues cartes ens retorni si les dues
cartes són iguals. I amb tres cartes??*/

//Resumen: utilizar funciones del ejercicio anterior, implementar una funcion que las compare.  

int main(){
    
    //uso paso por  valor pork  no  estoy modificando nada,  solo  comparando. 
    int PrimeraCarta, SegonaCarta, TerceraCarta;
    char demanarcarta1,  demanarcarta2, demanarcarta3; 

    PrimeraCarta = demanarnumero();
    demanarcarta1 = demanarcarta();

    SegonaCarta = demanarnumero();
    demanarcarta2 = demanarcarta();

    TerceraCarta = demanarnumero();
    demanarcarta3 = demanarcarta();

    imprimecarta(PrimeraCarta, demanarcarta1, SegonaCarta, demanarcarta2, TerceraCarta, demanarcarta3);

    compararcartes(PrimeraCarta, demanarcarta1, SegonaCarta, demanarcarta2, TerceraCarta, demanarcarta3);

    printf("\nPrem una tecla per finalitzar.");

    getch();
    return 0;
}

void imprimecarta(int PrimeraCarta, char demanarcarta1, int SegonaCarta,  char demanarcarta2, int TerceraCarta, char demanarcarta3)
{
    printf("\nLa carta es: %d%c", PrimeraCarta, demanarcarta1);
    printf("\nLa carta es: %d%c",  SegonaCarta, demanarcarta2);
    printf("\nLa carta es: %d%c\n", TerceraCarta, demanarcarta3);
}

void compararcartes(int PrimeraCarta, char demanarcarta1, int SegonaCarta,  char demanarcarta2, int TerceraCarta, char demanarcarta3)
{
    if((PrimeraCarta == SegonaCarta && SegonaCarta == TerceraCarta) && (demanarcarta1  == demanarcarta2 && demanarcarta2 == demanarcarta3)){
        printf("Les tres cartes son iguals.");
    }else if((PrimeraCarta == SegonaCarta) && (demanarcarta1  == demanarcarta2)){
        printf("Les dos primeres cartes  son iguals.");
    }else if((SegonaCarta == TerceraCarta) && (demanarcarta2 == demanarcarta3)){
        printf("Les dos ultimes cartes son iguals.");
    }else if((PrimeraCarta == TerceraCarta) && (demanarcarta1  == demanarcarta3)){
        printf("La primera i ultima carta son iguals.");
    }else printf("Cap carta es igual.");
}

int demanarnumero()
{
    int num; 
    do{
        printf("Introdueix un numero de la carta (1-12): ");
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