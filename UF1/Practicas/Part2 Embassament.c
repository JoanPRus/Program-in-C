#include <stdio.h>
#include <rlutil.h>
#include <stdlib.h>
#include <time.h>
void presentacio();
void demanar_cabal(int *cabal);
void pintar_grafic();
void imprimir_cabal(int *cabal, int *cabal_aleatori);
void generar_numeros(int *cabal, int *cabal_aleatori);
/*DIBUIX (part2)
Estem pensant en oferir al client la possibilitat de visualitzar la informació en un
gràfic. Per això, s’ha decidit, representar el gràfic del cabal del riu 1. Com encara
no sabem molt bé, què volem fer, estem començant per visualitzar el cabal del
riu1, limitat entre 0 i 30 m3
. A més a més, s’ha decidit que en comptes de
treballar amb decimals, el cabal del riu el determinarem com a variable entera.
La variació del cabal seguirà la formula de la pràctica anterior, però ara, haurem
de modificar la formula del càlcul del nou cabal per a què momentàniament el
cabal es comporti com a un decimal. Si no ho fem d’aquesta manera, el cabal del
riu a baix cabal no es modifica.
La idea, doncs, és fer un gràfic, on es demani a l’usuari el cabal del riu 1, entre 0
a 30 m3
, i veure com aquest varia al llarg del dia.
Nota:
− per fixar l’amplada de la pantalla a un ample fixa de columnes, utilitza la
instrucció:
system("mode con cols=168");
formula: Cabalhora=cabalhora anterior+/-rand()%11* cabalhora anterior/100*/

int main(){
    int cabal;
    int cabal_aleatori;
    system("mode con cols=168");
    presentacio();
    demanar_cabal(&cabal);
    pintar_grafic();
    srand(time(NULL));
    imprimir_cabal(&cabal, &cabal_aleatori);
    getch();
    return 0;
}

void imprimir_cabal(int *cabal, int *cabal_aleatori){
  
    int x= 3, y_inicial = 5;
    y_inicial += 30 - *cabal;
    gotoxy(x, y_inicial);
    printf("%d", *cabal);
    y_inicial = 5;
    x += 3;
    
    for(int i = 0; i < 23; i++){

        do{
            generar_numeros(cabal, cabal_aleatori);
        }while(*cabal_aleatori > 30 || *cabal_aleatori < 0);

        y_inicial += 30 - *cabal_aleatori;
        gotoxy(x, y_inicial);
        printf("%d", *cabal_aleatori);
        *cabal = *cabal_aleatori;
        x += 3;
        y_inicial = 5;
    }
}

void generar_numeros(int *cabal, int *cabal_aleatori){  
    //usar esta formula: Cabalhora=cabalhora anterior+/-rand()%11* cabalhora anterior/100
    if(*cabal < 1){
        *cabal = 1;
    }
    int positiu = rand()  % 2;

    if(positiu == 1){
        *cabal_aleatori  = *cabal + rand() % 11 * ((float)*cabal/100);  
    }else{
        *cabal_aleatori  = *cabal - rand() % 11 * ((float)*cabal/100);
    }
}

void pintar_grafic(){
    printf("\n");

    for(int i = 30; i >= 0; i--){
        printf("\n%2d|", i);
    }

    for(int j = 0; j < 24; j++){
        
        if(j >= 23){
            printf("---------");

        }else printf("--|");

    }

    printf("\n ");

    for(int k = 0; k < 24; k++){
    
        if(k > 9){
            printf("%3d", k);

        }else printf("%2d ", k);
    }
    printf("    hora");
}


void demanar_cabal(int *cabal){
    

    do{
        printf("\nIntrodueix el cabal inicial (0-30): ");
        scanf("%d", cabal);
    }while(*cabal > 30 || *cabal < 0);

}


void presentacio(){
    printf("Benvingut  al sistema de  representacio del riu");
}