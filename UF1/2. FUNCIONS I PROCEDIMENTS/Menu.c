#include <stdio.h>
#include <rlutil.h>
#include <time.h>
#include <stdbool.h>
void marc();
void MistermainIA();
void MisterMainIA2(); 
void prinTitol2();
void prinTitol();
int asignaNumATrobar();
void comprovaVolta(bool volta, int numero, int num_masAnterior, int num_menosAnterior, int vueltas, int numAIAnterior,char cAnterior);
char retornaCaracter(int numIA, int numero);
void valorsAnteriors(int *num_masAnterior,  int num_mas, int *num_menosAnterior, int num_menos, int *numAIAnterior, int  numIA, char *cAnterior, char c);




int main(){
int opcio = 1, x = 40, y = 7, contador = 0;

while(opcio != 3){
    cls();

    marc();

    gotoxy(x, y);
    printf("Selecciona un videojoc");
    y += 2;
    gotoxy(x, y);
    printf("MisterMainIA2.....1");
    y += 2;
    gotoxy(x, y);
    printf("MisterMainIA......2");
    y += 2;
    gotoxy(x, y);
    printf("Sortida del menu..3");
    y += 2;
    gotoxy(x, y);
    printf("Opcio:");
    scanf("%d",  &opcio);

    x = 40;
    y = 7;

    switch (opcio)
    {
    case 1:
        cls();
        MisterMainIA2();
        
        break;
    case 2:
        cls();
        MistermainIA();
        break;
    case 3:

    
        while(contador != 3){
            
            gotoxy(x, (y + 15));
            printf("Sortin del menu");
            Sleep(500);
            gotoxy(x, (y + 15));
            printf("Sortin del menu.");
            Sleep(500);
            gotoxy(x, (y + 15));
            printf("Sortin del menu..");
            Sleep(500);
            gotoxy(x, (y + 15));
            printf("Sortin del menu...");
            Sleep(500);
            gotoxy(x, (y + 15));
            printf("Sortin del menu   ");
            Sleep(500);

            contador  += 1;
    
        }
        cls();
        
        break;

    default:
        printf("\nOpcio no valida.");
        break;
    }
    }

    getch();
    return 0;
}


void MisterMainIA2(){
    /*Introducir un numero de 4  digitos,  y  que la maquina lo adivine,  la IA debe asignar el valor si es +, -, o =*/
    srand(time(NULL)); 
    int numero = 0, numIA = 0, vueltas  = 1, num_menos = 9999,  num_mas = 1000;
    char c, cAnterior; 
    bool volta = false, numEncontrado = false;
    int num_masAnterior = 0, num_menosAnterior = 0, numAIAnterior = 0;
    
    prinTitol();

    numero = asignaNumATrobar();

    while(!numEncontrado)
    {
        c = ' ';
        numIA = rand() % (num_menos - num_mas + 1) + num_mas; 

        comprovaVolta(volta,  numero,  num_masAnterior,  num_menosAnterior,  vueltas,  numAIAnterior, cAnterior);

        c = retornaCaracter(numIA, numero);

        printf("\n[%d-%d]---> numero generat en el intent [%.2d] = %d %c", num_mas, num_menos, vueltas, numIA, c);
        vueltas++;

        //paso  la  direccion de  las variables  &
        valorsAnteriors( &num_masAnterior, num_mas, &num_menosAnterior, num_menos, &numAIAnterior, numIA, &cAnterior, c);
        
        if(c == '+') num_mas = numIA + 1;                
        else if(c == '-') num_menos = numIA - 1;
        else if(c == '=') numEncontrado = true;
        volta = true; 
        Sleep(2000);
    }

    printf("\nNumero trobat  amb %d intents!!!", vueltas - 1);
    printf("\nPrem una tecla per finalitzar");

    getch();

}

void prinTitol()
{
    setColor(BLUE);
    printf("\t  Bienvenido a  MasterMindAI\n");
    setColor(WHITE);
}

int asignaNumATrobar()//El numeroLocal nace y muere dentro de la funcion se devuelve el valor y se le asigna al numero global
{
    int numeroLocal;
    do {
    printf("\n\nintrodueix  un  numero de 4  digits: ");
    scanf("%d", &numeroLocal);
    }while(numeroLocal < 1000 || numeroLocal > 9999);
    return numeroLocal;
}

