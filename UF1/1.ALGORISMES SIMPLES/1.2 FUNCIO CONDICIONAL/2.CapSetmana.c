#include <stdio.h>

//Demanar un numero del 1-7 (dies de la setmana) mostrar per pantalla si es laboral o no
// Si els dies son el 6 o 7 ens mostra per pantalla que es cap de setmana

int main()
{
    int num;

    printf("Introdueix un numero del 1 al 7: ");
    scanf("%d", &num);
    if (num>0 && num<6) printf("es laboral\n");
    
    else 
          
        if (num>=8) printf("numero incorrecte\n");
        if (num<=0) printf("numero incorrecte\n");

        if (num>=6 && num<=7) printf("es cap de setmana\n"); 

        getch();
        return 0;
}


