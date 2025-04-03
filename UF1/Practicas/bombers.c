#include <stdio.h>
#include <time.h>
#include <rlutil.h>
#include <stdlib.h>
#include <time.h>
#include  <stdbool.h>
#define  max_escales 100
void mensaje_inicio();
void pedir_escaleras(int posiciones_escaleras_inicio[], int posiciones_escaleras_final[]);
void pedir_extintores(int posiciones_escaleras_inicio[], int posiciones_escaleras_final[], int posiciones_extintores[]);
void control_juego(int posiciones_escaleras_inicio[], int posiciones_escaleras_final[], int posiciones_extintores[]);

/*La  estacion  de  bomberos  esta en la casilla 0  y la casa donde tenemos que  ir esta en  la casilla 100.  Saltamos las casillas con   un dado  del 1-6. Llegamos  a la casa cuando la casilla  es igual o  superior a 100.  

Durante  el trayecto  podemos encontrar dos tipos de dispositivos:

1. Escaleras de  bajada haciendo que recorrar n casillas hacia atras .
Al  inicio  pedir cuantas escaleras  quiere poner  y  tambien pedir el punto donde  queremos que inicien  las  escaleras  
y donde  terminen podemos  tener entre 2-20 escaleras. 
Para cada  escalera tendremos  que  pedirle  la casilla  de  inicio y la casilla final como  minimo tienen  que haber  5 casillas de separacion.  
Controlar que cuando termine  una  escalera  no haya otra en  esa  misma posicion.
En una misma casilla si que p ueden  haber varias  escaleras si  el  inicio es  diferente.
En una casilla de  inicio no pueden   haber  dos  escaleras.
No se  pueden tener  dos escaleras  que comiencen  y terminen en  las mismas posiciones.  
2. Pedir  al usuario cuantos extintores  quiere 2-10. Pedir en que casillas quiere colocarlos, no se  puede en  la casilla 0-100.
En una casilla solo puede haber  un  extintor, no puede se pueden poner donde haya una  escalera. 
Mostrar las entradas de  cada escalera,  de los extintores y del  recorrido de los  bomberos. */
int main(){

    int posiciones_escaleras_inicio[20] = {};
    int posiciones_escaleras_final[20] = {};
    int posiciones_extintores[10] = {};

    srand(time(NULL));
    mensaje_inicio();
    pedir_escaleras(posiciones_escaleras_inicio, posiciones_escaleras_final);
    pedir_extintores(posiciones_escaleras_inicio, posiciones_escaleras_final, posiciones_extintores);
    control_juego(posiciones_escaleras_inicio, posiciones_escaleras_final, posiciones_extintores);


    getch();
    return 0;
}

void control_juego(int posiciones_escaleras_inicio[], int posiciones_escaleras_final[], int posiciones_extintores[]){

    int nueva_posicion = 0;
    int posicion = 0;
    int numero_dado, salto = 1;
    int contador_extintores = 0;
    char salt[] = "salt", pos[] = "pos", dau[] = "dau", nova_pos[] = "nova_pos";
    printf("%5s%5s%5s%10s",salt, pos, dau, nova_pos);

    while(nueva_posicion < 100){

        numero_dado = rand() % 5 + 1;
        nueva_posicion  = numero_dado + posicion;

        printf("\n%5d%5d + %d = %5d", salto, posicion, numero_dado,nueva_posicion);
        posicion = nueva_posicion;
        for(int i = 0; i < 20; i++){
            
            if(nueva_posicion == posiciones_escaleras_inicio[i]){
                printf("  hi ha una escala i es pasa a ---> %d", posiciones_escaleras_final[i]);
                posicion = posiciones_escaleras_final[i];
                break;
            }

            if( i < 10 && nueva_posicion == posiciones_extintores[i]){
                printf("  Has conseguit un extintor");
                contador_extintores++;
                break;
            }
        }
        salto++;
    }

    printf("\nFelicitats el bombers han  arribat al foc amb %d extintors", contador_extintores);

}

