

/*(TipusCaracter) Demana un caràcter, determina si és lletra majúscula,
minúscula, dígit o diferent. Cal utilitzar els codis ASCII
Exemple: carácter=’f’
Resultat: El carácter f es una lletra minúscula
*/

#include <stdio.h>

int main() {
    char car;

    // Solicitar el carácter al usuario
    printf("Introdueix un caràcter: ");
    scanf("%c", &car);

    // Verificar el tipo de carácter utilizando los códigos ASCII
    if (car >= 'A' && car <= 'Z') {
        printf("Resultat: El caràcter '%c' és una lletra majúscula\n", car);
    } else if (car >= 'a' && car <= 'z') {
        printf("Resultat: El caràcter '%c' és una lletra minúscula\n", car);
    } else if (car >= '0' && car <= '9') {
        printf("Resultat: El caràcter '%c' és un dígit\n", car);
    } else {
        printf("Resultat: El caràcter '%c' és diferent\n", car);
    }

    return 0;
}
