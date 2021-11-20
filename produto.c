#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */
#include "produto.h"

void PrintarLances(Produto *P){

    Lance *aux = P->maior_lance;

    /*percorre-se printando lance por lance*/
    while(aux != NULL){
        printf("%s %f\n", aux->info->nome, aux->info->valor);
        aux = aux->prox_lance;
    }

    return;

}

void NovoLance(Produto *P, char *pessoa, float valor_lancado, int erro){

    if (valor_lancado < P->maior_lance->info->valor || valor_lancado < P->valor_min){
        erro = 1;
        return;
    }
    
    /*aloca-se a memoria para o novo lance*/
    Lance *novo = (Lance *) malloc(sizeof(Lance));
    novo->info = (Info *) malloc(sizeof(Info));
    novo->info->nome = pessoa;
    novo->info->valor = valor_lancado;

    if (P->menor_lance == NULL)
    {
        /*se for o primeiro lance:*/
        P->menor_lance = novo;
        P->maior_lance = novo;
        novo->prox_lance = NULL;
        novo->ant_lance = NULL;
    }
    else
    {
        /*atualizando os ponteiros de ordem*/
        Lance *aux = P->maior_lance;

        novo->ant_lance = aux;
        novo->prox_lance = NULL;
        aux->prox_lance = novo;
    }

    /*atualizando o maior lance*/
    P->maior_lance = novo;

    /*tudo certo*/
    erro = 0;
    return;
}

Produto* NovoProduto(char *nome_produto, float valor_min){
    /*aloca-se a memoria para o novo produto*/
    Produto *novo = (Produto *) malloc(sizeof(Produto));

    /*atribuindo os valores*/
    novo->nome_prod = nome_produto;
    novo->valor_min = valor_min;
    novo->maior_lance = NULL;
    novo->menor_lance = NULL;
    
    return novo;
}