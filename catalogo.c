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
        return;
    }
    else {
        Prateleira *p;
        p = C->prat_ini;
        while (p != NULL) {
            printf(">>> Produto: \"%s\", Lance inical: R$ %d\n", p->produto->nome_prod, p->produto->valor_min);
            PrintarLances(p->produto);
            p = p->prox;
        }
    }
}

/*Cadastrar um novo produto*/
void CadastrarProduto(Catalogo *C, char *nome_produt, float valor_min){
    /*aloca memoria para o novo produto*/

    Produto *pp;
    pp = NovoProduto(nome_produt, valor_min);
    Prateleira *prat;
    prat = (Prateleira*) malloc(sizeof(Prateleira));

    prat->produto = pp;

    /*insere o novo produto na lista em ordem alfabetica*/
    if (C->prat_ini == NULL) {
        C->prat_ini = prat;
        C->prat_fim = prat;
        printf("%s", "Produto cadastrado!\n");
    }
    else {

        if (strcmp(C->prat_ini->produto->nome_prod, nome_produt) < 0)
        {
            /*se aux for o primeiro da lista e a inserção for a esquerda*/
            prat->prox = C->prat_ini;
            prat->ant = NULL;
            C->prat_ini->ant = prat;
            C->prat_ini = prat;
            printf("%s", "Produto cadastrado!\n");
        }
        else if (strcmp(C->prat_fim->produto->nome_prod, nome_produt) > 0)
        {
            /*se aux for o ultimo da lista e a inserção for à direita*/
            prat->prox = NULL;
            prat->ant = C->prat_fim;
            C->prat_fim->prox = prat;
            printf("%s", "Produto cadastrado!\n");
        }
        else if (strcmp(C->prat_ini->produto->nome_prod, nome_produt) == 0)
        {
            /*se tiverem nomes iguais*/
            printf("Produto ja cadastrado.\n");
            free(prat);
            return;
        }
        else
        {
            Prateleira *aux;
            aux = C->prat_ini;

            /*procura a posicao correta para inserir o novo produto*/
            while (strcmp(aux->produto->nome_prod, nome_produt) > 0) {
                aux = aux->prox;
            }

            prat->prox = aux;
            prat->ant = aux->ant;
            aux->ant->prox = prat;
            aux->ant = prat;
            
            printf("%s", "Produto cadastrado!\n");
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

Produto* ProcurarProduto(Catalogo *C, char *nome_prod){
    Prateleira *aux;
    aux = C->prat_ini;
    while (aux != NULL) {
        if (strcmp(aux->produto->nome_prod, nome_prod) == 0) {
            return aux->produto;
        }
        aux = aux->prox;
    }
    return NULL;
}

void RemoverProduto(Catalogo *C, char *nome_prod){

    ProcurarProduto(C, nome_prod);
    
}

void SugerirProduto(Catalogo *C){

    Prateleira *auxProdutoExterno = C->prat_ini;

    /*percorre a lista de produtos*/
    while (auxProdutoExterno != NULL) {

        Lance *auxLances = auxProdutoExterno->produto->menor_lance;
        
        /*percorre a lista de lances*/
        while (auxLances != NULL) {

            Prateleira *auxProdutoInterno = C->prat_ini;

            /*percorre a lista de produtos para sugerir ao comprador*/
            while (auxProdutoInterno != NULL) {

                /*se o valor de um lance do usuario for maior que o o valor minimo de outro produto*/
                if (auxProdutoInterno->produto->valor_min < auxLances->info->valor && auxProdutoInterno != auxProdutoExterno) {
                    printf("O produto \"%s\" pode ser sugerido ao usuario \"%s\"\n", auxProdutoInterno->produto->nome_prod, auxLances->info->nome);
                }

                auxProdutoInterno = auxProdutoInterno->prox;
            }
            auxLances = auxLances->prox_lance;
        }
        auxProdutoExterno = auxProdutoExterno->prox;
    }
    return;
}