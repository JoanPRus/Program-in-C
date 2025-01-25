#include <stdio.h>
void estacio(int mes, int dia);
int mesdelany();
int diadelany();

/*(Estacio) Fer una funció que li passem un mes i un dia i ens retorni en quina
estació estem. Cal controlar que el mes sigui un nombre vàlid i que el dia
també sigui un nombre vàlid.*/

/*Verano: inicia el 21/06 y finaliza el 23/09.
Otoño: inicia el 23/09 y finaliza el 21/12.
Invierno: inicia el 21/12 y finaliza el 20/03.
Primavera: inicia el 20/03 y finaliza el 21/06.*/


int main(){

    int mes, dia;

    mes = mesdelany();
    dia = diadelany();
    estacio(mes,dia);

    getch();
    return 0;
}

void estacio(int mes, int dia)
{
    if ((mes == 6 && dia >= 21) || (mes == 9 && dia < 23) || (mes > 6 && mes < 9)){
        printf("El dia %d/%d es estiu", dia, mes);
    } else if ((mes == 9 && dia >= 23) || (mes == 12 && dia < 21) || (mes > 9 && mes < 12)){
        printf("El dia %d/%d es tardor", dia, mes);
    } else if ((mes == 12 && dia >= 21) || (mes == 3 && dia < 20) || (mes < 3)){
        printf("El dia %d/%d es hivern", dia, mes);
    } else if ((mes == 3 && dia >= 20) || (mes == 6 && dia < 21) || (mes > 3 && mes < 6)){
        printf("El dia %d/%d es primavera", dia, mes);
    }

}
int mesdelany()
{
    int mes;
    do{
        printf("Introdueix un mes del any (1-12): ");
        scanf("%d", &mes);
    }while(mes > 12 || mes < 1);

    return mes;
}

int diadelany()
{
    int dia;
    do{
        printf("Introdueix un dia del mes (1-31): ");
        scanf("%d", &dia);
    }while(dia > 31  || dia < 1);

    return dia;
}

