#include <stdio.h>
#include <conio.h>
/*(Mostra0a99v2) Mostra els números des del 0 fins al 99, en grup de n valors.
El paràmetre n es demana a l’usuari, abans de mostrar els valors per pantalla,
i haurà d’estar controlat entre 1 i 19.
Per resoldre l’exercici podeu tenir una variable que vagi comptant per a cada
línia, la quantitat de números que hem imprès.
Introdueix l'amplada: -6
Introdueix l'amplada: 23
Introdueix l'amplada: 12
 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11
12,13,14,15,16,17,18,19,20,21,22,23
24,25,26,27,28,29,30,31,32,33,34,35
36,37,38,39,40,41,42,43,44,45,46,47
48,49,50,51,52,53,54,55,56,57,58,59
60,61,62,63,64,65,66,67,68,69,70,71
72,73,74,75,76,77,78,79,80,81,82,83
84,85,86,87,88,89,90,91,92,93,94,95
96,97,98,99
Prem una tecla per finalitzar*/


//sin contador, chatgp

int main() {
    int n_valors;

    // Solicitar al usuario el ancho y validar el valor
    do {
        printf("Introdueix l'amplada: ");
        scanf("%d", &n_valors);
    } while (n_valors < 1 || n_valors > 19); // Controla que n_valors esté entre 1 y 19

    for (int i = 0; i <= 99; i++) {
        printf("%2d", i); // Imprimir el número actual
        
        // Comprobar si es el último número de la línea
        if ((i + 1) % n_valors == 0) {
            printf("\n"); // Salto de línea después de imprimir n_valors números
        } else {
            printf(", "); // Imprimir coma si no es el último de la línea
        }
    }

    getch(); // Esperar a que el usuario presione una tecla
    return 0;
}
