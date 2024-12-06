#include <stdio.h>
#include <rlutil.h>


/*(Compta_Paraules) Donada una frase acabada en ‘.’. Calcula quantes
paraules s’han introduït. Cal tenir en compte que els caràcters que introduirem
seran tots correctes i que entre paraula i paraula hi poden haver més d’un
espai. Entre paraula i paraula només hi haurà espais. */

int main(){

    //Ultimaletra--> Espacio = palabra.
    //Ultimaletra--> Punto = Palabra. 

    /*Esto quiere  decir que si  comprobamos que antes del  espacio  habia una  letra es una  palabra.  Y que si antes del punto hay 
    una  letra tambien es una palabra.*/  

    char letras[100];
    int contador_palabras = 0;
 

    for (int i = 0; i < 100; i++){
        
        printf("\nIntrodueix un caracter: ");
        scanf("%c", &letras[i]); //cuando se pulsa  enter se guarda en el array \n   
                //cuando pongo una letra y pulso enter se guarda  la letra  en  el array y getchar elimina el salto de  linea.  

        if (letras[i] == '.'){
            break;
        }

         if (getchar() == '\n') {  //limpia el  salto de linea del buffer, hace que no  se repita dos veces el mensaje. 
            continue;
       
         }
    }

    for (int j = 0; j < 100 ; j++){ //bucle  para poder  trabajar los espacios y condiciones para   saber las palabras. 
    //Ultimaletra--> ENTER = palabra.
    //Ultimaletra--> Punto = Palabra. 

         if (j > 0){ // condicion  para  evitar evaluar  array  -1, no es posible. 

            if ((letras[j - 1] != '\n') && (letras[j] == '\n')){ // aumenta  el  contador mirando si el indice anterior es Caracter y el actual \n
                contador_palabras++;
            }

            if ((letras[j - 1] != '\n') && (letras[j] == '.')){ // aumenta el  contador si el  indice  anterior es  letra y el actual punto. 
                contador_palabras++;
            }
        }

    } {
        printf("\nEl numero de palabras es: %d", contador_palabras);
        printf("\nPrem una tecla per finalitzar.");
    } 



    getch();
    return 0;
}