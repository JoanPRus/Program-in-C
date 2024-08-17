#include <stdio.h>
#include <string.h>

/*(ConversorTemperatura) Demana la temperatura d’una habitació en escala
Fahrenheit i calcula la seva equivalència a Cèlsius. La formula que transforma
de Celsius a Fahrenheit és: Celsius = (5/9) * (Fahrenheit-32);*/
int main() {

float temperatura, formula;
const float celsius = 5.0 / 9.0;

printf("Introdueix la temperatura en Fahrenheit: ");
scanf("%f", &temperatura);

formula = celsius * (temperatura - 32);

printf("La temperatura en celsius es %.2f", formula);

return 0; 
}

