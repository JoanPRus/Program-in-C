#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Función que calcula el precio
float calcularPreu(bool esFestiu, bool esSocipremium) {
    int preulaboral = 80;
    int preufestiu = 100;
    float preuhabitacio;

    // Determinamos el precio según si es festivo o no
    if (esFestiu) {
        preuhabitacio = preufestiu;
    } else {
        preuhabitacio = preulaboral;
    }

    // Aplicamos descuento si es socio premium
    if (esSocipremium) {
        preuhabitacio *= 0.95; // Descuento del 5%
    }

    return preuhabitacio;
}

int main() {
    // Declaramos variables
    char dia[15];
    char sisoci[5];
    bool esFestiu;
    bool esSocipremium;

    // Preguntamos el día y si es socio
    printf("Quin dia es? ");
    scanf("%14s", dia);
    printf("Ets soci premium? ");
    scanf("%4s", sisoci);

    // Verificamos si es festivo (sábado o domingo)
    if (strcasecmp(dia, "Dissabte") == 0 || strcasecmp(dia, "Diumenge") == 0) {
        esFestiu = true;
    } else if (strcasecmp(dia, "Dilluns") == 0 || strcasecmp(dia, "Dimarts") == 0 || 
               strcasecmp(dia, "Dimecres") == 0 || strcasecmp(dia, "Dijous") == 0 || 
               strcasecmp(dia, "Divendres") == 0) {
        esFestiu = false;
    } else {
        printf("Dades incorrectes\n");
        return 1; // Salir si el día es incorrecto
    }

    // Verificamos si es socio premium (Sí o No)
    if (strcasecmp(sisoci, "Si") == 0) {
        esSocipremium = true;
    } else if (strcasecmp(sisoci, "No") == 0) {
        esSocipremium = false;
    } else {
        printf("Resposta no valida\n");
        return 1; // Salir si la respuesta es inválida
    }

    // Calculamos el precio usando la función
    float preuhabitacio = calcularPreu(esFestiu, esSocipremium);

    // Mostramos el resultado
    printf("El preu es %.2f euros\n", preuhabitacio);
    
    getch();
    return 0;
}
