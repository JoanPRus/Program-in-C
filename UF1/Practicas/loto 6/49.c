#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
void demanar_combinacio(int  combinacio[]);
void generar_reintegrament(int reintegrament[]);
void combinacio_guanyadora_i_reintegrament(int combinacio_guanyadora[], int reintegrament_guanyador[]);
void demanar_import_diners(int *diners);
void resum_partidas(int import_de_cada_partida_guanyada[], int numero_voltes);
void  comprobacio_boleti(int combinacio_guanyadora[], int reintegrament_guanyador[], int combinacio[], int reintegrament[], int *import);
void control_de_partides(int *diners, int combinacio_guanyadora[], int reintegrament_guanyador[], int combinacio[], int reintegrament[], int import_de_cada_partida_guanyada[20], int *import);

/*Volem fer un algoritme per poder jugar al programa de la 6/49. Aquest programa es basa en que
es demana a l’usuari 6 nombres a l’atzar (sense repeticions) entre 1 i 49. Posteriorment i de
forma automàtica, se li assigna un valor de Reintegrament que ha d’anar entre 0 a 9.
Posteriorment es simula la loteria, fent que l’ordinador generi la combinació guanyadora (1 a
49) i el Reintegrament (0 a 9).
Finalment caldrà cercar quants números ha encertat l’usuari i si ha encartat el Reintegrament.
Caldrà utilitzar vectors per a gestionar el joc de l’usuari i un vector per a la combinació
guanyadora (ordinador).
A més a més, el programa inicialment ens ha de demanar quin és el nostre import inicial, o sigui
els diners que teniu per a poder jugar. Aquests valors només podran ser 5€, 10€ o bé 20€.
El programa ens demanarà la combinació inicial amb la que voleu jugar, que serà la mateixa per
a totes les partides. Cal mostrar aquesta butlleta combinació per pantalla. Tenint en compte que
cada partida val 1 Euro, el programa un cop finalitzi una partida, ens ha de demanar si voleu
tornar a jugar o no. Com a mínim es farà una partida i com a màxim 20 partides. Teniu en compte
que només es pot jugar si disposeu de diners.
Quan hagueu acabat de jugar el programa ens ha de mostrar per a cada una de les partides quin
és l’import guanyat o bé zero si no s’ha guanyat res.
Cal tenir en compte que els premis obtinguts seran segons la següent taula:
PREMIS:
0 encerts: Sense premi
1 encert: 2
2 encerts: 6
3 encerts: 16
4 encerts: 80
5 encerts: 100
5 encerts + complementari: 500
6 encerts: 5000
6 encerts + complementari: 10000*/

int main(){
    int combinacio[6] = {};
    int reintegrament[1] = {};
    int combinacio_guanyadora[6] = {};
    int reintegrament_guanyador[1] = {};
    int diners;
    int import = 0;
    int import_de_cada_partida_guanyada[20];
    demanar_combinacio(combinacio);
    generar_reintegrament(reintegrament);
    demanar_import_diners(&diners);
    control_de_partides(&diners, combinacio_guanyadora, reintegrament_guanyador, combinacio, reintegrament, import_de_cada_partida_guanyada, &import);
    getch();
    return 0;
}   

/*Resum y pasos:
Demanar  al usuari 6 nombres (no repetir) entre  el 1-49.
Automaticament asignem  un nombre de reintegrament 0-9.
Generar combinacio guanyadora amb els 6 nombres + el reintegrament. 
Inicialmente demanar el import inicial per jugar (5,10,20 euros).
Cada  partida  costa 1 euro. Despres de una partida demanar  si volem jugar, si tenim diners podem jugar. 
Despres de jugar mostrem el  import guanyat per cada partida.
PREMIS:
0 encerts: Sense premi
1 encert: 2
2 encerts: 6
3 encerts: 16
4 encerts: 80
5 encerts: 100
5 encerts + complementari: 500
6 encerts: 5000
6 encerts + complementari: 10000
*/

