#include <stdio.h>
#include <string.h>

/*Calcul_Salari) Escriu un programa per tal de calcular les nòmines dels
treballadors d’una consultora IT els quals cobren setmanalment per total
d’hores realitzades:
● Les hores treballades pels consultors seran sempre hores senceres, però el
preu al que es paguen les mateixes podrà contenir decimals.
● El volum d’hores inferior a les 35h/setmana es paga a una tarifa prefixada
que caldrà introduïr a través de teclat, juntament amb el total d’hores
realitzades.
● El volum d’hores igual o superior a les 35h/setmana es paga com a extres
a un preu que serà 1.5 vegades el preu de l’hora normal (que s’haurà
introduït per teclat prèviament).
● Les deduccions fiscals que s’han d’aplicar als treballadors depenen del sou
brut:
o Si el sou<=120€, no es paguen impostos i per tant el sou brut = sou
net.
o Fins als 900€ s’haurà de deduïr (restar) un 20% del sou brut.
*/

/*los ejemplos estan mal en el pdf.*/


int main(){

    //Establir les variables hores y preu per hora
    int horestreballades, horesextres;
    float preuhores, sou, preuhoresextres, sou2, soutotal, soufinal;

    //Introduïr el nombre d'hores realitzades i el preu de la tarifa prefixada

    printf("Introdueix les hores treballades i la tarifa prefixada: ");
    scanf("%d %f", &horestreballades, &preuhores);

    //Si les hores son inferiors a 35h/setmana tarifa fixa
    //Hores iguals o superiors a 35h/setmana pagades per (1.5 x preu fix) per cada hora extra


    if (horestreballades < 35) {

        sou = horestreballades * preuhores;
        soutotal = sou;
        
    } else if (horestreballades >= 35) {

    horesextres = horestreballades - 34;
    preuhoresextres = horesextres * (preuhores * 1.5);
            
    sou = (horestreballades - horesextres) * preuhores; 
    sou2 = preuhoresextres;
    soutotal = (sou + sou2);

    }

        //Deduccions fiscals depen del sou brut. Si el sou<=120 no paguen impostos. Fins 900 es resta el 20%

    if (soutotal <= 120) {
      printf("EL sou es %.2f", soutotal); 
        
            
     }else if (soutotal >=121 && 900 >= soutotal) {

        soufinal = (soutotal * 0.80);
        printf("El sou es %.2f", soufinal);

    }else printf("EL sou es %.2f", soutotal); 
       
    getch();
    return 0;
}