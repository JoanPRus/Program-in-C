#include <stdio.h>
#include <stdbool.h>
#include <rlutil.h>
#include <stdlib.h>
#include <time.h>
#define max_casellas 100
#define max_escales 20
#define min_escales 2
#define max_extintors 10
#define min_extintors 2
void demanar_numero_escales(int *numero_de_escales);
void posicions_de_cada_escala(int *numero_de_escales, int posicions_escales_inici[], int posicions_escales_final[]);
bool control_escales_iguals(int posicions_escales_inici[],int posicions_escales_final[], int casella_superior_escala, int casella_inferior_escala);
bool control_escales_final_inci(int posicions_escales_inici[], int casella_superior_escala);
int demanar_casella_escales(const char *mensaje, int min,  int casella);
void demanar_numero_extintors(int *numero_extintors);
void demanar_posicions_extintors(int posicions_escales_inici[], int posicions_escales_final[], int *numero_extintors, int posicions_extintors[]);
void recorregut_bombers(int posicions_escales_inici[], int posicions_escales_final[], int posicions_extintors[]);
/*Bombers casella 0, casa  amb foc casella 100. Saltem les caselles amb un dau 1-6.
 Arribem quan  la casella del bombers sigui igual  o major a 100.
1.Tenim  escales durant el  recorregut,  fan  que recullin n  posicions. 
Demanar quantes escales vol posar 2-20. Demanar el punt de  inici i  final de cada escala
minim 5 caselles de diferencia. Controlar que no   quan el  bomber cau per  una escala 
al final  no  pot haber altra escala. La escala final  no  pot haber  una escala  inici. 
De diferents inicis  si poden  terminar  en la  mateixa casella final. 
No poden  tenir  dos  escales  amb el mateix inici  i final.
2.Demar numero de  extintors  2-10.
Demanar en que  posicions  els vol  colocar, no es  pot en  la casella 0 i  100.
En  cada casella nomes pot haber  1 extintor. No podem tenir  
un extintor  en una  casella que te una  escala.

Mostrar per pantalla les caselles que  han pasat els bombers, indicar  
si ha  trobat una escala o  extintor.
missatge final amb  el numero de extintors.*/

int main(){
    int numero_de_escales, numero_extintors;
    int posicions_escales_inici[max_escales] = {};
    int posicions_escales_final[max_escales] = {};
    int posicions_extintors[max_extintors] = {};

    demanar_numero_escales(&numero_de_escales);
    posicions_de_cada_escala(&numero_de_escales, posicions_escales_inici, posicions_escales_final);
    demanar_numero_extintors(&numero_extintors);
    demanar_posicions_extintors(posicions_escales_inici, posicions_escales_final, &numero_extintors, posicions_extintors);
    recorregut_bombers(posicions_escales_inici, posicions_escales_final, posicions_extintors);
    getch();
    return 0;
}

/*Pasos:
1.Demanar numero de escales
2.Demanar punt inicial i final, amb  condicions.
3.Demanar numeros  de extintors,  amb condicions
4. Moviment dels bombers */

void recorregut_bombers(int posicions_escales_inici[], int posicions_escales_final[], int posicions_extintors[]){

    bool hem_arribat_al_foc = false;
    int posicio = 0, salt = 1, nova_posicio = 0;
    int contador_extintors = 0;

    printf("\n\nsalt:    posicio     dau     nova_posicio");

    while(hem_arribat_al_foc == false){

        int dau = rand() % 6 + 1;
        nova_posicio = posicio  + dau;

        printf("\n%2d:         %2d   +   %2d    =      %2d", salt,  posicio, dau, nova_posicio);
        posicio = nova_posicio;
        salt++;
        for(int i = 0;  i < max_escales; i++){

            if(nova_posicio == posicions_escales_inici[i]){
                printf("    hi  ha una escala i es  passa a --> %d",posicions_escales_final[i]);
                posicio = posicions_escales_final[i];
                break;
            }

            if(i < max_extintors && nova_posicio == posicions_extintors[i]){
                printf("    hem trobat un extintor");
                contador_extintors++;
                break;
            }
        }

        if(nova_posicio >= 100){
            hem_arribat_al_foc = true;
        }
    }

    printf("\nHem arribat al  foc amb %d extintors", contador_extintors);
}

