#include <string.h>
#include <stdio.h>


/*(Públic cinema2) Un altre cinema ens ha demanat un altre programa.
Aquest cinema vol calcular quin serà l’import total d’un grup de persones. Per
a desenvolupar el programa es demanarà quantes persones volen entrar al
cinema de menys de 10 anys i quantes persones majors o iguals a 10 anys.
Seguidament cal tenir present que el preu per als adults és de 10.50, i de cada
menor és de 8.50. El preu es manté igual per a tots els dies de la setmana;
però dimarts és el dia de l’espectador i el seu preu final és redueix en un
30%.
Dossier Exercicis Programació (M3 UF1) 15/70
Ull per què s’aplica un 20% de descompte addicional sobre el preu final; en
cas del pack familiar. El pack familiar té com a mínim 2 adults i 2 menors.*/

int main() {

    /*Notas para hacer el codigo:  Calcular el importe total de un grupo. Menores de  10 años pagan 8.50 y mayores de 10 o igual  pagan  10.50
    Los martes hay descuento del 30%. Pack familiar 2 adultos o mas y dos menores o mas se aplica un 20% de descuento adicional.*/

    int menoredad, mayoredad; 
    float preciomenor = 8.50;
    float preciomayor = 10.50;
    float martes = 0.70; 
    float pack_familiar = 0.80;
    char dia[15];
    float sumapreusmenor, sumapreusmayor, preutotal, preudescompte, preupack; 
    printf("Quantes persones son menors de 10 anys? ");
    scanf("%d", &menoredad);
    printf("Quantes persones son mayors o iguals a 10 anys? ");
    scanf("%d", &mayoredad);
    printf("Quin  dia es? ");
    scanf("%14s", dia);

    sumapreusmenor = preciomenor  * menoredad; 
    sumapreusmayor = preciomayor * mayoredad;
    preutotal = sumapreusmayor + sumapreusmenor;  

    if (strcasecmp (dia, "dimarts") == 0) {
        preudescompte = preutotal * martes;
        if  (menoredad >= 2 && mayoredad >= 2) {
        preudescompte*= pack_familiar; 
        printf("El preu es %f euros", preudescompte);
    } else printf("El preu es %f euros", preudescompte);
    } else if (menoredad >= 2 && mayoredad >= 2) {
        preupack = preutotal * pack_familiar;
        printf("El preu es %f euros", preupack);  
    } else printf("El preu es %f euros", preutotal); 

    getch();
    return 0;
}
