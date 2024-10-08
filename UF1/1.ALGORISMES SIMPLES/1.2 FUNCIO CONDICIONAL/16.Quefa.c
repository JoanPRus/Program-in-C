#include <stdio.h>

//. Analitza el següent codi i explica què fa

int main() {
    int a = 0, b = 0, c = 0, aux = 0;
    
    printf("Introdueix els números: ");
    scanf("%d %d %d", &a, &b, &c);
    
    // intercanvi de valors per ordenar-los de major a menor. 
    if (a < b) {
        aux = a;
        a = b;
        b = aux;
    }
    
    if (b < c) {
        aux = b;
        b = c;
        c = aux;
    }
    
    if (a < b) {
        aux = a;
        a = b;
        b = aux;
    }
    
    printf("a: %d b: %d c: %d\n", a, b, c);

    getch();    
    return 0;
}
