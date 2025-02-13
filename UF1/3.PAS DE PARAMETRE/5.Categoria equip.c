#include <stdio.h>
#include <rlutil.h>
void categoria(int *sumapunts);
void puntslliga(int jornada, int *sumapunts, int *local, int *visitant, int *puntspartit);
void imprime(int *sumapunts,  int *local, int *visitant, int *puntspartit);
int demanarresultatlocal();
int demanarresultatvisitant();
void imprimetabla( int guardarjornades[10], int guardarlocal[10], int guardarvisitant[10], int guardarpuntspartit[10]);
/*(Categoria equip) Fer un algoritme per portar la
puntuació d’un equip de futbol a la lliga. Aquest
algoritme demanarà deu resultats de deu partits,
seguint el format de local – visitant, on el nostre equip
començarà jugant com a local i anirà alternant a
visitant. Si l’equip guanya, anotarem tres punts. Si
empata, un i si perd, cap punt. Al final s’ha de mostrar
el número de punts assolits per l’equip. Depenent del
número de punts que l’equip assoleixi a aquesta
minilliga, l’equip pot pujar de categoria, mantenir la
categoria o baixar de categoria, segons la següent
taula:
Per tal visualitzar el resultat del nostre equip es
mostrarà en color blau; la resta en color negre.
Punts Resultat
De 0 a 10 Baixa
De 11 a 25 Es manté
Més de 25 Puja */


/*Resum: Demanar els resultats de 10 partits. Primera jornada el  nostre equip es local, a la següent  visitant (alternem).  
Puntuació:
Guanya + 3 punts, empat + 1 punt, perd + 0 punts. Mostrar punts totals al final i mostrar la categoria. 
De 0 a 10 Baixa
De 11 a 25 Es manté
Més de 25 Puja. 

Nota: Per fer el exercici mes visual creare la taula-->  jornada/local/visitant/punts. Marcar el nostre equip de  color blau.  */


/*Funcions a crear: Jornada,  puntuacio  local i visitants,  punts lliga, categoria*/

int main(){

    int sumapunts = 0, local, visitant,  puntspartit = 0; 
    imprime(&sumapunts, &local, &visitant, &puntspartit);
    categoria(&sumapunts);

    getch();
    return 0;
}

//Imprime la tabla de resumen
void imprimetabla( int guardarjornades[10], int guardarlocal[10], int guardarvisitant[10], int guardarpuntspartit[10])
{
    setColor(WHITE);
    printf("\nJornada  Local  Visitant  Punts ");                                    
    for(int j = 0; j < 10; j++){ //pares local
        if(j % 2 == 0){
            setColor(WHITE);
            printf("\n%02d", guardarjornades[j]);
            setColor(BLUE);
            printf("\t  %d", guardarlocal[j]);
            setColor(WHITE);
            printf("\t  %d", guardarvisitant[j]);
            printf("\t   %d", guardarpuntspartit[j]);


        }else if(j % 2 != 0){ //impares visitante
            setColor(WHITE);
            printf("\n%02d", guardarjornades[j]);
            setColor(WHITE);
            printf("\t  %d", guardarlocal[j]);
            setColor(BLUE);
            printf("\t  %d", guardarvisitant[j]);
            setColor(WHITE);
            printf("\t   %d", guardarpuntspartit[j]);


        }   
    }
}

void imprime(int *sumapunts,  int *local, int *visitant, int *puntspartit)
{
    //iniciamos variables  para guardar los datos y correrlos en otro  for
    int guardarjornades[10], guardarlocal[10], guardarvisitant[10], guardarpuntspartit[10];

    for(int jornada = 1; jornada <= 10; jornada++){
        setColor(WHITE);
        printf("\nJornada numero %d:", jornada);
        puntslliga(jornada, sumapunts, local, visitant, puntspartit);
        guardarjornades[jornada - 1] = jornada;
        guardarlocal[jornada - 1] = *local; //goles del local
        guardarvisitant[jornada - 1] = *visitant;
        guardarpuntspartit[jornada - 1] = *puntspartit;  //puntos de cada  partido

    }

    //crea la  tabla
    imprimetabla(guardarjornades, guardarlocal, guardarvisitant, guardarpuntspartit);

}

//Punts de la lliga, marquem el color del  nostre equip, obtenim els gols guardem els punts de cada  partit.
void puntslliga(int jornada, int *sumapunts, int *local, int *visitant, int *puntspartit)
{   
    //nos  permite hacer las operaciones  sabiendo  si somos local o visitante   
    if(jornada % 2 != 0){ // numeros impares ---> equipo local
        
        setColor(BLUE);
        *local = demanarresultatlocal();
        setColor(WHITE);
        *visitant = demanarresultatvisitant();
        //sistema de puntuacion 
        if(*local > *visitant){
            *sumapunts += 3;
            *puntspartit = 3;
        }else if(*local == *visitant){
            *sumapunts += 1;
            *puntspartit = 1;
        }else if (*local < *visitant){
            *sumapunts += 0;
            *puntspartit = 0;
        }

    }else if(jornada % 2 == 0){ // numeros pares --> equipo visitante
        
        setColor(WHITE);
        *local  = demanarresultatlocal();
        setColor(BLUE);
        *visitant = demanarresultatvisitant();
        //sistema de  puntuacion 
        if(*local < *visitant){
            *sumapunts += 3;
            *puntspartit = 3;
        }else if(*local == *visitant){
            *sumapunts += 1;
            *puntspartit = 1;
        }else if (*local > *visitant){
            *sumapunts += 0;
            *puntspartit = 0;
        }
    }
}

//Ens diu la categoria segons  els punts  de totes  les jornades
void categoria(int *sumapunts)
{
    if(*sumapunts < 11){
        printf("\nTens %d punts. Baixa de categoria.", *sumapunts);
    }else if(*sumapunts >= 11 && *sumapunts <= 25){
        printf("\nTens %d punts. Es mante de categoria.", *sumapunts);
    }else if(*sumapunts > 25){
        printf("\nTens %d punts. Puja de categoria.", *sumapunts);
    }
}

//demanem  els punts dels equips
int demanarresultatlocal()
{
    int local;
    printf("\nLocal: ");
    scanf("%d", &local);

    return local;
}

int demanarresultatvisitant()
{
    int visitant;
    printf("\nVisitant: ");
    scanf("%d", &visitant);

    return visitant;
}
