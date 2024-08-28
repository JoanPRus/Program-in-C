#include <stdio.h>          //Programa con IA, tiene fallo con detectar mayúsculas y minúsculas, no importante. 
#include <stdbool.h>  // Incluir el encabezado para usar true y false

int main() {
    char dia[10];
    bool es_festivo = false;  // Usamos false en lugar de 0

    while (true) {  // Usamos true en lugar de 1 para el bucle infinito
        printf("Introduce un dia de la semana (escribe 'salir' para terminar): ");
        scanf("%s", &dia);

        // Variable para determinar si el usuario quiere salir
        bool quiere_salir = true;  // Inicializamos a true
        // Variable para comparar el input con "salir"
        char salir[] = "salir";

        // Comparar la entrada del usuario con "salir"
        int i = 0;
        while (dia[i] != '\0' && salir[i] != '\0') {
            if (dia[i] != salir[i]) {
                quiere_salir = false;  // Las cadenas son diferentes
                break;  // No hace falta seguir comparando
            }
            i++;
        }

        // Si ambas cadenas tienen diferente longitud, no son iguales
        if (dia[i] != '\0' || salir[i] != '\0') {
            quiere_salir = false;
        }

        // Si el usuario quiere salir, romper el bucle
        if (quiere_salir == true) {
            break;
        }

        // Verificar si el día ingresado es "sabado"
        bool es_sabado = true;
        char sabado[] = "sabado";
        i = 0;
        while (dia[i] != '\0' && sabado[i] != '\0') {
            if (dia[i] != sabado[i]) {
                es_sabado = false;  // Las cadenas son diferentes
                break;
            }
            i++;
        }

        if (dia[i] != '\0' || sabado[i] != '\0') {
            es_sabado = false;
        }

        // Verificar si el día ingresado es "domingo"
        bool es_domingo = true;
        char domingo[] = "domingo";
        i = 0;
        while (dia[i] != '\0' && domingo[i] != '\0') {
            if (dia[i] != domingo[i]) {
                es_domingo = false;  // Las cadenas son diferentes
                break;
            }
            i++;
        }

        if (dia[i] != '\0' || domingo[i] != '\0') {
            es_domingo = false;
        }

        // Comprobar si el día es festivo
        if (es_sabado == true || es_domingo == true) {
            es_festivo = true;
        } else {
            es_festivo = false;
        }

        // Mostrar si el día es festivo o no
        if (es_festivo == true) {
            printf("El %s es un día festivo.\n", dia);
        } else {
            printf("El %s no es un día festivo.\n", dia);
        }
    }
    getch();
    printf("Programa terminado.\n");
    return 0;
}
