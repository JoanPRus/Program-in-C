#include <stdio.h>
#include <string.h>

//(Promig) Demana a l’usuari 3 números i mostra el promig dels tres números

    int main(){

    float a,b,c,promig;

    printf("Introdueix un primer numero: ");
    scanf("%f", &a);
    printf("Introdueix un segon numero: ");
    scanf("%f", &b);
    printf("Introdueix un tercer numero: ");
    scanf("%f", &c);

    promig = (a + b + c) / 3.0;
    printf("El promig es: %.2f", promig);
  
    getch();
    return 0;
}