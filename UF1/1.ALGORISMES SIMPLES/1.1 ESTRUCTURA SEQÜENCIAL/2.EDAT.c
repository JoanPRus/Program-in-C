#include <stdio.h>
#include <time.h> 
 //formas mas sencillas para este ejercicio: preguntar al usuario en que año esta. 

 // Incluimos la biblioteca time.h para trabajar con funciones relacionadas con el tiempo

int main () {

    /* (Edat) Demana l’any en el que néixer una persona i calcula la seva edat
    actual. Funciona independientemente del año en el que se ejecute. */

    int edat, any;  // Declaramos dos variables enteras: edat (para almacenar la edad) y any (para almacenar el año de nacimiento)

    // Obtenemos el tiempo actual en segundos desde el Epoch (1 de enero de 1970)
    time_t t = time(NULL);

    // Convertimos el tiempo obtenido a una estructura tm que contiene desglosada la fecha y hora actual
    struct tm tm = *localtime(&t);

    // Calculamos el año actual sumando 1900 a tm.tm_year, ya que tm.tm_year cuenta los años desde 1900
    int anyactual = tm.tm_year + 1900;

    // Solicitamos al usuario que ingrese el año de nacimiento
    printf("En quin any has nascut: ");
    scanf("%d", &any);  // Leemos el año de nacimiento ingresado por el usuario y lo almacenamos en la variable 'any'

    // Verificamos si el año ingresado es mayor que el año actual (lo que sería un error)
    if (any > anyactual) {
        printf("Error: El any de naixement no pot ser al futur!\n");
    } 
    // Verificamos si el año ingresado es menor que 1900, lo que sería inusual y podría no tener sentido en este contexto
    else if (any < 1900) {
        printf("Error: El any de naixement no pot ser abans de 1900!\n");
    } 
    // Si el año ingresado es válido, calculamos y mostramos la edad
    else {
        edat = anyactual - any;  // Calculamos la edad restando el año de nacimiento del año actual
        printf("Actualment tens: %d anys\n", edat);  // Mostramos la edad calculada
    }
    getch();
    return 0;  // Finalizamos el programa
}
