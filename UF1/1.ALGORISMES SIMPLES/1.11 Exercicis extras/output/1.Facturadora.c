#include <stdio.h>


/*(Facturador): Escriu un programa que permeti emetre la factura
corresponent a la compra d’un article determinat del que se n’hagin adquirit 1
o múltiples unitats. Cal aplicar un IVA del 21% i si el preu brut de la venda
(preu+IVA) supera els 500€, caldrà realitzar un descompte del 15%. Així
doncs el programa haurà de demanar quin és el preu de l’article, quantes són
les unitats venudes i a continuació presentar l’import final de la venda (si s’ha
aplicat un descompte, caldrà que el programa ho faci saber, així com la
quantitat estalviada en euros).
    Exemple:
    Quin es l’import del producte? 200.50
    Quantes unitats vols del producte? 10
    Base: 2005
    IVA: 421,05
    Base Imposable: 2426,05
    Descompte: 363,90
    Import a pagar: 2062,14
*/

int main(){

    /*Pedir el precio del producto  y el  numero de unidades. El precio sin IVA, el IVA, el total, descuento del 15% si supera los 500
    euros, la cantidad del descuento  y el importe  final*/
    float preu_producte,  base, iva, base_imposable, descompte  = 0,  import_a_pagar;
    int quantitat;

    printf("\nImport del producte? ");
    scanf("%f", &preu_producte);
    printf("\nQuantitat? ");
    scanf("%d", &quantitat);

    base = preu_producte  *  quantitat;

    iva =  base * 0.21;

    base_imposable = base +  iva;

    printf("\nBase %.2f", base);
    printf("\nIVA %.2f", iva);
    printf("\nBase imposable %.2f", base_imposable);

    if(base > 500){
        descompte = base_imposable * 0.15;
        import_a_pagar = base_imposable - descompte;
        printf("\nDescompte %.2f",  descompte);
        printf("\nImport a pagar %.2f", import_a_pagar);
    }

    

   
    
   
    
    getch();
    return 0;
}