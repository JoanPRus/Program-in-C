#include <stdio.h>
#include <rlutil.h>


/*(Cronometre) Es demanarà a l’usuari quants segons vols i quants minuts vols.
Els segons hauran d’estar controlats entre 0 i 59; mentre que els minuts entre
0 i 3. A continuació cal fer el compte endarrere. En cada impressió netegeu la
pantalla amb cls() i recordeu d’utilitzar Sleep(1000) per a simular el temps
d’1s.*/


int main() {
    int minutsusuari, segonsusuari;
    int minutscronometre, segonscronometre;
    

    do {
        printf("Introdueix quants minuts  y segons vols (1:30): ");
        scanf("%d:%d", &minutsusuari, &segonsusuari);
    } while (segonsusuari > 59 ||  (minutsusuari == 3 && segonsusuari > 0));

    while (minutsusuari > 0 || segonsusuari > 0) {

        printf("%d:%02d", minutsusuari, segonsusuari);
        Sleep(1000);
        cls();
        segonsusuari--;

        if (segonsusuari < 0 && minutsusuari > 0) {
            minutsusuari--;
            segonsusuari = 59;
        }        
    } 
    printf("0:00");
    getch();
    return 0;
}