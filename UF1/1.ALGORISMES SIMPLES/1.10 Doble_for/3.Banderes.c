#include <stdio.h>
#include <rlutil.h>





/*(Banderes) Anem a fer banderes: Es realitzaran les dues banderes; una a sota de l’altra. L’amplada de les
banderes és de 60 mentre que l’alçada és de 12*/


/*Haciendo una  bandera puedo copiar el codigo y hacer la siguiente, cambiando 4 cosas
tengo que tener en cuenta que son 12 de alto entre 3 colores asi que 4 filas por color*/

int main(){

    /*Tengo  que imprimir 60 espacios (rojo), bajar una linea (asi 4 veces),  despues el mismo proceso con blanco  y luego  verde.
    Tengo que  hacer un bucle  para el largo y otro dentro para  el ancho. El primero nos marcara cuando cambia de color (largo),
    el  segundo el color (ancho)*/
    
    int terminalHeight = 50;  // Ajustar según tu terminal
    int terminalWidth = 119;  // Ajustar según tu terminal


    setBackgroundColor(BROWN);
    for (int i = 0; i < terminalHeight; i++) {
        for (int j = 0; j < terminalWidth; j++) {
            printf(" ");
        }
        printf("\n");
    }

    // Restaurar el cursor a la parte superior izquierda
    locate(1, 1); //Parte del codigo  anterior IA,  problema con el fondo de  la terminal, pintamos todo y movemos el  cursor al  inicio. 

    setBackgroundColor(BLACK);
    printf("HONGRIA\n");

    for (int i = 1;  i <= 12; i++){

        setBackgroundColor(RED);

        if (i > 8){
            setBackgroundColor(GREEN);
        } else if (i > 4){
            setBackgroundColor(WHITE);
        }
        
        
        for (int j = 1; j  <= 60;  j++){
            
            printf(" ");
        }

        

    }
    
    
    setBackgroundColor(BLACK);
    printf("\nIRLANDA\n");
    

    /*Las bandas ahora  son verticales, el ancho 60 se divide entre 3, frangas  de 20. Escribir 20 espacios 12  veces,
    luego cambiar  al siguiente  color y asi. Cada vez que haga 20 metemos  salto de linea. 12 x 3 = 36 veces*/

    /*Mas facil, cambiar el  color de los espacios con  condiciones, escribir, escribir 12 veces el ancho 
    y poner  tramos de  color*/


    for (int i = 1; i <= 12; i++){

        for (int j = 1; j <= 60; j++){
            
            
            if (j <= 20){
                setBackgroundColor(GREEN);
                
            }else if (j > 40){
                setBackgroundColor(BLACK); 
            } else if (j > 20){
                setBackgroundColor(WHITE);
                
            }

            printf(" ");

        }
        printf("\n");

    }


    getch();
    return 0;
}
