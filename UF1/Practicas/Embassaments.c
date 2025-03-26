#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <rlutil.h>
#include <time.h>
#define MAX_hores 24
#define MAX_embassament 1500
#define MAX_riu 400
void presentacio();
float demanar_cabal_embassament();
float demanar_cabal_riu(int num_del_riu);
void formacio_columnes();
void control_programa(float valors_embassament[], float percentatge[], float *cabal_inicial_embassament, float cabal_inicial_riu1, float cabal_inicial_riu2, float  *percent, float *total_riu, bool *comporta1, bool *comporta2, bool *sortida_evacuacio);
void control_comportes(bool *comporta1, bool *comporta2, float *percent);
void color_del_print(float *percent);
void modificacio_embassament(float *cabal_inicial_embassament, float *total_riu, bool *comporta1, bool *comporta2);
float increment_cabal_riu(float cabal_inicial_riu);
void evacuacio_sistema(float *percent, bool *sortida_evacuacio);
void resum_resultats(float valors_embassament[], float percentatge[], int i);

/*Pasos:
1.Demanar  el cabal inicial de l'embassament  (max = 1500 m^3)
2.Demanar el cabal inicial de  cadascun dels dos  rius (max 400).
3.Variacio del cabal del riu aplicant la  formula o si el cabal es = 0 aplicant  un  increment entre  0-2 aleatoriament.
Formula -->Cabalhora=cabalhora anterior+/-rand()%11* cabalhora anterior/100.  
4.Funcionament de  les  comportes: es tanquen  les dues  si el embassament es menor al 15% de la seva capacitat.
Obrim la  primera comporta si l'embassament creix i el  seu nivell  esta entre 15-80%. En la primera lectura nomes 
tenim en compte que que el nivell ha de estar entre el 15-80%. Obrim les dues comportes si supera  el 80%. 
Quan  una  comporta  està oberta evacua  el  10% del caudal de  l'embassament, s'actualitza l'estat  de les comportes quan ha finalitzat  l'hora.
Aquesta pèrdua es reflecteix en la següent hora.
5.A cada  hora tenim que  monitoritzar   el  valor y  percentatja de l'embassament, el cabal de  cada riu,  el total y el  estat de  cada comporta. 
6.Format de colors: 
Linea de resum de  color verd si el  nivell es inferior o igual al 60%.
color blau si es superior a 60% o igual a 90%.
color vermell si  es superior del  90%
7.Quan el percentatge de l’embassament supera el 95%, automàticament el
programa ha de finalitzar, emetre un beep i mostrar un missatge d’EVACUACIÓ
en color vermell. En el cas, però, que es superi el 100% de la capacitat de
l’embassament, el sistema ha d’emetre 5 beeps seguits separats per 1s i
mostrar, també en color vermell, un missatge d’EVACUACIÓ ZONA. En aquests
casos el sistema s’haurà d’aturar.
8.Al final del programa ens mostrarà un resum amb la següent informació: valor
màxim i mínim de l’embassament, valor mitjà de cabal i percentatge mitjà
d’ocupació.*/

int main(){
    float cabal_inicial_embassament, cabal_inicial_riu1, cabal_inicial_riu2;
    float percent;
    float total_riu;
    bool comporta1  = false, comporta2 = false;
    bool sortida_evacuacio = false;
    float valors_embassament[MAX_hores] = {};
    float percentatge[MAX_hores] = {};
    

    presentacio();
    cabal_inicial_embassament = demanar_cabal_embassament();
    cabal_inicial_riu1 = demanar_cabal_riu(1);
    cabal_inicial_riu2 = demanar_cabal_riu(2);
    control_programa(valors_embassament, percentatge, &cabal_inicial_embassament, cabal_inicial_riu1, cabal_inicial_riu2, &percent, &total_riu, &comporta1, &comporta2, &sortida_evacuacio);

    getch();
    return 0;
}

/*Notas: Tengo que gestionar  todos los datos dentro de  un  mismo for  en el cual principalmente  maneja las horas, dentro de ese for
tengoq que gestionar todo lo que  me esta pidiendo, asi que primero creare esa funcion que  controle todo y ire añadiendo funciones
con las cosas que me va pidiendo*/

void control_programa(float valors_embassament[],  float percentatge[], float *cabal_inicial_embassament, float cabal_inicial_riu1, float cabal_inicial_riu2, float  *percent, float *total_riu, bool *comporta1, bool *comporta2, bool *sortida_evacuacio){

    int numero_voltes = 0;
    formacio_columnes();


    for(int i = 0; i < MAX_hores; i++){
        *total_riu = cabal_inicial_riu1 + cabal_inicial_riu2;
        *percent = (100 * *cabal_inicial_embassament) / MAX_embassament;
        control_comportes(comporta1, comporta2, percent);
        color_del_print(percent);
        valors_embassament[i] = *cabal_inicial_embassament;
        percentatge[i] = *percent;
        printf("\n%-10d %-10.2f %-10.2f %-10.2f %-10.2f %-10.2f %-10d  %-10d", i, *cabal_inicial_embassament, *percent, cabal_inicial_riu1, cabal_inicial_riu2, *total_riu, *comporta1, *comporta2);
        modificacio_embassament(cabal_inicial_embassament, total_riu, comporta1, comporta2);
        //cabal riu modificiar.
        cabal_inicial_riu1 = increment_cabal_riu(cabal_inicial_riu1);
        cabal_inicial_riu2 = increment_cabal_riu(cabal_inicial_riu2);
        evacuacio_sistema(percent, sortida_evacuacio);
        numero_voltes = i + 1;
        if(*sortida_evacuacio == true){
            break;
        }
       
    }
    
    resum_resultats(valors_embassament, percentatge, numero_voltes);

}

