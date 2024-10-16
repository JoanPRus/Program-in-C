


/*(TipusCaracter) Demana un caràcter, determina si és lletra majúscula,
minúscula, dígit o diferent. Cal utilitzar els codis ASCII*/

//este ejercicio ya  lo hice de otra forma, usando <ctype.h> 

#include <stdio.h>

int main() {
    char c;

    printf("Introduce un carácter: ");
    scanf(" %c", &c);  // Asegúrate de incluir un espacio antes de %c para ignorar espacios

    // Obtener el valor ASCII del carácter
    int ascii_value = (int)c;

    switch (ascii_value) {
        // Verificar si es una letra mayúscula (A-Z)
        case 65: case 66: case 67: case 68: case 69:
        case 70: case 71: case 72: case 73: case 74:
        case 75: case 76: case 77: case 78: case 79:
        case 80: case 81: case 82: case 83: case 84:
        case 85: case 86: case 87: case 88: case 89:
        case 90:
            printf("'%c' es una letra mayúscula.\n", c);
            break;

        // Verificar si es una letra minúscula (a-z)
        case 97: case 98: case 99: case 100: case 101:
        case 102: case 103: case 104: case 105: case 106:
        case 107: case 108: case 109: case 110: case 111:
        case 112: case 113: case 114: case 115: case 116:
        case 117: case 118: case 119: case 120: case 121:
        case 122:
            printf("'%c' es una letra minúscula.\n", c);
            break;

        // Verificar si es un dígito (0-9)
        case 48: case 49: case 50: case 51: case 52:
        case 53: case 54: case 55: case 56: case 57:
            printf("'%c' es un dígito.\n", c);
            break;

        // Verificar si es un espacio
        case 32:
            printf("'%c' es un espacio.\n", c);
            break;

        // Verificar si es un símbolo o carácter especial
        default:
            printf("'%c' es un símbolo o carácter especial.\n", c);
            break;
    }
    
    getch();
    return 0;
}
