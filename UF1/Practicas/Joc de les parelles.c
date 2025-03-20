#include <stdio.h>
#include <rlutil.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 8
void presentacio();
void omplir_posicions(int posicions[]);
void generar_valors(int valors_parelles[]);
void mostrar_caselles_pendents(int posicions[], char valors_sense_mostrar[]);
void demanar_casella_usuari(int posicions[], int posicions_esbrinades[],  int posicions_seleccionades[],  int valors_parelles[]);
void demanar_casella_ordinador(int posicions[], int posicions_esbrinades[], int posicions_seleccionades[], int valors_parelles[]);
bool determinar_si_son_parella(int posicions_seleccionades[], int valors_parelles[]);
void destapem_caselles(int posicions[], char valors_sense_mostrar[], int  posicions_seleccionades[], int valors_parelles[]);
void control_partida(int posicions[], int valors_parelles[], char valors_sense_mostrar[], int posicions_seleccionades[], int parelles_esbrinades_usuari[], int parelles_esbrinades_ordinador[], int posicions_esbrinades[]);
/*Necesitem  una  graella amb  les posicions   0-7,  altra amb els valors  de  les parelles 1-4 i  desordenar els valors en la graella.
Indiquem dues caselles ens  monstren els  valors de les  dues caselles seleccionades. 
Jugar  amb el ordinador, comença  el jugador, si  no fa parella  perd el  torn i  els  valors es queden,   si fa parella es  retiren i  
es  queda la parella. Finalitza quan ja  no  hi ha   mes  parelles a esbrinar.  Determinar guanyador del joc,  el que  te  mes parelles. 
Mostrar els numeros  obtinguts de cada jugador*/

int main(){
    int posicions[MAX]  = {};
    int valors_parelles[MAX] = {};
    char valors_sense_mostrar[MAX] = "????????";
    int posicions_seleccionades[MAX] = {};
    int parelles_esbrinades_usuari[MAX] = {};
    int parelles_esbrinades_ordinador[MAX] = {};
    int posicions_esbrinades[MAX] = {-1,-1,-1,-1,-1,-1,-1,-1,};
    srand(time(NULL));
    presentacio();
    omplir_posicions(posicions);
    generar_valors(valors_parelles);
    control_partida(posicions, valors_parelles, valors_sense_mostrar, posicions_seleccionades, parelles_esbrinades_usuari,parelles_esbrinades_ordinador, posicions_esbrinades);

    getch();
    return 0;
}

/*Pasos: 
1.Presentació del joc amb unes instruccions básiques.
2.Generar els vectors de les  posicions 0-7,  dels valors 1-4 aleatoriament.
3.Mostrar caselles pendents
4.Demanar les  posiciones tant jugador com ordinador,  controlar que estiguin en el rang i que les posicions seleccionades no hagin
estat parella abans.
5.Destapem  les caselles seleccionades
6.Determinar si son parella, el torn, guardar el  numero si  es  parella al jugador per mostrar-lo al finalitzar el joc. 
Controlar el que  es  monstra  y  les  entrades si  hem fet parella, modificar vector*/

void control_partida(int posicions[], int valors_parelles[], char valors_sense_mostrar[], int posicions_seleccionades[], int parelles_esbrinades_usuari[], int parelles_esbrinades_ordinador[], int posicions_esbrinades[]){
    bool totes_les_parelles_esbrinades = false;
    bool encerta_parella = false;
    bool torn_usuari = true;
    int index = 0;
    int index_usuari = 0;
    int index_ordinador = 0;

    while(totes_les_parelles_esbrinades == false){

        mostrar_caselles_pendents(posicions, valors_sense_mostrar);
        
        if(torn_usuari == true){
            printf("\n\nTorn del usuari:");
            demanar_casella_usuari(posicions, posicions_esbrinades, posicions_seleccionades, valors_parelles);
            encerta_parella = determinar_si_son_parella(posicions_seleccionades, valors_parelles);   //problema retorna false cuando  tiene que ser true
            if(encerta_parella == true){
                torn_usuari = true;
            }else torn_usuari = false;
        }else{
            printf("\n\ntorn del  ordinador:");
            demanar_casella_ordinador(posicions, posicions_esbrinades, posicions_seleccionades, valors_parelles);
            encerta_parella = determinar_si_son_parella(posicions_seleccionades, valors_parelles);
            if(encerta_parella == true){
                torn_usuari = false;
            }else torn_usuari = true;
        }

        destapem_caselles(posicions, valors_sense_mostrar, posicions_seleccionades, valors_parelles);
        if(encerta_parella ==  true){
            printf("\ntenim una parella");
            posicions_esbrinades[index] = posicions_seleccionades[0];
            index++;
            posicions_esbrinades[index] = posicions_seleccionades[1];
            index++;
            valors_sense_mostrar[posicions_seleccionades[0]] = 'X'; 
            valors_sense_mostrar[posicions_seleccionades[1]] = 'X';
        }else printf("\nNo tenim una parella");

        if(encerta_parella ==  true && torn_usuari == true){
            parelles_esbrinades_usuari[index_usuari] = valors_parelles[posicions_seleccionades[0]];
            index_usuari++;
        }else if(encerta_parella ==  true && torn_usuari == false){
            parelles_esbrinades_ordinador[index_ordinador] = valors_parelles[posicions_seleccionades[0]];
            index_ordinador++;
        }

        printf("\nPrem una tecla");
        getch();
        cls();

        if(index > 7){
            totes_les_parelles_esbrinades = true;
            printf("\nPrem una tecla per veure el resum del joc");
            getch();
        }    
    }

    if(index_usuari > index_ordinador){
        printf("\nEl usuari a guanyat");
    }else if(index_usuari < index_ordinador){
        printf("\nEl ordinador a guanyat");
    }else printf("\nTenim un empat");

    printf("\nNumeros obtinguts pel usuari: ");
    for(int i = 0; i < index_usuari; i++){  
        printf("%d ", parelles_esbrinades_usuari[i]);
    }

    printf("\nNumeros obtinguts pel ordinador: ");
    for(int i = 0; i < index_ordinador; i++){
        printf("%d ", parelles_esbrinades_ordinador[i]);
    }
}

