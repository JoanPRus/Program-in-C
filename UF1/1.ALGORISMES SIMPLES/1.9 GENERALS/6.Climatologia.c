#include <stdio.h>
#include <stdlib.h>
#include <rlutil.h>


/* (Climatologia): Escriu un programa per una estació meteorològica. El
programa haurà de demanar a l’usuari la introducció de temperatures reals
amb valors decimals, les quals hauran d’estar compreses entre -69.9ºC i
69.9ºC (cal controlar-ho). Aquestes temperatures representen la temperatura
mitjana diària enregistrada. El programa acabarà d’enregistrar valors quan
l’usuari introdueixi una temperatura de 100 ºC. Un cop finalitzada la seqüència
caldrà que el programa ens indiqui el número de dies registrats (quantitat de
valors introduïts), quina ha estat la temperatura mitjana màxima/mínima i en
quin dia s’han donat, així com el diferencial en graus que presenten respecte
la temperatura mitjana global (que també caldrà mostrar).
Exemple:
Dia: 01 Temperatura: 20.3ºC
Dia: 02 Temperatura: 22.1ºC
Dia: 03 Temperatura: 25.2ºC
Dia: 04 Temperatura: 23.5ºC
Dia: 05 Temperatura: 19.1ºC
Dia: 06 Temperatura: 0.0ºC
Total dies registrats = 6 , Temperatura Mitjana Global = 22.04ºC
Temperatura Màxima = 25.2ºC , enregistrada el dia 03 amb un
diferencial de 3.16ºC respecte la mitjana.
Temperatura Mínima = 19.1ºC , enregistrada el dia 05 amb un
diferencial de -2,94ºC respecte la mitjana
*/


int main(){

    /*Pedir temperatura al usuario, controlar rango  -69.9-69.9, float, termina si introduce 100. 
    hacer temperatura minima, media, maxima. calcular las diferencia entre el valor medio con los  valores min y max. 
    tenemos que  decir cuantos dias en  total y los dias de min y max.*/

    float temperatura = 0, t_min = 69.9, t_max = -69.9, t_total = 0, t_media = 0,  diferencia_min = 0, diferencia_max = 0;
    int dia = 1,  dia_min,  dia_max;

    do {
        
      printf("Dia: %02d Temperatura: ", dia, temperatura); //preguntamos  la temperatura
      scanf("%f", &temperatura);
      
      if ((temperatura >= -69.9) && (temperatura <= 69.9)){ //rango para guardar los datos
        
        //sumamos el dia y las temperaturas
        dia++;
        t_total += temperatura;
        //determinamos las min  y max
        if (t_min > temperatura){
          t_min = temperatura;
          dia_min = dia - 1;
        }
          if (t_max < temperatura){
          t_max = temperatura;
          dia_max = dia - 1;
        }


      } 
    }while (temperatura != 100);
    //operaciones varias
    t_media = t_total / (dia - 1);
    diferencia_min = t_min - t_media;
    diferencia_max = t_max - t_media;
    printf("Total de dies registrats = %d", (dia - 1)); printf("\tTemperatura mitjana global = %f", t_media);
    printf("\nTemperatura maxima = %.2f, enregistrada el dia %02d amb una diferencia de %.2f respecte la mitjana", t_max, dia_max, diferencia_max);
    printf("\nTemperatura minima = %.2f, enregistrada el dia %02d amb una diferencia de %.2f respecte la mitjana", t_min, dia_min,  diferencia_min);

    //problemas para eliminar la ultima linea (100) y tambien cuando estan fuera del rango. 
    //si hubiese  utilizado for no tendria  esos problemas, podria  haber imprimido los datos validos en un array. 




    getch();
    return 0;
}
