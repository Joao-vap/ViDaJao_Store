#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */
#include <string.h> /* strcmp */
#include "produto.h"
#include "catalogo.h"

void EncerrarCatalogo(Catalogo *C){
    if (C->prat_ini == NULL){
        printf("Leilao encerrado. Nao haviam produtos cadastrados, nem lances efetuados.\n");
    }
    else if (C->prat_ini->produto->maior_lance == NULL){
        printf("Leilao encerrado. Haviam produtos cadastrados mas nenhum lance efetuado.\n");
    }
    else {
        printf("Leilao encerrado! Confira os produtos e vencedores:\n");
        Prateleira *p;
        p = C->prat_ini;
        while (p != NULL) {
            printf("O vencedor do produto \"%s\" ",p->produto->nome_prod);
            printf("eh \"%s\" ",p->produto->maior_lance->info->nome);
            printf("Comprado por: R$ %f\n",p->produto->maior_lance->info->valor);
            p = p->prox;
        }
    }
}

void PrintarProdutos(Catalogo *C){
    if (C->prat_ini == NULL){
        printf("=> Ainda nao ha produtos no leilao.\n");
    }
    else {
        Prateleira *p;
        p = C->prat_ini;
        while (p != NULL) {
            printf(">>> Produto: \"%s\", Valor minimo para lance: R$ %f\n", p->produto->nome_prod, p->produto->valor_min);
            PrintarLances(p);
            p = p->prox;
        }
    }
}

/*Cadastrar um novo produto*/
void CadastrarProduto(Catalogo *C, char nome_produt, float valor_min){
    /*aloca memoria para o novo produto*/
    Produto *pp;
    pp = (Produto*) malloc(sizeof(Produto));
    Prateleira *prat;
    prat = (Prateleira*) malloc(sizeof(Prateleira));

    /*atribui os valores ao novo produto*/
    pp->maior_lance = NULL;
    pp->menor_lance = NULL;
    pp->valor_min = valor_min;
    pp->nome_prod = nome_produt;

    prat->produto = pp;

    /*insere o novo produto na lista em ordem alfabetica*/
    if (C->prat_ini == NULL) {
        C->prat_ini = pp;
        C->prat_fim = pp;
    }
    else {

        if (strcomp(C->prat_ini->produto->nome_prod, nome_produt) < 0)
        {
            /*se aux for o primeiro da lista e a inserção for a esquerda*/
            prat->prox = C->prat_ini;
            prat->ant = NULL;
            C->prat_ini->ant = prat;
            C->prat_ini = prat;
        }
        else if (strcomp(C->prat_fim->produto->nome_prod, nome_produt) > 0)
        {
            /*se aux for o ultimo da lista e a inserção for à direita*/
            prat->prox = NULL;
            prat->ant = C->prat_fim;
            C->prat_fim->prox = prat;
        }
        else
        {
            Prateleira *aux;
            aux = C->prat_ini;

            /*procura a posicao correta para inserir o novo produto*/
            while (strcomp(aux->produto->nome_prod, nome_produt) > 0) {
                aux = aux->prox;
            }

            prat->prox = aux;
            prat->ant = aux->ant;
            aux->ant->prox = prat;
            aux->ant = prat;
        }
    }
}

/*Criar novo Catalogo*/
Catalogo* NovoCatalogo(void){

    /*aloca-se a memoria para o novo catalogo*/
    Catalogo *C = (Catalogo*) malloc(sizeof(Catalogo));

    /*atribuindo os valores*/
    C->prat_ini = NULL;
    C->prat_fim = NULL;
    return C;
}