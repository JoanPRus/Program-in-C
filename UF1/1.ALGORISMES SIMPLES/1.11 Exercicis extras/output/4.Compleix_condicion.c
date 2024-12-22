#include<stdio.h>

/*(CompleixenCondició): Escriu un programa que sumi tots els números
sencers positius menors de 1000 que compleixin la següent condició: “La
suma de les unitats més les centenes és la meitat de les desenes”. Cal indicar
a més a més del resultat de la suma total, quins números compleixen la
condició.
Algorisme a aplicar
− Si número < 10 → Ignorar
− Si número >= 10 i número < 100 → 0=centenes; núm/10=desenes;
núm%10=unitats;
− Si número >= 100 i número < 1000 → núm/100=centenes;
(núm%100)/10=desenes; núm%10=unitats;
Exemple:
Números: 21, 42, 63, 84, 120, 141, 162, 183, 240, 261, 282, 360,
381, 480
Suma Total: 2820
*/

int main(){

    /*Sumar  todos los numeros con  dos condicones.  1. positivo  y  menor de  1000.  2. Unitats + centenes = desenes/2.  
    Indicar que numeros cumplen la condicion  y la suma total. 
    Aplicar el  algoritmo.
    Tengo que hacer  un bucle que recorra todos  los  numeros, los que  cumplan los tengo que guardar mostrarlos  y sumarlos.*/

    float  centenes = 0, desenes =  0, unitats = 0;
    int memoria[100],  num = 0, suma_total = 0;

    for(int i = 0; i < 1000;  i++){ //recorre los numeros hasta el 1000

        if(i >= 10 && i < 100){ 
            centenes = 0;
            desenes = i / 10;
            unitats  = i % 10;

        }

        if(i >= 100 && i < 1000){
            centenes = i / 100;
            desenes = (i  % 100) / 10;
            unitats =  i % 10;
        }

        if(i >= 10 && (desenes / 2) == (unitats + centenes)){ 
            memoria[num] = i;
            printf("\n %d",  memoria[num]);
            suma_total += memoria[num];
            num++;

        }    
    }

    printf("\ntotal %d", suma_total);
    
    getch();
    return 0;
}