void demanar_posicions_extintors(int posicions_escales_inici[], int posicions_escales_final[], int *numero_extintors, int posicions_extintors[]){

    bool tenim_tots_els_extintors = false;
    bool no_extintor = false;
    int i = 0;
    int posicio_extintor;

    while(tenim_tots_els_extintors == false){

        if(no_extintor == false){
            printf("\n----GENERANT EXTINTORS %d----", i + 1);
        }
        no_extintor = false;
        printf("\nIntrodueix la  posicio del extintor:  ");
        scanf("%d", &posicio_extintor);

        for(int j = 0; j < max_extintors; j++){

            if(posicio_extintor == posicions_escales_final[j] ||posicio_extintor == posicions_escales_inici[j]){
                printf("\nNo es pot colocar un extintor on hi ha una escala");
                no_extintor = true;
                break;
            }

            if(posicio_extintor == posicions_extintors[j]){
                printf("\nNo es  pot colocar un  extintor  perque ja  hi  ha  un");
                no_extintor = true;
                break;
            }
        }

        if(no_extintor == false){
            posicions_extintors[i] = posicio_extintor;
            i++;

            if(i == *numero_extintors){
                tenim_tots_els_extintors = true;
            }
        }
    }
}

void demanar_numero_extintors(int *numero_extintors){
    
    do{
        printf("\nIntrodueix el numero de extintors (2-10): ");
        scanf("%d", numero_extintors);
    }while(*numero_extintors >  max_extintors  || *numero_extintors < min_extintors);
}

void demanar_numero_escales(int *numero_de_escales){

    do{
        printf("\nIntrodueix  el  numero  de  escales que vols (2-20): ");
        scanf("%d", numero_de_escales);
    }while(*numero_de_escales > max_escales || *numero_de_escales < min_escales);
}

void posicions_de_cada_escala(int *numero_de_escales, int posicions_escales_inici[], int posicions_escales_final[]){

    int i = 0;
    int casella_superior_escala, casella_inferior_escala;
    bool posicio_escala_no_valida, posicio_escala_igual;
    int min = *numero_de_escales;
    bool numero_escales_complet = false;

    while(numero_escales_complet == false){

        if(posicio_escala_igual == false && posicio_escala_no_valida == false){
            printf("\n----GENERANT ESCALA %d----", i + 1);
        }

        posicio_escala_no_valida = false, posicio_escala_igual = false;
        casella_superior_escala = demanar_casella_escales("Introdueix la casella superior de la escala", min, max_casellas);
        casella_inferior_escala = demanar_casella_escales("Introdueix la casella inferior de la escala", 0, casella_superior_escala - 5);
        
        posicio_escala_no_valida = control_escales_final_inci(posicions_escales_inici, casella_superior_escala);
        posicio_escala_igual = control_escales_iguals(posicions_escales_inici, posicions_escales_final, casella_superior_escala,  casella_inferior_escala);

        if(posicio_escala_igual == false && posicio_escala_no_valida == false){
            posicions_escales_inici[i] = casella_superior_escala;
            posicions_escales_final[i] = casella_inferior_escala;
            i++;
            if(i == *numero_de_escales){
                numero_escales_complet = true;
            }
        }

        if(posicio_escala_igual == true){
            printf("Cal inserir altra  posicio, tenim una escala amb el  mateix inici i final");
        }else if(posicio_escala_no_valida == true){
            printf("Cal inserir altra  posicio, has posat el  inici  de  una escala amb el final de altra");
        }
    }
}

bool control_escales_iguals(int posicions_escales_inici[],int posicions_escales_final[], int casella_superior_escala, int casella_inferior_escala){

    bool posicio_escala_no_valida = false;

    for(int j = 0;  j < max_escales; j++){

      if(casella_superior_escala == posicions_escales_inici[j] && casella_inferior_escala == posicions_escales_final[j]){
        posicio_escala_no_valida  = true;
        break;
      }   
    }
    return posicio_escala_no_valida;
}

bool control_escales_final_inci(int posicions_escales_inici[], int casella_superior_escala){
    
    bool posicio_escala_no_valida = false;

    for(int j = 0;  j < max_escales; j++){

        if(casella_superior_escala == posicions_escales_inici[j]){
            posicio_escala_no_valida = true;
            break;
        }
    }
    return posicio_escala_no_valida;
}

int demanar_casella_escales(const char *mensaje, int min,  int casella){
    int numero;
    do{
        printf("\n%s  (%d-%d): ", mensaje, min, casella);
        scanf("%d", &numero);

    }while(numero < min || numero > casella);
    
    return numero;
}