void control_de_partides(int *diners, int combinacio_guanyadora[], int reintegrament_guanyador[], int combinacio[], int reintegrament[], int import_de_cada_partida_guanyada[20], int *import){
    bool altra_partida = true;
    int numero_voltes = 6;
    int i = 0;
    while(*diners >= 1 && altra_partida == true){
        *diners -= 1;
        int numero;
        import_de_cada_partida_guanyada[i];
        combinacio_guanyadora_i_reintegrament(combinacio_guanyadora, reintegrament_guanyador);
        comprobacio_boleti(combinacio_guanyadora, reintegrament_guanyador, combinacio, reintegrament, import);


        import_de_cada_partida_guanyada[i] = *import;
        i++;
        numero_voltes = i;
        printf("\nVols fer altra partida? (Si = 1 No = 0)  ");
        scanf("%d", &numero);
        if(numero == 1){
            altra_partida = true;
        }else altra_partida = false;
    }

    resum_partidas(import_de_cada_partida_guanyada, numero_voltes);
}

void resum_partidas(int import_de_cada_partida_guanyada[], int numero_voltes){

    for(int i = 0; i < numero_voltes; i++){
        printf("\nPartida %d: %d import partida", i + 1, import_de_cada_partida_guanyada[i]);
    }
}


void comprobacio_boleti(int combinacio_guanyadora[], int reintegrament_guanyador[], int combinacio[], int reintegrament[], int *import){
    int numero_complementari = 0;
    int numero_encertats = 0;
    if(reintegrament_guanyador[0] == reintegrament[0]){
        numero_complementari = 1;
    }

    for(int i = 0; i < 6; i++){

        for(int j = 0; j < 6; j++){

            if(combinacio[j] == combinacio_guanyadora[i]){
                numero_encertats += 1;
            }
        }
    }

    if(numero_encertats == 6){
        *import = 5000;
        if(numero_complementari == 1){
            *import = 10000; 
        }
    }else if(numero_encertats == 5){
        *import = 100;
        if(numero_complementari == 1){
            *import = 5000; 
        }
    }else if(numero_encertats ==  4){
        *import = 80;
    }else if(numero_encertats == 3){
        *import = 16;
    }else if(numero_encertats ==  2){
        *import = 6;
    }else if(numero_encertats == 1){
        *import = 2;
    }else *import = 0;

}

void demanar_import_diners(int *diners){

    do{
        printf("\nIntrodueix el import inicial per jugar (5-10-20 euros): ");
        scanf("%d", diners);
    }while(*diners != 5 && *diners != 10 && *diners != 20);
}

void combinacio_guanyadora_i_reintegrament(int combinacio_guanyadora[], int reintegrament_guanyador[]){
    
    int numero, numero_reintegrament;
    for(int i = 0; i < 6; i++){
        bool es_repeteix = false;

        numero = 1 + rand() % 49;

        for(int j = 0;  j <= i; j++){

            if(combinacio_guanyadora[j] == numero){
                es_repeteix = true;
                break;
            }
        }

        if(es_repeteix == true){
            i--;
        }else combinacio_guanyadora[i] = numero;  
    }  
    generar_reintegrament(reintegrament_guanyador);

}

void generar_reintegrament(int reintegrament[]){
    int i = 0;
    int numero = rand() % 10;
    reintegrament[i] = numero;
}

void demanar_combinacio(int  combinacio[]){

    int numero;

    for(int i = 0; i < 6; i++){
        bool es_repeteix = false;

       do{
        printf("\nIntrodueix un numero: ");
        scanf("%d", &numero);
       }while(numero > 49 || numero < 1);

        for(int j = 0;  j <= i; j++){

            if(combinacio[j] == numero){
                es_repeteix = true;
                break;
            }
        }

        if(es_repeteix == true){
            i--;
        }else combinacio[i] = numero;  
    }  
}

