#include <stdio.h>
#include <string.h>


/*(DiesMes) Fer un algoritme que donat un nombre natural de l’u al dotze, que
representa el mes, indiqui si el mes corresponent té 28 (no es té en compte si
és any de traspàs), 30 o 31 dies. */


int main() {

    int mes;

    printf("Introdueix un numero que representa el mes: ");
    scanf("%d", &mes);

    switch (mes)
    {
    case 2:

        printf("El mes te 28 dies");
        
        break;
    case 4: case 6: case 9: case 11:

        printf("El mes te 30 dies");
        
        break;
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:

        printf("El mes te 31 dies");
        
        break;
    
    default:
        printf("Numero no valid");
        break;
    }

    getch();
    return 0;
}