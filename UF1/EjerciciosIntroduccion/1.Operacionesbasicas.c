#include <stdio.h>
int main()
{
    //Creant operacions amb dos enters
    
    int num,num2;
    printf("Ingresa un numero entero: ");
    scanf("%d", &num);
    printf("Se ingreso un %d", num);

    printf("\n");

    printf("Ingresa un segundo numero entero: ");
    scanf("%d", &num2);
    printf("Se ingreso un %d\n", num2);

    
    printf("\n%d + %d = %d\n",num,num2,num+num2);
    printf("\n%d - %d = %d\n",num,num2,num-num2);
    printf("\n%d * %d = %d\n",num,num2,num*num2);
    printf("\n%d / %d = %d\n",num,num2,num/num2);
    
    getch();
    return 0;
}