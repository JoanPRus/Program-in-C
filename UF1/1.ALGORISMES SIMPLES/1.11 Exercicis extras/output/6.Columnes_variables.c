#include <stdio.h>
#include <rlutil.h>

/*(ColumnesVariables): Volem fer un programa que permeti fer n columnes
de longitud fixa. De cada una de les columnes es demanarà la seva longitud. A
més a més es demanarà quantes columnes es volen visualitzar i quin és l’espai
entre les columnes. A més a més cal demanar la posició (tant la xo com la yo)
a partir de la qual es començaran a mostrar les columnes. Cal demanar les
dades i netejar la pantalla per tal de fer la visualització (cls())
Introdueix la posicio inicial en x: 10
Introdueix la posicio inicial en y: 5
Introdueix quantes creus vols en una linia vertical: 8
Introdueix quants cops es repetira la linia vertical: 10
Introdueix quina es la separacio entre linies verticals: 4*/

int main(){

    /*Tengo que pedir la posicion inicial del cursor. pedir cuantas  X quiere en la linea vertical y cuantas  veces quiere  que se  repita.
    preguntar el espacio  que quiere entre cada linea vertical.Limpiar la pantalla antes de generar las X*/

    int x = 0, y = 0, creus_linea = 0, quantes_linies = 0, separacions = 0, y_incr;

    printf("\nIntrodueix la  posicio inicial  en X: ");
    scanf("%d", &x);
    printf("\nIntrodueix la  posicio inicial  en y: ");
    scanf("%d", &y);
    printf("\nIntrodueix quantes creus vols en una linia vertical: ");
    scanf("%d", &creus_linea);
    printf("\nIntrodueix quants cops es repetira la linia vertical: ");
    scanf("%d", &quantes_linies);
    printf("\nIntrodueix quina es la separacio entre linies verticals: ");
    scanf("%d", &separacions);
    
    cls();

    /*Primero posicion el cursor. Un bucle para posicionar el cursor dejan los espacios, otro bucle  dentro para imprimir todas las X
    la separacion hay que aumentarla en el primer bucle la posicion de  x*/

    

    for(int i = 1;  i <=  quantes_linies; i++){ //imprime  el numero de  lineas
        
        y_incr = y; //retoma el  valor inicial de y
        gotoxy(x, y); //posicione el cursor en cada  vuelta

        for(int j = 1; j <= creus_linea; j++){ //imprime las x

            gotoxy(x, y_incr);//imprime en la posicion
            printf("X");
            y_incr += 1; //baja una  fila
            Sleep(150);

        }

        x += separacions; //aumenta la x despues  del  segundo  for


    }

    getch();
    return 0;
}