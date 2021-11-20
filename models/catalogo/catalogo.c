#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */
#include "lance.h"
#include "produto.h"
#include "catalogo.h"

void EncerrarCatalogo(Catalogo *C){
    if (C->prod_fim == NULL){
        printf("Leilao encerrado. Nao haviam produtos cadastrados, nem lances efetuados.\n");
    }
    if (C->prod_fim->lance_high == NULL){
        printf("Leilao encerrado. Haviam produtos cadastrados mas nenhum lance efetuado.\n");
    }
    else {
        printf("Leilao encerrado! Confira os produtos e vencedores:\n");
        Produto *p;
        p = C->prod_fim;
        while (p != NULL) {
            printf("O vencedor do produto \"%s\" ",p->nome_prod);
            printf("eh \"%s\" ",p->lance_high->pessoa);
            printf("Comprado por: R$ %f\n",p->lance_high->valor);
            p = p->ant_prod;
        }
    }
}

void PrintarProdutos(Catalogo *C){
    if (C->prod_ini == NULL){
        printf("=> Ainda nao ha produtos no leilao.\n");
    }
    else {
        Produto *p;
        p = C->prod_ini;
        while (p != NULL) {
            printf(">>> Produto: \"%s\", Valor minimo para lance: R$ %f\n", p->nome_prod, p->lance_min);
            PrintarLances(p);
            p = p->prox_prod;
        }
    }
}

void CadastrarProduto(Catalogo *C, char *nome_produt, float valor_min){
    Produto *pp;
    pp = (Produto*) malloc(sizeof(Produto));
    pp->lance_high = NULL;
    pp->prox_prod = NULL;
    pp->ant_prod = NULL;
    pp->lance_min = valor_min;
  
    /*char produto_copy[50];
    strcpy(produto_copy, nome_produt);
    printf("copia = %s\n", produto_copy);
    pp->nome_prod = produto_copy;*/

    pp->nome_prod = nome_produt;

    if (C->prod_ini == NULL) {
        C->prod_ini = pp;
        C->prod_fim = C->prod_ini;
    }
    else {
        C->prod_fim->prox_prod = pp;
        C->prod_fim->prox_prod->ant_prod = C->prod_fim;
        C->prod_fim = C->prod_fim->prox_prod;
    }
}

Catalogo* NovoCatalogo(void){
    Catalogo *C = (Catalogo*) malloc(sizeof(Catalogo));
    C->prod_ini = NULL;
    C->prod_fim = NULL;
    return C;
}