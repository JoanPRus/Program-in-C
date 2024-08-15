#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main()
{
    //Demana un caràcter i determina si és lletra majúscula, minúscula, dígit o diferent.

    /*isalpha(c) verifica si el carácter es una letra. isupper(c) verifica si la letra es mayúscula.
    isdigit(c) verifica si el carácter es un dígito.*/


    char c; 

    printf("Introdueix un caracter: ");
    scanf("%c", &c);

    if (isalpha(c))
        if (isupper((c)))
        {
            printf("Podem dir que (%c) es una lletra mayuscula", c);

        } else
            {
        printf("Podem dir que (%c) es una lletra minuscula", c); 
            }
            
    else if (isdigit(c)) {
        printf("Podem dir que (%c) es un digit", c);
    }     
    
     else printf("Podem dir que (%c) no es una lletra ni un digit", c);

    return 0;
}