void resum_resultats(float valors_embassament[], float percentatge[], int i){
    float valor_maxim = 0, valor_minim = 3000, mitjana_embassament = 0, percentatge_mitja = 0;
    float mitjana = 0, percentatge_final = 0;
    for(int j = 0; j < i; j++){
        mitjana_embassament += valors_embassament[j];
        percentatge_mitja += percentatge[j];

        if(valor_maxim < valors_embassament[j]){
            valor_maxim = valors_embassament[j];
        }

        if(valor_minim > valors_embassament[j]){
            valor_minim = valors_embassament[j];
        }

    }

    mitjana = mitjana_embassament / i;
    percentatge_final = percentatge_mitja / i;
    setColor(WHITE);
    printf("\n\nResum");
    printf("\nEl cabal maxim a sigut %.2f", valor_maxim);
    printf("\nEl cabal minim a sigut %.2f", valor_minim);
    printf("\nEl cabal mitja a sigut %.2f", mitjana);
    printf("\nEl percentatge mitja a sigut %.2f", percentatge_final);
}


void evacuacio_sistema(float *percent, bool *sortida_evacuacio){

    if(*percent > 100){
        printf("%c", 7);
        Sleep(1000);
        printf("%c", 7);
        Sleep(1000);
        printf("%c", 7);
        Sleep(1000);
        printf("%c", 7);
        Sleep(1000);
        printf("%c", 7);
        Sleep(1000);
        printf("%c", 7);
        Sleep(1000);
        printf("\n\nEVACUACIO ZONA");
        *sortida_evacuacio = true;
    }else if(*percent > 95){
        printf("%c", 7);
        printf("\n\nEVACUACIO");
        *sortida_evacuacio = true;
    }
}

float increment_cabal_riu(float cabal_inicial_riu){
    int numero_increment;

    int positiu_negatiu = rand() % 2;

    if(cabal_inicial_riu == 0){
        numero_increment = rand() % 3;
    }


    if(positiu_negatiu == 0){

        numero_increment = cabal_inicial_riu - rand() % 11 *cabal_inicial_riu / 100;

    }else{
        numero_increment = cabal_inicial_riu + rand() % 11 *cabal_inicial_riu / 100;

    }

    return numero_increment;
}

void modificacio_embassament(float *cabal_inicial_embassament, float *total_riu, bool *comporta1, bool *comporta2){
    
    if(*comporta1 == true && *comporta2 == true){
        *cabal_inicial_embassament =  *cabal_inicial_embassament * 0.80 + *total_riu;
    }else if(*comporta1 == true && *comporta2 == false){
        *cabal_inicial_embassament =  *cabal_inicial_embassament * 0.90 + *total_riu;
    }else{
        *cabal_inicial_embassament =  *cabal_inicial_embassament + *total_riu;
    }
}

void color_del_print(float *percent){
    
    if(*percent <= 60){
        setColor(GREEN);
    }else if(*percent > 60 && *percent <= 90){
        setColor(BLUE);
    }else if(*percent > 90){
        setColor(RED);
    }
}

void control_comportes(bool *comporta1, bool *comporta2, float *percent){

    if(*percent >= 15 && *percent < 80){
        *comporta1 = true;
    }else if(*percent >= 80){
        *comporta1 = true;
        *comporta2 = true;
    }else if(*percent < 15){
        *comporta1 = false;
        *comporta2 = false;
    }
}



void formacio_columnes(){

    printf("\n%-10s %-10s %-10s %-10s %-10s %-10s %-10s  %-10s", "Hora", "Estat", "Percent", "Riu 1", "Riu 2", "Total", "Comporta 1", "Comporta 2");
}

void presentacio(){
    printf("Benvinguts al sistema de control de l'embassament");
}

float demanar_cabal_embassament(){
    float num;

    do{
        printf("\nIntrodueix el cabal  inicial de l'embassament: ");
        scanf("%f", &num);
    }while(num < 0 || num > MAX_embassament);

    return num;
}

float demanar_cabal_riu(int num_del_riu){
    float num;
    do{
        printf("\nIntrodueix la capacitat actual del riu %d: ", num_del_riu);
        scanf("%f", &num);
    }while(num < 0  || num > MAX_riu);
    return num;
}