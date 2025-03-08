#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <rlutil.h>
#include<stdbool.h>
#define MAXVECTOR 24
#define HORAMINRANG1 0
#define HORAMAXRANG1 10
#define TEMMINRANG1 -10
#define TEMMAXRANG1 12
#define HORAMINRANG2 11
#define HORAMAXRANG2 18
#define TEMMINRANG2 10
#define TEMMAXRANG2 20
#define HORAMINRANG3 19
#define HORAMAXRANG3 23
#define TEMMINRANG3 0
#define TEMMAXRANG3 10
#define numeroelementosdetemperaturaminima 3

void imprimirresultados(int v[], int num_elementos);
void incrementartemperatura(int v[]);
void promediotemperatura(int v[], float *promedio);
void pedirtemperatura(int v[]);
void promedioentrehoras(int v[]);
void calcularpromedioentrehoras(int v[], int horainicial, int horafinal);
void temperaturamediaporrangos(int v[]);
void temperaturasPorEncimaDeLaMedia(int v[], float  *promedio);
void eliminartemperatura(int v[]);
void trestemperaturasminimas(int v[]);
int funciontempminima(int v[], int numeroelementos, int tempminima);
/*A continuació, i a través de la definició del vector fixarem unes temperatures
per tal de facilitar els resultats dels exercicis següents
int v[MAXVECTOR] = {0,3,4,0,-4,-1,7,4,4,8,10,16,10,14,18,20,17,13,12,11,7,4,3,0};
2. Hi ha hagut un error en el termòmetre. Totes les temperatures captades pel
termòmetre que són negatives, cal incrementar-li 2ºC
3. Calcula el promig de les temperatures en graus Celsius. No s’ha de tenir en
compte la modificació que s’ha fet en l’exercici 2.
Promig es 7.50 Graus Celsius
4. Demana una temperatura a l’usuari i indica en quina hora s’ha produït. Només
ens interessa la primera hora en la que s’ha produït.
Introdueix la temperatura que vols consultar : 10
La temperatura 10 ha aparegut per primera vegada a les 10 hores.
Introdueix la temperatura que vols consultar : 2
La temperatura 02 no ha aparegut avui!
5. Fes una nova funció que calculi el promig de les temperatures enregistrades
entre una hora inicial i una hora final. Cal controlar que l’hora final sigui
superior a l’hora inicial. Evidentment les hores han d’estar controles dins del
marge 0 i 23.
float calculMitjaEntreDuesHores(int v[],int horaInici, int
horaFinal)
Introdueix hora inicial: 3
Introdueix hora final: 4
EL promig de les temperatures entre les 3 i les 4 ha sigut de -
2.00
6. Quina és la temperatura mitja per a cadascuna dels rang (0-10, 11-18 i 19-
23). Caldrà fer un procediment que ens retorni simultàniament els tres
promitjos. Evidentment dins del procediment, caldrà fer crides a la funció de
l’exercici 5.
Temperatures promig per a cada tram : 3.18 , 15.00 , 5.00 Graus
Celsius
7. Indica quines són les hores en què temperatura ha estat per sobre de la mitja.
Cal desar les hores en un nou vector; i al final mostrar el vector
8. Demana a l’usuari quina temperatura vol eliminar i elimina tots els cops on
apareix aquest valor.
9. Indica les tres temperatures mínimes, sense utilitzar mètodes d’ordenació.
Procediment:
a. Defineix un vector de temperatures mínimes amb 3 caselles
b. Omple la primera casella amb el valor més petit de les temperatures.
En el nostre cas en la casella 0 inserirà un -4
c. Fes una funció que passant-li el vector, la quantitat d’elements i una
temperatura mínima; ens retorni la temperatura mínima superior a la
temperatura que li hem passat com a paràmetre
En el nostre cas , en la primera crida a la funció li passarem
el -3 i retornarà el -1
En la segona crida a la funció se li passarà un -1 i retornarà
el 0.*/

//modificamos  un poco el ejercicio  el anterior para  hacer este

