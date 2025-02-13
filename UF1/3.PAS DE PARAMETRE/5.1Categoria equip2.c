#include <stdio.h>
#include <rlutil.h>
void GolsEquipVisitant(int *golsvisitant);
void GolsEquipLocal(int *golslocal);
void numerodejornada(int *golslocal,  int *golsvisitant, int *sumapunts, int *puntspartit, int indexgolslocal[10], int indexgolsvisitant[10], int indexpuntspartit[10]);
void PuntuacioLligaSentVisitant(int *golslocal, int *golsvisitant, int *sumapunts, int *puntspartit);
void PuntuacioLligaSentLocal(int *golslocal, int *golsvisitant, int *sumapunts, int *puntspartit);
void categoria(int *sumapunts);
void taula(int indexgolslocal[10],  int indexgolsvisitant[10], int indexpuntspartit[10]);
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


/*Resum: Demanar el   resultats del partit, començem  en local  y  despres en visitant (alternem).
Puntuació per  partit-->  Guanya +3  punts, empat +1 punts, perd +0 punts. 
Categoria al final-->  0-10 baixa, 11-25 es manté, + de 25 puja.
Notes: Per diferenciar el nostre equip sera de  color blau.  Crear una taula al  final amb tota la informació.*/


int main(){
    int sumapunts = 0, golsvisitant = 0, golslocal = 0, puntspartit = 0, indexgolslocal[10], indexgolsvisitant[10], indexpuntspartit[10];
    
    numerodejornada(&golslocal, &golsvisitant, &sumapunts, &puntspartit, indexgolslocal, indexgolsvisitant, indexpuntspartit);
    categoria(&sumapunts);
    taula(indexgolslocal, indexgolsvisitant, indexpuntspartit);


    getch();
    return 0;
}
//Nota: Els arrays no es declaren com  a  punters. 
//Crear  taula  amb  aquestes variables:  i, golslocal, golsvisitant, puntspartit
void taula(int indexgolslocal[10],  int indexgolsvisitant[10], int indexpuntspartit[10]){
    
    printf("\nJornada   Local     Visitant  Punts");//columnes de la  taula
    for(int i = 0; i < 5; i++){
        setColor(WHITE);
        printf("\n%d", i + 1);
        //marca  els  gols en color  blau els  del nostre equip
        if(i % 2 == 0){ //local de color blau
            setColor(BLUE);
            printf("          %d", indexgolslocal[i]);
            setColor(WHITE);
            printf("          %d", indexgolsvisitant[i]);
        }else if(i % 2 != 0){ //visitant color blau
            setColor(WHITE);
            printf("          %d", indexgolslocal[i]);
            setColor(BLUE);
            printf("          %d", indexgolsvisitant[i]);
        }
        setColor(WHITE);
        printf("          %d", indexpuntspartit[i]);
    }
}

//Funcio per les jornades i  per demanar le numero de gols
void numerodejornada(int *golslocal,  int *golsvisitant, int *sumapunts, int *puntspartit, int indexgolslocal[10], int indexgolsvisitant[10], int indexpuntspartit[10])
{    
    for(int i = 1; i <= 5; i++){
        setColor(WHITE);
        printf("\nJornada numero %d:", i);
        
        //condició per marca  el nostre  equip de  color blau
        if(i % 2 == 0){// visitant  blau
            setColor(WHITE);
            GolsEquipLocal(golslocal);
            setColor(BLUE);
            GolsEquipVisitant(golsvisitant);
            PuntuacioLligaSentVisitant(golslocal, golsvisitant, sumapunts, puntspartit);
        }else if(i % 2 != 0){// LOCAL  blau
            setColor(BLUE);
            GolsEquipLocal(golslocal);
            setColor(WHITE);
            GolsEquipVisitant(golsvisitant);
            PuntuacioLligaSentLocal(golslocal, golsvisitant, sumapunts, puntspartit);
        }
        //guarden en  el  array els valors de les variables  per fer  després la taula. 
        indexgolslocal[i - 1] = *golslocal;
        indexgolsvisitant[i - 1] = *golsvisitant;
        indexpuntspartit[i - 1] = *puntspartit;
    }
}

//funció categoria determina segons els  punts
void categoria(int *sumapunts)
{
    if(*sumapunts > 25){
        printf("\nPunts totals %d. Puja de  categoria", *sumapunts);
    }else if(*sumapunts > 11 && *sumapunts <= 25){
        printf("\nPunts totals %d. Es mante de categoria", *sumapunts);
    }else if (*sumapunts > 0 && *sumapunts <= 10){
        printf("\nPunts totals %d. Baixa de categoria", *sumapunts);
    }
}

//Funcions per fer la puntuacio total
void PuntuacioLligaSentLocal(int *golslocal, int *golsvisitant, int *sumapunts, int *puntspartit)
{
    if(*golslocal > *golsvisitant){
        *sumapunts += 3;
        *puntspartit = 3;
    }else if(*golslocal == *golsvisitant){
        *sumapunts += 1;
        *puntspartit = 1;
    }else if (*golslocal < *golsvisitant){
        *sumapunts += 0;
        *puntspartit = 0;
    }
}

void PuntuacioLligaSentVisitant(int *golslocal, int *golsvisitant, int *sumapunts, int *puntspartit)
{
    if(*golslocal < *golsvisitant){
        *sumapunts += 3;
        *puntspartit = 3;
    }else if(*golslocal == *golsvisitant){
        *sumapunts += 1;
        *puntspartit = 1;
    }else if (*golslocal > *golsvisitant){
        *sumapunts += 0;
        *puntspartit = 0;
    }
}

//Funcions  per  demanar la puntuacio del local y visitant.
void GolsEquipLocal(int *golslocal)
{
    printf("\nGols equip Local: ");
    scanf("%d", golslocal);
}

void GolsEquipVisitant(int *golsvisitant)
{
    printf("\nGols equip visitant: ");
    scanf("%d", golsvisitant);
}