#include <stdio.h>
#include <stdbool.h>
#include <rlutil.h>
int demanarany();
int demanarmes();
int demanardia(int mes, bool traspas);
int  demanardiesaveure();
void imprimirdies(int diaseleccionat, int mes, int anyoriginal, int diesaveure, bool traspas);

/*(DiesMesAnyQuantitatDies) A partir d’una data (día, mes i any) es demana
mostrar els n dies següents. Tant la data com la quantitat de dies es
demanarà a l’usuari. S’haurà de tenir en compte els anys de trapàs
“Són de traspàs els anys en què les són múltiples de 4, excepte si els darreres
dos dígits acaben en 00. Aleshores, cal tenir en compte les dues primeres xifres
de l'any. Si són múltiples de 4, l'any també serà de traspàs”
Seguir els següents passos:
− Escriure una funció per tal de validar l'any introduït per l'usuari. L’any ha
d’estar comprès entre 0 i 2050 (ambdós inclosos)
− Escriure una funció que ens retorni un mes correcte (entre 1 i 12)
− Escriure una funció que passant-li el mes ens retorni la quantitat de dies
que té el mes. Cal tenir en compte els anys de traspàs
int quantitatDiesMes(int mes, int any)
− Escriu una funció que ens demani
quants dies volem visualitzar. La
quantitat de dies com a mínim serà 1 i
com a màxim 2000
Cal tenir en compte que per tal de
visualitzar un integer amb tres dígits,
alineat a ma dreta i amb 0 plens per la
part Esquerra, utilitzarem la següent
instrucción:
printf(“%03d”,5) → 005*/

/*Resumen: Pedir el año, el  mes,  el dia (1-31/30/29/28 depende  del mes y año) y el numero de dias que queremos imprimir.
Tener en  cuenta los años bisiestos.
Años = 0/2050. Meses = 1/12. Dias a visualizar 1/2000. Para alinear los numeros printf(“%03d”,5) → 005. 
Para saber si un año es bisiesto --> 
Es bisiesto si-->  El año es multiples de 4 si los dos ultimos digitos no son 0.
Si los dos ultimos digitos son 0 y los dos primeros son multiples de 4 es bisiesto. febrero tiene 29 dias.  */

/*Orden de trabajo:
Funciones para pedir el año (saber si es bisiesto),mes(obtener cuantos dias tiene) y dia(numero de dias que tiene el mes).
Por ultimo  funcion  para pedir los dias que quiere ver y imprimirlos. */

int main(){

    int mes, diaseleccionat, diesaveure, anyoriginal;
    bool traspas = false; 

    anyoriginal = demanarany();
    mes = demanarmes();
    diaseleccionat = demanardia(mes,traspas);
    diesaveure = demanardiesaveure();
    imprimirdies(diaseleccionat, mes, anyoriginal, diesaveure, traspas);

    getch();
    return 0;
}



int demanarany(){ 
    //declaramos variables 
    int any, anyoriginal;
    bool traspas = false; 
    //controlamos el año 
    do{
        printf("Introdueix un any: ");
        scanf("%d", &any);
        anyoriginal = any; 
    }while(any < 0 || any > 2050);

    //Calcular  si es bisiesto:  si año/100 su resto no es 0 (los dos ultimos digitos no son 0) Y si año/4 su resto  es 0 es bisisto
    if(any % 100 != 0 && any % 4 == 0) traspas = true; 
    else if(any % 100 == 0){
        any /= 100;
        if(any % 4 == 0) traspas = true;
    }else traspas = false;

    return anyoriginal;
}

int demanarmes()
{   
    //igual que arriba
    int mes;
    do{
        printf("Introdueix un mes: ");
        scanf("%d", &mes);
    }while(mes < 1 || mes > 12);

    return mes;
}

int demanardia(int mes, bool traspas)
{   
    //Guardamos el dia, controlamos el mes y si es bisiesto
    int diaseleccionat;
    switch (mes)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12: //31 dies
        printf("Introdueix el primer dia entre (1-31): ");
        scanf("%d", &diaseleccionat);
        break;
    case 4: case 6: case 9: case 11: //30 dies
        printf("Introdueix el primer dia entre (1-30): ");
        scanf("%d", &diaseleccionat);
        break; 
    case 2:
        if(traspas == true){
            printf("Introdueix el primer dia entre (1-29): ");
        
        }else if(traspas == false){
            printf("Introdueix el primer dia entre (1-28): ");
            scanf("%d", &diaseleccionat);
        } 
        break;
    }
    return diaseleccionat;
}

int  demanardiesaveure()
{   
    //pedimos los dias que quiere  ver
    int diesaveure;
    printf("Introdueix el  numero de  dies que vols veure: ");
    scanf("%d", &diesaveure);
    
    return diesaveure;
}

void imprimirdies(int diaseleccionat, int mes, int anyoriginal, int diesaveure, bool traspas)
{   
    //Usamos los valores de las variables  de otras funciones y declaramos dos nuevas
    int contador = 0, anyactual;
    //bucle para imprimir
    while(contador != diesaveure){
        printf("\n%003d: %02d/%02d/%003d", contador + 1, diaseleccionat, mes, anyoriginal);
        Sleep(50);
        
        
        //usamos el switch anterior modificado para ir  aumentando las variables que se estan imprimiendo
        switch (mes)
        {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: //31 dies
            diaseleccionat <= 31;
            diaseleccionat ++;
            if(diaseleccionat == 32){
                diaseleccionat = 1;
                mes += 1;
                if(mes == 13){
                    mes = 1;
                    anyoriginal += 1;
                    
                    //miramos que despues de  aumentar un  año sea bisiesto o no
                    anyactual = anyoriginal;

                    if(anyactual % 100 != 0 && anyactual % 4 == 0) traspas = true; 
                    else if(anyactual % 100 == 0){
                        anyactual /= 100;
                        if(anyactual % 4 == 0) traspas = true;
                    }else traspas = false;
                }    
            }
            break;
        case 4: case 6: case 9: case 11: //30 dies
            diaseleccionat <= 30;
            diaseleccionat ++;
            if(diaseleccionat == 31){
                diaseleccionat = 1;
                mes += 1;
            }
            break;
        case 2:
            if(traspas == true){
                diaseleccionat <= 29;
                diaseleccionat ++;
                if(diaseleccionat == 30){
                    diaseleccionat = 1;
                    mes += 1;
                }  
            
            }else if(traspas == false){
                diaseleccionat <= 28;
                diaseleccionat ++;
                if(diaseleccionat == 29){
                    diaseleccionat = 1;
                    mes += 1;
                }
            }    
            break;
        }
        contador ++;  //aumenta el contador fuera del switch. 
    }
    printf("\nPrem una tecla per finalitzar");
}



