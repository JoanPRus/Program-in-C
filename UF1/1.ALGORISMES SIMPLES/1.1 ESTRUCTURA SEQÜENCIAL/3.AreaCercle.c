#include <stdio.h>
#include <string.h>

  int main() {

    /*(AreaCercle) Demana el radi d’un cercle i calcula la seva àrea (Area=pi x
    radi2)*/
  float area, radi;
  #define Pi 3.14

  printf("Introdueix el radi del cercle: ");
  scanf("%f", &radi);
  area = Pi * radi * radi;
  printf("La seva area es: %.2f", area);

  getch();
  return 0;
  }