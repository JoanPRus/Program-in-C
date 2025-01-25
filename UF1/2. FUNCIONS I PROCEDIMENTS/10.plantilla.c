#include <stdio.h>
int demanarNumeroControlarPerUnLimit(int limit0);
int demanarNumeroControlarPerDosLimits(int limit1 , int limit2 );
/*Plantilla i actualització de la plantilla amb les funcions:
int demanarNumero ();
int demanarNumeroControlarPerUnLimit(int);
int demanarNumeroControlarPerDosLimits(int ,int );*/

//probar un poco las dos ultimas funciones.

int main(){
    
    demanarNumeroControlarPerUnLimit(5);//parametros que podemos cambiar para poner  otros numeros como  limites
    demanarNumeroControlarPerDosLimits(10,60);
    printf("\nPrem una tecla per finalitzar");

    getch();
    return 0;
}


int demanarNumeroControlarPerUnLimit(int limit1)
{   
    int numero;
    do{
    printf("\nIntrodueix un numero a partir del %d: ", limit1);
    scanf("%d", &numero);
    }while(numero <= limit1);

    return 0;
}

int demanarNumeroControlarPerDosLimits(int limit1 , int limit2)
{   
    int numero;
    do{
    printf("\nIntrodueix un numero a partir del %d fins %d: ", limit1, limit2);
    scanf("%d", &numero);
    }while(numero <= limit1 || numero >= limit2);

    return 0;
}


