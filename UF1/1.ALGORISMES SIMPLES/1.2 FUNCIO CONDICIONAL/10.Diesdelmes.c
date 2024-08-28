#include <stdio.h>

/*Fer un algoritme que donat un nombre natural de l’u al dotze,
que representa el mes, indiqui si el mes corresponent té 28 (no es tindran en
compte els anys de traspàs), 30 o 31 dies.*/

// otra forma usando if-else o arrays (aun no se)
int main() {

    int num;
    printf("Introdueix un numero del 1-12 (representen els mesos del any): ");
    scanf("%d", &num);

    switch (num)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12: 
        printf("Mes = %d te 31 dies", num);
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        printf("Mes = %d te 30 dies", num);
        break;
   
    case 2:
        printf("Mes = %d te 28 dies", num);
        break;

    default:
        printf("Dades incorrectes");
        break;
    }

    getch();
    return 0;
}