#include <stdio.h>


/*. (Taula del 5) Fer un algoritme que mostri per pantalla la taula del 5.*/

int main() {

    int resultat;

    for (int i = 0; i <= 10; i++) {
        
        printf("5 X %d = %d\n", i, 5 * i);
    }

    getch();
    return 0;
}