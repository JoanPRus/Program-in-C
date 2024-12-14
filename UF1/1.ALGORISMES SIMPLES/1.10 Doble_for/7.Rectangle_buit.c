#include <stdio.h>


/*(Rectangle_Buit) Fer una modificació de l'algoritme anterior, que dibuixi un
rectangle buit.*/


int main(){

    //muy parecido  al anterior, facil.
    
    int altura,  ancho;

    printf("Introdueix la altura entre 2-20: ");
    scanf("%d", &altura);
    printf("Introdueix la amplada entre 2-20: ");
    scanf("%d", &ancho);

    
    /*Primer bucle la altura, para  \n cuando i++.  el segundo el ancho, escribe lo que le toca.
    las condiciones son faciles, pinta X si j  =  1 o = ancho. tambien  si  i = 1 o = altura*/
    for (int i = 1; i <= altura; i++){
        
        for  (int  j = 1; j <= ancho; j++){
            
            if ((i != 1) && (i != altura)){


                if ((j == 1) || (j == ancho)){
                    printf("x");
                } else {
                    printf(" ");
                }
            }else {
                printf("x");
            }

            
        }

        printf("\n");

    }

    getch();
    return 0;
}