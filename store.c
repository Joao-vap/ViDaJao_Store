#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */
#include <string.h>
#include "lance.h"
#include "produto.h"
#include "catalogo.h"
#include "users.h"

int main(void){
    int escolha;
    printf("Qual versao?: ");
    scanf("%i", &escolha);
    if (escolha == 1) {
        return main_real();
    }
    else {
        main_fake();
    } 
    return 0;
}