#include <stdio.h>
#include <rlutil.h>


/*) Es vol simular un rellotge. Per a fer-ho es demanarà a l’usuari
quants minuts vol visualitzar i a continuació cal fer el rellotge des del 0:0 fins
als minuts introduïts per l’usuari. Recordeu utilitzar la funció Sleep(1000) per
a fer l’aturada del programa d’1 segon i cls() per netejar la pantalla
*/

int main() {

    //tengo que tener en cuenta que a  los 60 segundos el reloj tiene que aumentar  a un minuto
    //preguntar al usuario los minutos que quiere  visualizar
    //crear un bucle que haga funcionar el  reloj
    //condiciones dentro del bucle para los segundos a minutos.

    int minutsusuari;
    int minutsrellotge;
    int segonsrellotge; 
    int minfinal = minutsrellotge;
   

    printf("Introdueix els minuts que vols visualitzar: ");
    scanf("%d", &minutsusuari);

    for (int minutsrellotge = 0; minutsrellotge < minutsusuari; minutsrellotge++) { //repetimos  el siguiente bucle con el numero de minutos del usuario
            for (int segonsrellotge = 0; segonsrellotge <= 59; segonsrellotge++){
            printf("%d:%02d", minutsrellotge, segonsrellotge);
            Sleep(1000);
            cls();
        }
    } 

    printf("%d:0",minutsusuari);

  


    getch();
    return 0;
}