void comprovaVolta(bool volta, int numero, int num_masAnterior, int num_menosAnterior, int vueltas, int numAIAnterior,char cAnterior)
{
    if (volta){
        cls();
        prinTitol();
        printf("El numero ha adivinar es el: %d",  numero);
        printf("\n[%d-%d]---> numero generat en el intent [%.2d] = %d %c", num_masAnterior, num_menosAnterior, vueltas - 1, numAIAnterior, cAnterior);
    }
}

char retornaCaracter(int numIA, int numero)
{
    char c = ' ';
    if(numIA > numero)  c = '-';
    if(numIA < numero)  c = '+';
    if(numIA == numero) c = '=';
    return c;
}

//para  poder esta funcion necesito usar punteros para modificar los valores 
void valorsAnteriors(int *num_masAnterior,  int num_mas, int *num_menosAnterior, int num_menos, int *numAIAnterior, int  numIA, char *cAnterior, char c)
{
    *num_masAnterior = num_mas;
    *num_menosAnterior = num_menos;
    *numAIAnterior = numIA;
    *cAnterior = c;
}
void MistermainIA(){

    /*Introducir un numero de 4  digitos,  y  que la maquina lo adivine,  indicar si es mas grande + o mas  pequeño -*/

    int numero = 0, numIA = 0, vueltas  = 1, num_menos = 9999,  num_mas = 1000;
    char c, cG; 
    bool volta = false;
    int num_masG = 0, num_menosG = 0, numIAG = 0;
    
    prinTitol2();

    //pedimos  el  numero  y  controlamos que tenga  4 digitos.  
    do {
    printf("\n\nintrodueix  un  numero de 4  digits: ");
    scanf("%d", &numero);
    }while(numero < 1000 || numero > 9999);

    //ahora tengo  que hacer que  el ordenador genere  numeros con ciertas  condiciones. 4 digitos y que controle si es mas grande o pequeño el numero. 

    srand(time(NULL)); 

    while(numero != numIA){

        c = ' ';//elimina el caracter anterior
        numIA = rand() % (num_menos - num_mas + 1) + num_mas; //genera  el numero  teniendo en cuenta los limites  y luego  se suma num_mas 
        if (volta){
            cls();
            prinTitol2();
            printf("El numero ha adivinar es el: %d",  numero);
            printf("\n[%d-%d]---> numero generat en el intent [%.2d] = %d %c", num_masG, num_menosG, vueltas - 1, numIAG, cG);


        }
        printf("\n[%d-%d]---> numero generat en el intent [%.2d] = %d %c", num_mas, num_menos, vueltas, numIA, c);
        scanf(" %c", &c);
        vueltas++;

        num_masG = num_mas;
        num_menosG = num_menos;
        numIAG = numIA;
        cG = c;



        if(c == '+'){

            num_mas = numIA + 1;  //limite del rango  por abajo se  suma 1 
                  

        }else if(c == '-'){

            num_menos = numIA - 1; //limite  del  rango   por arriba se resta 1.

        }else if(c == '='){
            break;
        }
        volta = true; 
    }

    printf("Numero trobat  amb %d intents!!!", vueltas - 1);

    getch();
    
}

void prinTitol2()//funcion  
{
    setColor(BLUE);
    printf("\t  Bienvenido a  MasterMindAI\n");
    setColor(WHITE);
}


void marc(){

    //muy parecido  al anterior, facil.
    

    int altura =  13, ancho = 50;
    int x = 30, y = 5;

    
    
    /*Primer bucle la altura, para  \n cuando i++.  el segundo el ancho, escribe lo que le toca.
    las condiciones son faciles, pinta X si j  =  1 o = ancho. tambien  si  i = 1 o = altura*/
    for (int i = 1; i <= altura; i++){
        
        gotoxy(x,y);

        for  (int  j = 1; j <= ancho; j++){
            
           
            if ((i != 1) && (i != altura)){


                if ((j == 1) || (j == ancho)){
                    printf("#");
                } else {
                    printf(" ");
                }
            }else {
                printf("#");
            } 
           
        }
        y += 1;
      
    

    }
}
