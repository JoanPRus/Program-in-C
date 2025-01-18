#include <stdio.h>
#include <string.h>


int main(){


    /*Fes un programa que mostri quan haura que pagar un client en
    una benzinera atenent a les seg�ent condicions:
    1. La gasolina Sense Plom 95 t� un cost de 2.083 �/litre.
    2. La gasolina Sense Plom 98 t� un cost de 2.238 �/litre.
    3. El gasoil t� un cost de 2.003 �/litre.
    4. Si el client te la targeta client, tindra? un descompte del 10% sobre el
    preu per litre.
    El programa haur? de demanar tipus de combustible; quantitat de litres i si el
    client disposa de la targeta client.
    */
    // Declarar variables i constants 
    
    int opcio; 
    float litres, paga, pagadescompte;
    char tarjeta[10];

    //Demanar combustible, quantitat libtres i si te tarjeta client
    printf("Selecciona una opcio: \n");
    printf("\t1. La gasolina Sense Plom 95 te un cost de 2.083 $/litre.\n");
    printf("\t2. La gasolina Sense Plom 98 te un cost de 2.238 $/litre.\n");
    printf("\t3. El gasoil te un cost de 2.003 $/litre.\n");
    printf("Selecciona una opcio: ");
    scanf("%d", &opcio);
    printf("Quantitat de litres: ");
    scanf("%f", &litres);
    printf("Tens tarjeta client: ");
    scanf("%9s", tarjeta);

    //Condicions

    switch (opcio)
    {
    case 1:
        paga = 2.083 * litres;
        break;
    case 2:
        paga = 2.238 * litres;
        break;
    case 3:
        paga = 2.003 * litres;
        break;
    
    default: 
        printf("Opcio incorrecte"); 
        break;
    }

    if (strcasecmp (tarjeta, "si") == 0) {
        pagadescompte = paga * 0.9;
        printf("Total a pagar %.4f", pagadescompte); 

    } else if (strcasecmp (tarjeta, "no") == 0) {
        printf("Total a pagar %.4f", paga);

    }else printf("Resposta incorrecta"); 

    getch();
    return 0;
}