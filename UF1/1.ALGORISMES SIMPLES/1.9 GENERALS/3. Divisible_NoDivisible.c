#include <stdio.h>

/* (Divisible_NoDivisible) Fer un algoritme que demani un nombre a l'usuari i
mostri per pantalla el missatge “DIVISIBLE" si es pot dividir entre algun
nombre del 2 al 10. Si no, ha de mostrar el missatge “NO DIVISIBLE". Fixa’t
que en el moment que sigui divisible per un número ja no cal que continuem
fent la resta de divisions.
Introdueix un numero: 21
El numero es divisible entre 3
Prem una tecla per finalitzar
Introdueix un numero: 17
El numero no es divisible entre el 2 i el 10
Prem una tecla per finalitzar*/


int main(){

    //Tengo que  pedir un numero y decir si es divisible  entre 2-10, no hace falta seguir dividiendo por mas  numeros si  es divisible. 

    //En el ejemplo solo es una entrada, no es un bucle.  

    int num = 0, Del_2_al_10[9] =  {2, 3, 4, 5, 6, 7, 8, 9, 10}, resultado = 0; //Variables  y array

    printf("Introdueix un numero: ");
    scanf("%d", &num);

    for (int i = 0; i < 9; i++){ //bucle para  recorrer los indices del  array

        resultado = (num % Del_2_al_10[i]);   // operacion para  ver si es divisible
        
        if (resultado  == 0){  // si el resto es cero  es divisible
            printf("El numero es  divisible entre %d", Del_2_al_10[i]);
            break;//rompemos el for
        }
    
    }{
        if (resultado  != 0){ //comprobamos  el  ultimo resultado  y si  no  es  cero no  es divisible. 
            printf("El numero no es divisible entre el 2 i el 10");
        }
    
        printf("\nPrem una tecla per finalitzar");
    }
                    
    getch();
    return 0;
}