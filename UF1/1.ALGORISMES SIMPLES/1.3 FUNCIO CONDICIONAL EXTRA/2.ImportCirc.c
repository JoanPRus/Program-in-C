#include <stdio.h>
#include <string.h>


/*) Volem calcular el preu de les entrades d'un circ, aplicant la
següent regla:
• Si és home paga l'entrada sencera: 60 €
• Si és dona paga l'entrada sencera amb un descompte del 15%
• 3.- En cas que sigui menor té un descompte del 20%
Cal aplicar sempre l'opció més adequada per al client.
El sexe pot ser Home o Dona (‘H’ o ‘D’); i l’edat cal que sigui positiva.
Considerem els 18 anys com a edat per considerar si una persona és major o
menor. Els de 18 anys es consideren majors d’edat
*/

int main() {

    float H = 60;
    float D = (60 * 0.85);
    int edat;
    char sexe;
    float preuentrada;   

    printf("Introdueix el teu sexe: H o D ? ");
    scanf("%c", &sexe); 
    printf("Introdueix la teva edat: ");
    scanf("%d", &edat); 

    if (sexe == 'H') {
        if ( edat < 18) {
            preuentrada = H * 0.8;
        } else preuentrada = H; 

    } else if (sexe == 'D'){
         if ( edat < 18) {
            preuentrada = D * 0.8;
        } else preuentrada = D; 
    } else printf("Dada incorrecte");

    printf("El preu de la  entrada es %.2f euros", preuentrada); 

    getch();
    return 0;
}