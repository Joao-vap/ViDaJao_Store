#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */
#include "lance.h"
#include "produto.h"
#include "catalogo.h"

void main(void){
    Produto *P = (Produto*) malloc(sizeof(Produto));
    Lance *L = (Lance*) malloc(sizeof(Lance));
    Catalogo *C = (Catalogo*) malloc(sizeof(Catalogo));

    
    P->nome_prod = "TV 4k";
    L->pessoa = "Marlene";
    L->valor = 5499.00;
    P->lance_ini = L;
    C->produt = P;

    printf("Produto: %s\n",C->produt->nome_prod);
    printf("Lance 1: %s, R$ %f\n",C->produt->lance_ini->pessoa,C->produt->lance_ini->valor);
};
