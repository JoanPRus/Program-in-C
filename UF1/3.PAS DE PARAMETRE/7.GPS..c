#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <rlutil.h>
#include <time.h>
void mostrarpuntos(int *gpsx, int *gpsy, int *x, int *y, int  *Xmascerca, int *Ymascerca);
void mostrarposicionesgps(int *gpsx, int *gpsy);
void pedirposiciones(int *gpsx,  int *gpsy);
void puntomascerca(int *Xmascerca, int *Ymascerca);
           
/*(GPS) Es tracta de fer un programa que donada la posició d’un GPS,
introduïda per l’usuari, ens mostri els punts que tenim al seu voltant.
Per a demanar la posició inicial del GPS, l’usuari haurà d’introduir una posició x
i una posició y. La posició x haurà d’estar controlada entre els marges (1 i 80),
mentre que la posició y ha d’estar controlada entre (1 i 20). En la posició del
nostre GPS mostrarem un ‘g’ de color verd.
Posteriorment, cal generar 100 punts aleatoris, que es mostraran a la pantalla
en color blau cel i el caràcter serà un ‘p’.
Finalment, volem conèixer quin és el punt que està més a prop del nostre GPS,
mostrant aquest punt en color vermell i amb el format de ‘c’. El punt més
proper es mostrarà en finalitzar el programa.
Per a calcular la distància entre dos punts aplicarem pitàgores, fent servir la
formula sqrt que ens retorna l’arrel quadrada d’un número.
p1(3,6)  p2(7,9)

Dist = SQRT((7-3)^2 + (9-6)^2)=
SQRT = ((4)^2 + (3)^2) =
SQRT = (16 + 9) =
SQRT = (25) = 5

float calcularDistancia(int x, int y, int gpsx, int gpsy)
{
float res;
res=sqrt((x-gpsx)*(x-gpsx)+(y-gpsy)*(y-gpsy));
return res;
}*/

/*Resumen:  Pedir  al usuario posicion x (1-80)  y (1-20) mostrar la poscion con 'g' de color verde.
Generar 100 puntos aleatorios dentro del margen, color cielo 'p'.
Conocer que  punto esta  mas cerca  de 'g' mostrarlo de  color rojo 'c'.*/

int main(){
    int gpsx, gpsy, x, y;
    int Xmascerca, Ymascerca; 
    srand(time(NULL));

    pedirposiciones(&gpsx, &gpsy);
    mostrarposicionesgps(&gpsx, &gpsy);
    mostrarpuntos(&gpsx, &gpsy, &x, &y, &Xmascerca, &Ymascerca);
    puntomascerca(&Xmascerca, &Ymascerca);



    getch();
    return 0;
}


//pide la  posicion del usuario
void pedirposiciones(int *gpsx,  int *gpsy){

    do{
        printf("\nIntroduce  la posicoin de x (1-80): ");
        scanf("%d", gpsx);
    }while(*gpsx > 80 || *gpsx < 1);

    do{
        printf("\nIntroduce  la posicoin de y (1-20): ");
        scanf("%d", gpsy);
    }while(*gpsy > 20 || *gpsy < 1);
    cls();
}

//muestra la  posicon   del usuario
void mostrarposicionesgps(int *gpsx, int *gpsy){

    gotoxy(*gpsx, *gpsy);
    setColor(GREEN);
    printf("g");
    
}

//genera los puntos de manera aleatoria
void mostrarpuntos(int *gpsx, int *gpsy, int *x, int *y, int  *Xmascerca, int *Ymascerca)
{
    int minX = 1, maxX = 80;
    int minY = 1, maxY = 20;
    float distanciafinal = 1000;
    float distancia;
    for(int i = 0; i < 100; i++){
        do{
            *x = minX + rand() % (maxX - minX + 1); 
            *y = minY + rand() % (maxY - minY + 1);
        }while(*x == *gpsx && *y == *gpsy);  //condicion para que no genere una p encima  de  la g.

        //calcular distancia  en  cada iteracion   
        distancia=sqrt((*x-*gpsx)*(*x-*gpsx)+(*y-*gpsy)*(*y-*gpsy));
        
        if(distancia < distanciafinal){//se  guarda la distancia mas baja  y su posicion
            distanciafinal = distancia;
            *Xmascerca = *x;
            *Ymascerca = *y;
        }

        gotoxy(*x, *y);
        setColor(BLUE);
        printf("p");
    }
}

void puntomascerca(int *Xmascerca, int *Ymascerca){

    gotoxy(*Xmascerca, *Ymascerca);
    setColor(RED);
    printf("c");

}