int main(){

    int v[MAXVECTOR] = {0,3,4,0,-4,-1,7,4,4,8,10,16,10,14,18,20,17,13,12,11,7,4,3,0};
    float promedio = 0;

    imprimirresultados(v, MAXVECTOR);
    printf("\n--------------------------------------");
    incrementartemperatura(v);
    printf("\n--------------------------------------");
    promediotemperatura(v, &promedio);
    printf("\n--------------------------------------");
    pedirtemperatura(v);
    printf("\n--------------------------------------");
    promedioentrehoras(v);
    printf("\n--------------------------------------");
    temperaturamediaporrangos(v);
    printf("\n--------------------------------------");
    temperaturasPorEncimaDeLaMedia(v, &promedio);
    printf("\n--------------------------------------");
    eliminartemperatura(v);
    printf("\n--------------------------------------");
    trestemperaturasminimas(v);
    getch();
    return 0;
}

//imprime los  resultados del vector
void imprimirresultados(int v[], int num_elementos)
{
    for(int j = 0; j < num_elementos; j++){

        if(j <= HORAMAXRANG1){
            
            setColor(BLUE);
            printf("[%2d]: ", j);

            setColor(WHITE);
            printf("%2d", v[j]);

            printf("\n");

        }else if(j >= HORAMINRANG2  &&  j <= HORAMAXRANG2){
            setColor(RED);
            printf("[%2d]: ", j);

            setColor(WHITE);
            printf("%2d", v[j]);

            printf("\n");

        }else if(j >= HORAMINRANG3  &&  j <= HORAMAXRANG3){
            setColor(GREEN);
            printf("[%2d]: ", j);

            setColor(WHITE);
            printf("%2d", v[j]);

            printf("\n");
            
        }   
    }
}

/*2. Hi ha hagut un error en el termòmetre. Totes les temperatures captades pel
termòmetre que són negatives, cal incrementar-li 2ºC*/

void incrementartemperatura(int v[]){

    int vmodificat[MAXVECTOR] = {};  //nuevo  vector  donde copiaremos el anterior con sus modificaciones
    
    for(int  i = 0;  i < MAXVECTOR; i++){

        if(v[i] < 0){ //si es negativo le  sumaremos dos y lo  guardamos en el  nuevo vector
            vmodificat[i] = v[i] + 2; 
        }else vmodificat[i] = v[i]; //lo copia y ya  esta  

    }
    printf("\n\nVector modificado:\n");
    imprimirresultados(vmodificat, MAXVECTOR); //usamos la funcion  de  imprimir  pero con un nuevo parametro que es el vector copiado y modificado
}

/*3. Calcula el promig de les temperatures en graus Celsius. No s’ha de tenir en
compte la modificació que s’ha fet en l’exercici 2.
Promig es 7.50 Graus Celsius*/

void promediotemperatura(int v[], float *promedio)
{   
    float suma = 0, resultado = 0;
    for(int i = 0; i < MAXVECTOR; i++){

        suma += v[i];
    }
    resultado = suma / 24;
    printf("\nEl promedio es %f", resultado);
    *promedio = resultado;  
}

/*4. Demana una temperatura a l’usuari i indica en quina hora s’ha produït. Només
ens interessa la primera hora en la que s’ha produït.
Introdueix la temperatura que vols consultar : 10
La temperatura 10 ha aparegut per primera vegada a les 10 hores.
Introdueix la temperatura que vols consultar : 2
La temperatura 02 no ha aparegut avui!*/

void pedirtemperatura(int v[])
{
    int temperatura;
    bool temperaturaexistente = false;

    printf("\n\nIntrodueix una temperatura: ");
    scanf("%d", &temperatura);

    for(int i = 0; i < MAXVECTOR; i++){

        if(v[i] == temperatura){
            printf("\nLa temperatura %d ha aparecido a las %d horas por primera vez", temperatura, i);
            temperaturaexistente = true;
            break;
        }    
    }

    if(temperaturaexistente == false){
        printf("La temperatura %d no ha aparecido en ninguna hora", temperatura);
    }
}

/*5. Fes una nova funció que calculi el promig de les temperatures enregistrades
entre una hora inicial i una hora final. Cal controlar que l’hora final sigui
superior a l’hora inicial. Evidentment les hores han d’estar controles dins del
marge 0 i 23.
float calculMitjaEntreDuesHores(int v[],int horaInici, int
horaFinal)
Introdueix hora inicial: 3
Introdueix hora final: 4
EL promig de les temperatures entre les 3 i les 4 ha sigut de -
2.00*/