void pedir_extintores(int posiciones_escaleras_inicio[], int posiciones_escaleras_final[], int posiciones_extintores[]){
    int numero_extintores  = 0;
    int i = 0;
    int posicio_extintor = 0;

    do{
        printf("\n\nQuants extintors vols (2-10): ");
        scanf("%d", &numero_extintores);
    
    }while(numero_extintores > 10 || numero_extintores < 2);


    while(i < numero_extintores){
        bool no_puede_ocupar_la_posicion = false;
        printf("\n\n------Generant extintors  %d------", i + 1);

       do{
            printf("\nIntrodueix la posicio del extintor (1..99): ");
            scanf("%d", &posicio_extintor);
        }while(posicio_extintor < 1 || posicio_extintor > 99);

        for(int j = 0; j < 20; j++){

            if(posicio_extintor == posiciones_escaleras_inicio[j] || posicio_extintor == posiciones_extintores[j]){
                no_puede_ocupar_la_posicion = true;
                break;
            }
            
            if(posicio_extintor == posiciones_escaleras_final[j] || posicio_extintor == posiciones_extintores[j]){
                no_puede_ocupar_la_posicion = true;
                break;
            }
        }

        if(no_puede_ocupar_la_posicion == true){

            while (no_puede_ocupar_la_posicion == true){
            
                do{
                    printf("\nPosicio ocupada");
                    printf("\nIntrodueix la posicio del extintor (1..99): ");
                    scanf("%d", &posicio_extintor);
                }while(posicio_extintor < 1 || posicio_extintor > 99);

                no_puede_ocupar_la_posicion = false;
                for(int j = 0; j < 20; j++){

                    if(posicio_extintor == posiciones_escaleras_inicio[j] || posicio_extintor == posiciones_extintores[j]){
                        no_puede_ocupar_la_posicion = true;
                        break;
                    }
                    
                    if(posicio_extintor == posiciones_escaleras_final[j] || posicio_extintor == posiciones_extintores[j]){
                        no_puede_ocupar_la_posicion = true;
                        break;
                    }
                }
            }  
        }

        posiciones_extintores[i] = posicio_extintor;
        i++;
    }
}




void pedir_escaleras(int posiciones_escaleras_inicio[], int posiciones_escaleras_final[]){

    int numero_de_escaleras;
    int i = 0;
    int numero_superior, numero_inferior;

    do{
        printf("\nIntrodueix el  numero de escales que vols (2-20): ");
        scanf("%d", &numero_de_escaleras);
    }while(numero_de_escaleras > 20 || numero_de_escaleras < 2);

    while(i < numero_de_escaleras){
        bool no_se_puede_poner_escalera = false;
        bool no_se_puede_poner_escalera_2control = false;
        printf("\n\n--------Generant escala %d--------", i + 1);
        do{
            printf("\nIntrodueix la casella superior de la escala (%d..100): ", numero_de_escaleras);
            scanf("%d", &numero_superior);
        }while(numero_superior <= numero_de_escaleras || numero_superior > 100);
        
        do{
            printf("\nIntrodueix la casella inferior de la escala (0..%d): ", numero_superior  - 5);
            scanf("%d", &numero_inferior);
    
        }while(numero_inferior < 0 && numero_inferior > numero_superior - 5);

        
        for(int j = 0; j < i; j++){

            if(numero_superior == posiciones_escaleras_inicio[j]){
                no_se_puede_poner_escalera = true;
                break;
                if(numero_inferior == posiciones_escaleras_final[j]){
                    no_se_puede_poner_escalera_2control = true;
                    break;
                }

            }
        }

        if(no_se_puede_poner_escalera == true){
            
            while(no_se_puede_poner_escalera == true){
                
                if(no_se_puede_poner_escalera == true && no_se_puede_poner_escalera_2control == true){
                    
                    printf("\nCal  inserir la  escala perque tenim una escala exactament  igual");

                }else if(no_se_puede_poner_escalera == true){
                    printf("\nCal  inserir la  escala perque  has posat el incici de una escala amb  el  inci de altra");
                }

                do{
                    printf("\nIntrodueix la casella superior de la escala (%d..100): ", numero_de_escaleras);
                    scanf("%d", &numero_superior);
                }while(numero_superior <= numero_de_escaleras || numero_superior > 100);
                
                do{
                    printf("\nIntrodueix la casella inferior de la escala (0..%d): ", numero_superior  - 5);
                    scanf("%d", &numero_inferior);
            
                }while(numero_inferior < 0 && numero_inferior > numero_superior - 5);
                no_se_puede_poner_escalera = false;
                no_se_puede_poner_escalera_2control = false;

                for(int j = 0; j < i; j++){

                    if(numero_superior == posiciones_escaleras_inicio[j]){
                        no_se_puede_poner_escalera = true;
                        break;
                        if(numero_inferior == posiciones_escaleras_final[j]){
                            no_se_puede_poner_escalera_2control = true;
                            break;
                        }
                    }
                }
            }
        }
       
        posiciones_escaleras_inicio[i] = numero_superior;
        posiciones_escaleras_final[i] = numero_inferior;
        i++; 
    }
}


void mensaje_inicio(){

    printf("Benvingut al servei de bombers");
    printf("\nProces de configuracio  del sistema");
}