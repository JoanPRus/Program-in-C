#include <stdio.h>
#include <string.h>

/*(CreixentDecreixent): Donats tres nombre a,b i c, determina si la seqüència
és creixent, decreixent o cap d’elles. Es determina que una seqüència és
creixent si el valor actual és igual o superior al valor anterior. Una seqüència
on els tres nombres tenen el mateix valor, la considerarem seqüència creixent
*/

int main() {

    int a,b,c;

    printf("Introdueix tres nombres (deixant espais 1 2 3): ");
    scanf("%d %d %d", &a, &b, &c);
    printf("a=%d, b=%d i c= %d", a, b, c);

    //Creixent si el valor anterior es inferior o igual al actual a=4, b=4 i c=11
    //Decreixent si el valor anterior no es inferior ni igual al actual  a=6, b=6 i c=-7
    //Ni creixent ni decreixent  a=6, b=-6 i c=11

    if (a <= b && b <= c) {
        printf("\nSequencia creixent");
    } else if ( a >= b && b >= c){
        printf("\nSequencia decreixent");
    } else printf("\nSequencia ni creixent ni decreixent");

    getch();
    return 0;
}