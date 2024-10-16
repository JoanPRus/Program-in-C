#include <stdio.h>

/*Mostra0a99) Mostra els números des del 0 fins al 99; fixa’t amb el format
final de la impressió. Per imprimir un número alineat a ma dreta, utilitzeu la
instrucció:
printf(“%2d”,i);
 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
10,11,12,13,14,15,16,17,18,19
20,21,22,23,24,25,26,27,28,29
30,31,32,33,34,35,36,37,38,39
40,41,42,43,44,45,46,47,48,49
50,51,52,53,54,55,56,57,58,59
60,61,62,63,64,65,66,67,68,69
70,71,72,73,74,75,76,77,78,79
80,81,82,83,84,85,86,87,88,89
90,91,92,93,94,95,96,97,98,99
*/

int main() {

    int num1 =  0;
    int num2 = 99;

    for (int num1 = 0; num1 <= num2; num1++){
        printf("%2d,",num1);
            if(num1 == 9 || num1 == 19 || num1 == 29 || num1 == 39 || num1 == 49 || num1 == 59 || num1 == 69 || num1 == 79 || num1 == 89 || num1 == 99){
                printf("%d",num1);
                printf("\n");

            }

        }
    





    getch();
    return 0;
}