void destapem_caselles(int posicions[], char valors_sense_mostrar[], int  posicions_seleccionades[], int valors_parelles[]){
    printf("\nDestapem les caselles seleccionades:");
    printf("\nPosicio:  ");
    for(int i = 0; i < MAX; i++){
        printf("%d ", posicions[i]);
    }
    printf("\nValors:   ");
    for(int i = 0; i < MAX; i++){

        if(i == posicions_seleccionades[0]){
            printf("%d ", valors_parelles[posicions_seleccionades[0]]);
        }else if(i == posicions_seleccionades[1]){
            printf("%d ", valors_parelles[posicions_seleccionades[1]]);
        }else printf("%c ", valors_sense_mostrar[i]);
    } 
}

bool determinar_si_son_parella(int posicions_seleccionades[], int valors_parelles[]){

    bool son_parella = false;

    if(valors_parelles[posicions_seleccionades[0]] == valors_parelles[posicions_seleccionades[1]]){
        son_parella = true;
    }

    return son_parella;
}

void demanar_casella_ordinador(int posicions[], int posicions_esbrinades[], int posicions_seleccionades[], int valors_parelles[]){
    int num1 = 0, num2 = 0;
    bool posicio_descoberta = false;
    do{
        posicio_descoberta = false;
        printf("\nPrimera casella: ");
        num1 = rand() % 8;
        printf("%d", num1);

        for(int i = 0; i < MAX; i++){

            if(posicions_esbrinades[i] == num1){
                posicio_descoberta = true;
            }
        }

        if(posicio_descoberta == false){
            posicions_seleccionades[0] = num1;
        }
    }while(num1 < 0 ||  num1 > 7 || posicio_descoberta == true);

    do{
        posicio_descoberta = false;
        printf("\nSegona casella: ");
        num2 = rand() % 7 + 1;
        printf("%d", num2);

        for(int i = 0; i < MAX; i++){

            if(posicions_esbrinades[i] == num2){
                posicio_descoberta = true;
            }
        }

        
        if(posicio_descoberta == false){
            posicions_seleccionades[1] = num2;
        }

    }while(num1 < 0 ||  num1 > 7 || posicio_descoberta == true || num1 == num2);
}

void demanar_casella_usuari(int posicions[], int posicions_esbrinades[], int posicions_seleccionades[], int valors_parelles[]){
    int num1 = 0, num2 = 0;
    bool posicio_descoberta = false;
    do{
        posicio_descoberta = false;
        printf("\nPrimera casella: ");
        scanf("%d", &num1);

        for(int i = 0; i < MAX; i++){

            if(posicions_esbrinades[i] == num1){
                posicio_descoberta = true;
            }
        }

        
        if(posicio_descoberta == false){
            posicions_seleccionades[0] =  num1;
        }

    }while(num1 < 0 ||  num1 > 7 || posicio_descoberta == true);

    do{
        posicio_descoberta = false;
        printf("Segona casella: ");
        scanf("%d", &num2);

        for(int i = 0; i < MAX; i++){

            if(posicions_esbrinades[i] == num2){
                posicio_descoberta = true;
            }
        }
        
        if(posicio_descoberta == false){
            posicions_seleccionades[1] =  num2;
        }

    }while(num1 < 0 ||  num1 > 7 || posicio_descoberta == true || num1 == num2);

}

void mostrar_caselles_pendents(int posicions[], char valors_sense_mostrar[]){
    printf("\n\nCaselles pendents:");
    printf("\nPosicio:  ");
    for(int i = 0; i < MAX; i++){
        printf("%d ", posicions[i]);
    }
    printf("\nValors:   ");
    for(int i = 0; i < MAX; i++){
        if(valors_sense_mostrar[i] == 'X'){
            setColor(BLUE);
            printf("%c ", valors_sense_mostrar[i]);
        
        }else{
            setColor(WHITE);
            printf("%c ", valors_sense_mostrar[i]);
        }
    }
}
void generar_valors(int valors_parelles[]){
    int num = 0;
   
    for(int i = 0; i < MAX; i++){
        int contador = 0;
        num = rand() % 4 + 1;

        for(int j = 0; j < i; j++){

            if(valors_parelles[j] == num){
                contador++;
            }
        }
        if(contador >= 2){
            i--;
        }else{
            valors_parelles[i] = num;
        }
    } 
}

void omplir_posicions(int posicions[]){

    for(int i = 0; i < MAX; i++){
        posicions[i] = i;
    }
}

void presentacio(){

    printf("\nBenvingut al joc de  les parelles");
    printf("\n\nInstruccions: ");
    printf("\nEl joc  consisteix en adivinar les parelles en les seves respectives posicions.");
    printf("\nEl jugador que al finalitzar el  joc hagi obtingut mes  parelles guanya.");
    printf("\n\nPrem una tecla per iniciar el  joc");
    getch();
    cls();
}