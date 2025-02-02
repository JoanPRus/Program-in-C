#include <stdio.h>
#include <rlutil.h>
int posicioX();
int posicioY();
void mostrarhelice(int x,  int y);
/*(Hèlice) Realitza un programa que ens dibuixi una hèlice, en una
determinada posició de la pantalla. El programa, inicialment demanarà una
posició x i una posició y i es posicionarà en aquest punt. El punt inicial, cal que
estigui controlat dins de la pantalla (80X20). Seguidament, ens anirà mostrant
els caràcters:
-
\
|
/
de manera consecutiva fins que l’usuari premi una tecla.
Observacions:
▪ Per tal de veure l’hèlice, hauràs de jugar amb la funció Sleep (numero),
que retarda l’execució de l’instrucció següent, tant milisegons com ens
indiqui el número.
▪ Per a detectar que s’ha premut una tecla s’ha d’utilitzar la funció kbhit()
que està dins de la llibreria rlutil.h. Aquesta funció retorna 0 mentre que
l’usuari no prem cap tecla.
▪ la funció gotoxy(x,y), també de la llibreria rlutil.h, ens permet posicionarnos a la posició x, y de la pantalla. */


/*Resumen: Pedir posicion X y Y, contral  estos puntos  entre  80x20. Mostrar  los caracteres formando una helice.
knhit() para detectar  tecla.*/

int main(){
    int x, y;

    x = posicioX();
    y = posicioY();
    mostrarhelice(x, y);
    return 0;
}

int posicioX()
{
    int x;
    do{
        printf("Introdueix la posicio de X  inferior a 80: ");
        scanf("%d", &x);
    }while(x > 80);

    return x;
}


int posicioY()
{
    int y;
   do{
        printf("Introdueix la posicio de Y inferior a 20: ");
        scanf("%d", &y);
   }while(y > 20);

   return y;
}

void mostrarhelice(int x,  int y)
{
    int ycopia;
    while(!kbhit()){ //hasta que no presione una tecla seguira  el bucle
        ycopia = y;
        gotoxy(x, ycopia);
        printf("-");
        ycopia += 1;
        Sleep(500);
        gotoxy(x, ycopia);
        printf("\\");
        ycopia += 1;
        Sleep(500);
        gotoxy(x, ycopia);
        printf("|");
        ycopia += 1;
        Sleep(500);
        gotoxy(x, ycopia);
        printf("/");
        Sleep(500);
        cls();

    }
}