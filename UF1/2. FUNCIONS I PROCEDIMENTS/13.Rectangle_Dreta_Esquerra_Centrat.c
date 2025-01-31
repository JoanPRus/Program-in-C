#include <stdio.h>
#include <stdbool.h>
void lineaHoritzontalPlena(int i);
void lineaHoritzontalBuida(int i, int numero);
void esquerra(int numero);
void dreta(int numero);
char demanarCaracter(void);
int demanarnumero(void);
void caracterescollit(char caracter,  int numero, bool *Esquerra, bool *Dreta,  bool *Centre);
void centre(int numero);
void sortidadelprograma(bool *sortida, bool *Esquerra, bool *Dreta,  bool *Centre);
/*(Rectangle_Dreta_Esquerra_Centrat) Fer un programa que demani a
l'usuari un nombre natural entre 1 i 10 i un caràcter que pot ser 'C', 'E' o 'D'.
El programa ha de dibuixar llavors un triangle depenent de la lletra
proporcionada i amb l'alçada que digui el número. Les lletres signifiquen si el
triangle ha d'estar Centrat, a l'Esquerra o a la Dreta. El programa finalitarà
quan l’usuari hagi fet les tres opcions.
Passos que cal seguir:
a) Demanar el nombre natural; tenint en compte que ha d’estar controlat
entre 1 i 10.
b) Fer una funció que ens demani a l’usuari quin triangle vol fer. Caldrà
controlar que l’usuari només pugui inserir ‘C’, ‘E’ o ‘D’.
c) Fer un procediment per a l’opció ‘E’ que ens mostrarà un triangle a
l’esquerra
d) Fer un procediment per a l’opció ‘D’ que ens mostrarà un triangle a la dreta
e) Fer un procediment per a l’opció ‘C’ que ens mostrarà un triangle centrat
Podrà sortir del programa quan hagi fet com a mínim un cop cadascun dels
triangles. En cada triangle haurà de demanar el número.
Per a fer cada una de les línies dels triangle, cal utilitzar les funcions
liniaHoritzontalPlena i liniaHoritzontalBuida, on la primera escriu tants *
com el número que se li passi i la segona escriu tants espais en blancs com el
número que se li passa.
Funcions que cal fer:
char demanarCaracter(void);
void lineaHoritzontalPlena(int  i);
void esquerra(int num);
void dreta(int num);
void lineaHoritzontalBuida(int i);
*/

/*Resumen: Pedir un numero  entre  el 1-10. Pedir un caracter: C,E,D. Dibujar triangulo, el programa finaliza cuando se hayan creado los 3.
Usar estas funciones:  
cal utilitzar les funcions
liniaHoritzontalPlena i liniaHoritzontalBuida, on la primera escriu tants *
com el número que se li passi i la segona escriu tants espais en blancs com el
número que se li passa.
Funcions que cal fer:
char demanarCaracter(void);
void lineaHoritzontalPlena(int  i);
void esquerra(int num);
void dreta(int num);
void lineaHoritzontalBuida(int i);*/

int main(){
    int numero, i;
    char caracter;
    bool Esquerra = false, Dreta = false, Centre = false, sortida = false;

    
    while(Esquerra == false || Dreta == false || Centre == false || sortida == false){ 
        numero = demanarnumero();
        caracter = demanarCaracter();
        caracterescollit(caracter, numero, &Esquerra, &Dreta, &Centre);
        sortidadelprograma( &sortida, &Esquerra, &Dreta, &Centre);
    }

    return 0;
}
//Si se han  imprimido  los 3 triangulos preguntamos si quiere salir
void sortidadelprograma(bool *sortida, bool *Esquerra, bool *Dreta,  bool *Centre)
{   
    int numerosortida = 0;
    if(*Esquerra == true && *Dreta == true && *Centre == true){
        printf("\nPots sortir pulsant el numero 1: ");
        scanf("%d", &numerosortida);

        if(numerosortida == 1){
            *sortida = true;
        }

    }else  printf("\nPer poder sortir del programa has de fer els 3 triangles.\n");
}

//Controlamos el caracter para imprimirlo y guardamos que se ha imprimido
void caracterescollit(char caracter,  int numero, bool *Esquerra, bool *Dreta,  bool *Centre){
    

    switch (caracter)
    {
    case 'E': 
        esquerra(numero);  
        *Esquerra = true; 
    
        break;
    case 'C':
        
        centre(numero);
        *Centre = true;

        break;

    case 'D':
        
        dreta(numero);
        *Dreta = true;

        break;
    }
}

//Imprime los * segun i
void lineaHoritzontalPlena(int i)
{
    for(int j = 0; j <= i; j++){
        printf("*");
    }

    printf("\n");
}

//imprime los espacios teniendo en cuenta el  numero y el valor  de i
void lineaHoritzontalBuida(int i, int numero)
{
    for(int j = numero; j >= i; j--){ 
        printf(" ");
    }
}

//Imprime el triangulo del  centro, primero los espacios y luego los * 
void centre(int numero)
{
    for(int i = 0; i < numero; i++){
        lineaHoritzontalBuida(i, numero);
        lineaHoritzontalPlena(i * 2); //es un triangulo completo
   }
}

//Imprime el triangulo desde el lado izquierdo
void esquerra(int numero) //argumento para  la posicion  del  triangulo 
{
    for(int i = 0; i < numero; i++){
        lineaHoritzontalPlena(i);
    }
}

//Imprime el triangulo desde el lado derecho 
void dreta(int numero) //argumento para  la posicion  del  triangulo 
{   
   for(int i = 0; i < numero; i++){
        lineaHoritzontalBuida(i, numero); 
        lineaHoritzontalPlena(i);
   }  
}

//pide el  caracter
char demanarCaracter(void) //void dentro indicando  que no recibe parametros.
{   
    char caracter; 

    do{
        printf("Introdueix un caracter (C, E, D): ");
        scanf(" %c", &caracter);
    }while(caracter != 'C' && caracter != 'E' &&  caracter != 'D');

    return caracter;
}

//pide  el  numero
int demanarnumero(void)
{
    int numero;

    do{
        printf("Introdueix un numero del  1-10: ");
        scanf("%d", &numero);
    }while(numero < 1 || numero > 10);

    return numero; 
}