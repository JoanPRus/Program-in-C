#include <stdio.h>
#include <rlutil.h>
#include <time.h>


/*kbhit és una funció que està definida en el header de ‘conio.h’ i també en
‘rlutil.h’.
Permet testejar si s’ha premut una tecla. En el cas que s’hagi premut una tecla,
la funció retorna un valor diferent de zero; si no retorna zero.
Fer un programa que començant en la casella (1,5) i en increments d’1 en 1,
recorri la pantalla des de x=1 fins a la x=80. Quan arribi a x=80 ha de retornar
fins a x=1; i torna a anar cap a la dreta. Aquest procés es repetirà mentre que
no es premi una tecla.
En cada una dels printf ha de canviar el color del símbol que imprimeix.
Deixarem un Sleep de 50
Per comprovar el funcionament del kbhit () s’ha d’executar el .\main.exe*/

int main(){

    /*comenzar en 1,5. incrementar x +=1 hasta x = 80,  despues tiene que volver a x=1 y volver hasta x = 80
    asi  hasta que  presione una tecla. En cada impresion el caracter  tiene  que cambiar de color  dejamos medio segundo.*/

    //generar una semilla para  que sea aleatorio.  generar colores aleatorios para el texto. 

    srand(time(NULL));  //generamos la semilla 

    
    int x = 1, y = 5; //valores de inicio

    while (!kbhit()){  //si  no se presiona  ninguna  tecla el  bucle  sigue. 
        
        int color = rand() % 15 + 1; //generamos el color aleatorio, evitando el  negro (0)
        gotoxy(x,y);//posiciona el cursor
        setColor(color);//elige el color
        printf("X");//imprime la x con su color aleatorio
        Sleep(50);//se espera medio  segundo
        x += 1; // se aumenta la posicion de x
        
        if (x == 80){ // si  x = 80 se  aplica el siguiente bucle 
            while(x != 1){  // se  aplica el  bucle hasta que  x sea 1
                    x -= 1;//  restamos  a x -1.  80-1,79-1,...  hasta llegar a 1
                 int color = rand() % 15 + 1;  //aplicamos color
                    gotoxy((x - 1),y);//el cursor resta 1 a la x para ir a la izquierda asi hasta x=1
                    setColor(color);
                    printf("X");
                    Sleep(50);
                
            }
        }

    }

    getch();
    return 0;
}