void promedioentrehoras(int v[])
{
    int horainicial = 0, horafinal = 0;

    do{
        printf("\n\nIntroduce la hora  inicial: ");
        scanf("%d", &horainicial);
    }while(horainicial < 0 || horafinal > 23);

    do{
        printf("Introduce la  hora  final: ");
        scanf("%d",  &horafinal);
    }while(horafinal < horainicial || horafinal > 23);
    
    calcularpromedioentrehoras(v, horainicial, horafinal);
}

void calcularpromedioentrehoras(int v[], int horainicial, int horafinal)
{   
    float suma = 0, resultado = 0;
    for(int i = horainicial; i <= horafinal; i++){

        suma += v[i];
    }

    resultado = suma / (horafinal - horainicial + 1);
    printf("\n\nEl promedio de las temperaturas entre las  %d y las %d es: %f", horainicial, horafinal, resultado);
}

/*6. Quina és la temperatura mitja per a cadascuna dels rang (0-10, 11-18 i 19-
23). Caldrà fer un procediment que ens retorni simultàniament els tres
promitjos. Evidentment dins del procediment, caldrà fer crides a la funció de
l’exercici 5.
Temperatures promig per a cada tram : 3.18 , 15.00 , 5.00 Graus
Celsius*/

void temperaturamediaporrangos(int v[])
{   
    printf("\n\nPromedio por rangos: ");
    calcularpromedioentrehoras(v, HORAMINRANG1, HORAMAXRANG1);
    calcularpromedioentrehoras(v, HORAMINRANG2, HORAMAXRANG2);
    calcularpromedioentrehoras(v, HORAMINRANG3, HORAMAXRANG3);
}

/*7. Indica quines són les hores en què temperatura ha estat per sobre de la mitja.
Cal desar les hores en un nou vector; i al final mostrar el vector*/

void temperaturasPorEncimaDeLaMedia(int v[], float  *promedio){

    int  vm[MAXVECTOR] = {};
    int j = 0;

    for(int i = 0; i < MAXVECTOR; i++){

        if(v[i] > *promedio){
            vm[j] = v[i];
            j++;
        }
    }

    printf("\n\nVector  con temperaturas por encima de la  media %f\n", *promedio);
    imprimirresultados(vm, j);
}

/*8. Demana a l’usuari quina temperatura vol eliminar i elimina tots els cops on
apareix aquest valor.*/

void eliminartemperatura(int v[]){
    int temperatura;
    int  j = 0;
    int vnuevo[MAXVECTOR] = {};
    
    printf("\n\nIntroduce la temperatura que quieras eliminar: ");
    scanf("%d", &temperatura);

    for(int i = 0; i < MAXVECTOR; i++){

        if(v[i] != temperatura){
            vnuevo[j] = v[i];
            j++;
        }
    }

    imprimirresultados(vnuevo, j);
}

/*9. Indica les tres temperatures mínimes, sense utilitzar mètodes d’ordenació.
Procediment:
a. Defineix un vector de temperatures mínimes amb 3 caselles
b. Omple la primera casella amb el valor més petit de les temperatures.
En el nostre cas en la casella 0 inserirà un -4
c. Fes una funció que passant-li el vector, la quantitat d’elements i una
temperatura mínima; ens retorni la temperatura mínima superior a la
temperatura que li hem passat com a paràmetre
En el nostre cas , en la primera crida a la funció li passarem
el -3 i retornarà el -1
En la segona crida a la funció se li passarà un -1 i retornarà
el 0.*/

void trestemperaturasminimas(int v[]){
    int vmin[numeroelementosdetemperaturaminima] = {-4}; //paso  A y  B

    vmin[1] = funciontempminima(v, MAXVECTOR, -3); 
    vmin[2] = funciontempminima(v, MAXVECTOR, -1); 
    //printf("\n\nLas 3 temperaturas mas bajas son: %d %d %d", vmin[0], vmin[1], vmin[2]);
    printf("\n\nLas tres temperaturas mas bajas\n");
    imprimirresultados(vmin, 3);
}

//A la funcion hay  que pasarle el vector, cantidad de elementos  y temperatura minima

int funciontempminima(int v[], int numeroelementos, int tempminima){
    
    int numero = 900;

    for(int i = 0; i < MAXVECTOR; i++){

        if(v[i] > tempminima && v[i] < numero){

            numero = v[i]; 
        }
    }
    
   return numero;
}