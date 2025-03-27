#include <stdio.h>
#include <rlutil.h>
#include <stdlib.h>
#include <time.h>
void presentacio();
void demanar_cabal_inicial(int *cabal_inicial);
void pintar_grafic();
void imprimir_cabal(int *cabal_inicial, int *cabal_aleatori);
void generar_numeros(int cabal_anterior, int *cabal_aleatori);
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
system("mode con cols=168");*/

int main(){
    int cabal_inicial;
    int cabal_aleatori;
    system("mode con cols=168");
    presentacio();
    demanar_cabal_inicial(&cabal_inicial);
    pintar_grafic();
    srand(time(NULL));
    imprimir_cabal(&cabal_inicial, &cabal_aleatori);
    getch();
    return 0;
}

void imprimir_cabal(int *cabal_inicial, int *cabal_aleatori){
  
    int cabal_anterior =  *cabal_inicial;
    int x= 3, y_inicial = 5;
    y_inicial += 30 - *cabal_inicial;
    gotoxy(x, y_inicial);
    printf("%d", *cabal_inicial);
    y_inicial = 5;
    x += 3;
    
    for(int i = 0; i < 23; i++){

        do{
            generar_numeros(cabal_anterior, cabal_aleatori);
        }while(*cabal_aleatori > 30 || *cabal_aleatori < 0);

        y_inicial += 30 - *cabal_aleatori;
        gotoxy(x, y_inicial);
        printf("%d", *cabal_aleatori);
        cabal_anterior = *cabal_aleatori;
        x += 3;
        y_inicial = 5;
    }

}

void generar_numeros(int cabal_anterior, int *cabal_aleatori){
  
    int positiu = rand()  % 2;

    if(positiu == 1){
        *cabal_aleatori  = cabal_anterior + rand() % 7;  // 7 para que el dibujo tenga algo mas de forma
    }else{
        *cabal_aleatori  = cabal_anterior - rand() % 7;
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


void demanar_cabal_inicial(int *cabal_inicial){
    

    do{
        printf("\nIntrodueix el cabal inicial (0-30): ");
        scanf("%d", cabal_inicial);
    }while(*cabal_inicial > 30 || *cabal_inicial < 0);

}


void presentacio(){
    printf("Benvingut  al sistema de  representacio del riu");
}