#include <stdio.h>

int demanarnumero();
void imprime(int numero1, int num1, int numero2,  int num2);
void intercanvi(int *num1, int *num2);


/*. (IntercanviVariables) Crea un procediment que intercanviï el valor de dues
variables que passarem com a paràmetres i que prèviament haurem introduït
per teclat. S’han d’intercanviar els valors entre les variables i no mostrar les
variables al revés)
void intercanviVariables (int *num1, int *num2)
*/


int main(){

    int numero1,  numero2, num1, num2;

    numero1 = demanarnumero();
    numero2 = demanarnumero();

    num1 = numero1;
    num2 = numero2;

    intercanvi( &num1, &num2);
    imprime(numero1, num1, numero2, num2);


    getch();
    return 0;
}

int demanarnumero()
{
    int numero;

    printf("Introdueix un numero: ");
    scanf("%d", &numero);
    
    return numero;
}

void intercanvi(int *num1, int *num2)
{
    int temporal;
    temporal =  *num1;
    *num1 = *num2;
    *num2 = temporal;
}

void imprime(int numero1, int num1, int numero2,  int num2)
{
    printf("\nEl numero original %d   intercanviat es %d", numero1, num1);
    printf("\nEl numero original %d   intercanviat es %d", numero2, num2);
}
