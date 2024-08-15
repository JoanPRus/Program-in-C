#include <string.h>
#include <stdio.h>

int main(){

    /*(Consum) Demana la quantitat de kilòmetres recorreguts per una moto i la
    quantitat de litres de combustible que ha consumit durant aquest recorregut. A
    continuació mostra el consum de combustible per kilòmetre. La correccion
    del pdf es incorrecta*/

    float kilometres, litres, consum;

    printf("Kilometres recorreguts: ");
    scanf("%f", &kilometres);
    printf("Litres de combustible gastat: ");
    scanf("%f", &litres);

    consum = litres / kilometres;

    printf("El consum per kilometre es: %.3f", consum);











    return 0;
}