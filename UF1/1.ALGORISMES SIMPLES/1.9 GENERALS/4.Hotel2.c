#include <stdio.h>

/*(Hotel2) Crea un algoritme que calculi el preu a pagar en un hotel; cal tenir
en compte que durant els dies laborals el preu de l’habitació és de 80 €
mentre que el cap de setmana és de 100. El client només estarà en l’hotel
durant un perióde de N dies, que haurà també d’introduir com a paràmetre.
Introdueix el dia d'entrada: 6
Introdueix total dies estada: 3
Import total 280.00 Euros
Prem una tecla per finalitzar*/

int main(){
  //Pedir el dia  de entrada y  los  dias que  estara. laboral = 80, festivo = 100, calcular  importe  final. 
  
  /*Los dias estan representados en numeros 1-7. Puede quedarse los dias que quiera, asi que los  precios cambian.
    con el dia  de entrada y  los dias que se va ha  quedar podemos hacer contador y que  cuando  llegue a 7 vuelva 
    a  valer 1 y que cuando el contador sea 6 o 7 sumen el precio de festivo  y 1-5 laboral
  */

  int dia_entrada, dies_estada, resultat = 0, contador = 0, laboral = 80, festivo = 100; 

  printf("\nIntrodueix el dia de entrada: ");
  scanf("%d", &dia_entrada);
  printf("\nIntrdueix total dies estada: ");
  scanf("%d", &dies_estada);
  contador = dia_entrada; // contador obtiene el  valor  del  dia  que entramos

  //tengo que hacer un bucle para recorrer cada dia y sumar su precio. 

  for (int i = 1; i <= dies_estada; i++){ // hacemos un bucle para que se repita por  cada  dia

    if (contador == 6 || contador == 7){ //condicion  para el  festivo
      resultat += festivo; 
    }
    

    if (contador != 6 && contador != 7){ //condicion para  el laboral
      resultat += laboral; 
    }
    

    if (contador == 7){  //si el contador es 7 vale 0
      contador = 0;
    }

    contador++;   //aumentamos  el contador a 1 

  }{
    printf("\nPreu total %d", resultat);
    printf("\nPrem una tecla per finalitzar");
  }

  getch();
  return 0;
}