#include <stdio.h>
#include <rlutil.h>
int posicioX();
int posicioY();
void dibujarhelice(int x_inici, int y_inici);
void movimenthelice(int x_inici,  int y_inici);

/*(Ampliació Helice) Ens demanen una ampliació de l’exercici anterior, per tal
manera que el programan simuli que l’hèlice es mou a través de la pantalla i
que a mesura que es mou deixa una estela de punts.
Per a fer moure l’helice, utilitzarem les següents tecles:
KEY_UP Fa moure l’hèlice una posició amunt
KEY_DOWN Fa moure l’hèlice una posició avall
KEY_LEFT Fa moure l’hèlice una posició a l’esquerra
KEY_RIGHT Fa moure l’hèlice una posició a baix
Per a detectar aquestes tecles, en la llibreria rlutil.h, hi ha la funció getkey(),
que en retorna el codi ascii del caràcter llegit. En el cas de les tecles especials
(KEY_UP, KEY_DOWN, KEY_LEFT i KEY_RIGHT), aquesta funció ja està
implementada de tal manera que ens retorna els següents números:
KEY_UP = 14,
KEY_DOWN = 15,
KEY_LEFT = 16,
KEY_RIGHT = 17 
Caldrà controlar que l’hèlice no surti de la pantalla:
marge esquerra superior: 1,1
marge esquerra inferior: 1,20
marge dreta superior: 80,1
marge dreta inferior: 80,20
Per aturar el programa, l’usuari haurà de prèmer una tecla qualsevols que no
siguin cap de les tecles de moviment (KEY_UP, KEY_DOWN, KEY_LEFT i
KEY_RIGHT)*/

/*Resumen: Usar  flechas para mover  la helice, funcion  getkey(). Controlar que la helice no  salga de la pantalla. 
Parar el programa usando  cualquier tecla menos las flechas.
KEY_UP = 14,        
KEY_DOWN = 15,
KEY_LEFT = 16,
KEY_RIGHT = 17
marge esquerra superior: 1,1
marge esquerra inferior: 1,20
marge dreta superior: 80,1
marge dreta inferior: 80,20*/

int main(){

    int x_inici, y_inici;

    x_inici = posicioX();
    y_inici = posicioY();
    movimenthelice(x_inici, y_inici);

    return 0;
}

//pintamos la helice
void dibujarhelice(int x_inici, int y_inici)
{
    gotoxy(x_inici, y_inici); 
    printf("-");
    y_inici += 1;
    Sleep(500);
    gotoxy(x_inici, y_inici);
    printf("\\");
    y_inici += 1;
    Sleep(500);
    gotoxy(x_inici, y_inici);
    printf("|");
    y_inici += 1;
    Sleep(500);
    gotoxy(x_inici, y_inici);
    printf("/");
    Sleep(500);      
}

//bucle hasta presionar  una tecla y movimiento de  la helice
void movimenthelice(int x_inici,  int y_inici)
{   
    int tecla;               
    while(!kbhit()){ //si  se presionan mas de  dos flechas a la vez el buffer da  un problema.  
    
        dibujarhelice(x_inici, y_inici);
        tecla = getkey();

        if (tecla == KEY_UP || tecla == KEY_DOWN || tecla == KEY_LEFT || tecla == KEY_RIGHT){
            
            if(tecla == KEY_UP && y_inici > 1){ //control  de  la tecla y  de margenes
                y_inici -= 1;
            }else if(tecla == KEY_DOWN && y_inici < 20){
                y_inici += 1;
            }else if(tecla == KEY_LEFT && x_inici > 1){
                x_inici -= 1;
            }else if(tecla == KEY_RIGHT && x_inici < 80){
                x_inici += 1;
            }

            continue;

        }else if(tecla != KEY_UP && tecla != KEY_DOWN && tecla != KEY_LEFT && tecla != KEY_RIGHT){
            break;
        }
    }
}

int posicioX()
{
    int x_inici;
    do{
        printf("Introdueix la posicio de X inferior a 80: ");
        scanf("%d", &x_inici);
    }while(x_inici > 80);

    return x_inici;
}

int posicioY()
{
    int y_inici;
   do{
        printf("Introdueix la posicio de Y inferior a 20: ");
        scanf("%d", &y_inici);
   }while(y_inici > 20);

   return y_inici;
}