#include <stdio.h>
void imprimirtriangle(int numero, char caracter);
char demanarcaracter();
int demanarnumero();

/*(TriangleCaracter) Demana un caràcter i un número i imprimeix el següent:
Introdueix un caracter: f
Introdueix un numero : 4
ffff
fff
ff
f
*/

int main(){

    char caracter, numero;

    caracter = demanarcaracter();
    numero = demanarnumero();
    imprimirtriangle(numero, caracter);

    getch();
    return 0;
}

char  demanarcaracter()
{
    char caracter;
    printf("Introdueix un  caracter: ");
    scanf(" %c", &caracter);

    return caracter;
}

int demanarnumero()
{
    int numero;
    printf("Introdueix un numero: ");
    scanf("%d", &numero);

    return numero;
}


void imprimirtriangle(int numero, char caracter)
{
    int numero2 =  numero; 
    for(int i = 0; i < numero; i++){
        
        for(int j = 0; j < numero2; j++){
            
            printf("%c", caracter);   
        }
        numero2 -= 1;

        printf("\n");
    }
}