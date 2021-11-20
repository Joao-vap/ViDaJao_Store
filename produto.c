#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */
#include "produto.h"
#include "lance.h"

void PrintarLances(Produto *P){
    if (P->lance_high == NULL){
        printf("=> Ainda nao ha lances para esse produto.\n");
    }
    else {
        Lance *lanc;
        lanc = P->lance_high;
        while (lanc != NULL) {
            printf(" ==> %s, R$ %f\n", lanc->pessoa, lanc->valor);
            lanc = lanc->ant_lance;
        }
    }
    printf("\n");
}

void NovoLance(Produto *P, char *pessoa, float valor_lancado, int erro){
    Lance *lancar;
    lancar = (Lance*) malloc(sizeof(Lance));
    lancar->valor = valor_lancado;
    /*
    char *pessoa_copy;
    strcpy(pessoa_copy, pessoa);
    lancar->pessoa = pessoa_copy;
    */
    lancar->pessoa = pessoa;
    
    if (valor_lancado > P->lance_min){
        if (P->lance_high == NULL) {
            P->lance_high = lancar;
            P->lance_high->prox_lance = NULL;
            P->lance_high->ant_lance = NULL;
            P->lance_min = valor_lancado;
            erro = 0;
        }
        else {
            if (lancar->valor >= P->lance_high->valor) {
                P->lance_high->prox_lance = lancar;
                P->lance_high->prox_lance->ant_lance = P->lance_high;
                P->lance_high = P->lance_high->prox_lance;
                P->lance_high->prox_lance = NULL;
                P->lance_min = valor_lancado;
                erro = 0;
            }
        }
    }
    else {
        erro = 3;
    }
}

Produto* NovoProduto(char *nome_produto, float valor_min){
    Produto *P;
    P = (Produto*) malloc(sizeof(Produto));
    P->nome_prod = nome_produto;
    P->lance_min = valor_min;
    P->lance_high = NULL;
    P->prox_prod = NULL;
    P->ant_prod = NULL;
    return P;
}