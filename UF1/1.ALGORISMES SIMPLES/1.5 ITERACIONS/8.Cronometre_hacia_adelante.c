#include <stdio.h>
#include <rlutil.h>



/*(Cronometre) Es demanarà a l’usuari quants segons vols i quants minuts vols.
Els segons hauran d’estar controlats entre 0 i 59; mentre que els minuts entre
0 i 3.En cada impressió netegeu la
pantalla amb cls() i recordeu d’utilitzar Sleep(1000) per a simular el temps
d’1s.*/

int main() {

    int segonsusuari, minutsusuari; 
    int segonscronometre, minutscronometre; 
  

    //nos pide que el crono  tiene 3 min maximo 3:00

    do {
        printf("Introdueix el minuts y els segons  (format (1:50)): ");
        scanf("%d:%d", &minutsusuari, &segonsusuari);
    } while (segonsusuari > 59 || (minutsusuari == 3 && segonsusuari > 0));

    for (int minutscronometre = 0;  minutscronometre < minutsusuari; minutscronometre++){
        for (int segonscronometre = 0; segonscronometre <= 59; segonscronometre++){
            printf("%d:%02d", minutscronometre, segonscronometre);
            Sleep(100);
            cls();
        }
    }
  
    for (int segonscronometre = 0; segonscronometre < segonsusuari; segonscronometre++){
    printf("%d:%02d", minutsusuari, segonscronometre);
    Sleep(100);
    cls();
    } 
    printf("%d:%02d", minutsusuari, segonsusuari);


    getch();
    return  0;
}