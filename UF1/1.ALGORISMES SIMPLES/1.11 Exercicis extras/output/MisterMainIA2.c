#include <stdio.h>
#include <rlutil.h>
#include <time.h>
#include <stdbool.h> 

//En la parte superior del codigo despues de los includes de las bibliotecas se añaden los prototipos de las funciones
void prinTitol();
int asignaNumATrobar();
void comprovaVolta(bool volta, int numero, int num_masAnterior, int num_menosAnterior, int vueltas, int numAIAnterior,char cAnterior);
char retornaCaracter(int numIA, int numero);
void valorsAnteriors(int *num_masAnterior,  int num_mas, int *num_menosAnterior, int num_menos, int *numAIAnterior, int  numIA, char *cAnterior, char c);

/*(MasterMindAI): Inverteix el programa del MasterMind per tal de fer que ara
sigui el PC qui hagi d’encertar el número que prèviament ha introduit l’usuari.
El número a esbrinar ha de tenir 4 dígits.
*/ 

int main(){

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
    return 0;
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
