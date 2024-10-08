#include <stdio.h>
#include <string.h>


/*Cal indicar quina beca rebrà un alumne, en funció la qualificació
que ha obtingut. La qualificació ha d’estar controlada entre 1 i 10.
• Si la qualificació està entre 9,5 i 10, obté un 80% de la beca
• Si la qualificació està entre 8,5 i 9,4, obté un 40% de la
beca
• Si la qualificació està entre 8,0 i 8,4, obté un 25% de la
beca
• Si la qualificació és menor de 8.0 no s'otorga beca
L’import de la beca és de 1200 €*/

int main() {

    float nota; 
    float beca = 1200;
    float importfinal; 

    printf("Introdueix la  teva nota: ");
    scanf("%f", &nota); 

    if (nota >= 9.5 && nota <= 10)  {
        importfinal = beca * 0.80;
    } else if (8.5 <= nota && nota <= 9.4) {
        importfinal = beca *  0.40;
    } else if (8.0 <= nota && nota <= 8.4) { 
        importfinal = beca * 0.25;
    
    } else if (nota > 0 && nota <= 8.0) { 
        printf("No hi ha beca");
        getch();
        return 0;
    } else {
        printf("Dada incorrecte");
        getch();
        return 0;
    }
                
  printf("La beca es de: %.f", importfinal);

    getch();
    return 0;

}