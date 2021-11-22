#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h>  /* printf */
#include <string.h> /* strcmp */
#include "produto.h"
#include "catalogo.h"
#include "usuario.h"

/*Função para encerrar o catálogo*/
void EncerrarCatalogo(Catalogo *C)
{
    /*Verifica se o catálogo tem algum produto*/
    if (C->prat_ini == NULL)
    {
        printf("                     =                                                           Opcao Selecionada: Encerrar Leilao                                                                  =\n");
        printf("                     =---------------------------------------------------------------------------------------------------------------------------------------------------------------=\n");
        printf("                     =                                                                   Leilao Encerrado!                                                                           =\n");
        printf("                     =                                                   Nao haviam produtos cadastrados, nem lances efetuados.                                                      =\n");
        printf("                     =                                                        A equipe ViDaJao espera lhe rever em breve!                                                            =\n");
        printf("                     =================================================================================================================================================================\n");
    }
    else if (C->prat_ini->produto->topo_lance == NULL)
    {
        printf("                     =                                                           Opcao Selecionada: Encerrar Leilao                                                                  =\n");
        printf("                     =---------------------------------------------------------------------------------------------------------------------------------------------------------------=\n");
        printf("                     =                                                                   Leilao Encerrado!                                                                           =\n");
        printf("                     =                                                              Nao haviam lances efetuados.                                                      =\n");
        printf("                     =                                                        A equipe ViDaJao espera lhe rever em breve!                                                            =\n");
        printf("                     =================================================================================================================================================================\n");
    }
    else
    {
        printf("                     =                                                           Opcao Selecionada: Encerrar Leilao                                                                  =\n");
        printf("                     =---------------------------------------------------------------------------------------------------------------------------------------------------------------=\n");
        printf("                     =                                                                   Leilao Encerrado!                                                                           =\n");
        printf("                     =                                                             Confira os Produtos e Vencedores:                                                                 =\n");
        Prateleira *p;
        p = C->prat_ini;
        while (p != NULL)
        {
            if (p->produto->topo_lance != NULL)
            {
                printf("                                              Vencedor do Produto \"%s\" :", p->produto->nome_prod);
                printf("\"%s\" ", p->produto->topo_lance->info->nome);
                printf("\n");
                printf("                                                                    Comprado por: R$ %f\n", p->produto->topo_lance->info->valor);
            }
            else
            {
                printf("                                                            O produto \"%s\" nao teve lances efetuados.\n", p->produto->nome_prod);
            }
            p = p->prox;
        }
        printf("                     =                                                        A equipe ViDaJao espera lhe rever em breve!                                                            =\n");
        printf("                     =================================================================================================================================================================\n");
    }
}

void PrintarProdutos(Catalogo *C)
{
    if (C->prat_ini == NULL)
    {
        printf("                     =                                                        Opcao Selecionada: Listar Produtos e Lances                                                            =\n");
        printf("\n\n");
        printf("                     =---------------------------------------------------------------------------------------------------------------------------------------------------------------=\n");
        printf("                     =                                                            Nenhum produto foi cadastrado!                                                                     =\n");
        printf("                     =================================================================================================================================================================\n");
        printf("\n\n");
        return;
    }
    else
    {
        Prateleira *p;
        p = C->prat_ini;
        printf("                     =                                                        Opcao Selecionada: Listar Produtos e Lances                                                            =\n");
        printf("                     =---------------------------------------------------------------------------------------------------------------------------------------------------------------=\n");
        while (p != NULL)
        {
            printf("\n\n");
            printf("                                                                          >>> Produto: \"%s\", Lance inical: R$ %d\n", p->produto->nome_prod, p->produto->valor_min);
            PrintarLances(p->produto);
            p = p->prox;
        }
    }
}

/*Cadastrar um novo produto*/
void CadastrarProduto(Catalogo *C, char *nome_produt, float valor_min)
{
    /*aloca memoria para o novo produto*/

    Produto *pp;
    pp = NovoProduto(nome_produt, valor_min);
    Prateleira *prat;
    prat = (Prateleira *)malloc(sizeof(Prateleira));

    prat->produto = pp;

    /*insere o novo produto na lista em ordem alfabetica*/
    if (C->prat_ini == NULL)
    {
        C->prat_ini = prat;
        C->prat_fim = prat;
        printf("                     =                                                                  Produto cadastrado!                                                                          =\n");
    }
    else
    {

        if (strcmp(C->prat_ini->produto->nome_prod, nome_produt) < 0)
        {
            /*se aux for o primeiro da lista e a inserção for a esquerda*/
            prat->prox = C->prat_ini;
            prat->ant = NULL;
            C->prat_ini->ant = prat;
            C->prat_ini = prat;
            printf("                     =                                                                  Produto cadastrado!                                                                          =\n");
        }
        else if (strcmp(C->prat_fim->produto->nome_prod, nome_produt) > 0)
        {
            /*se aux for o ultimo da lista e a inserção for à direita*/
            prat->prox = NULL;
            prat->ant = C->prat_fim;
            C->prat_fim->prox = prat;
            printf("                     =                                                                  Produto cadastrado!                                                                          =\n");
        }
        else if (strcmp(C->prat_ini->produto->nome_prod, nome_produt) == 0)
        {
            /*se tiverem nomes iguais*/
            printf("                     =                                                                 Produto ja cadastrado!                                                                        =\n");
            free(prat);
            return;
        }
        else
        {
            Prateleira *aux;
            aux = C->prat_ini;

            /*procura a posicao correta para inserir o novo produto*/
            while (strcmp(aux->produto->nome_prod, nome_produt) > 0)
            {
                aux = aux->prox;
            }

            prat->prox = aux;
            prat->ant = aux->ant;
            aux->ant->prox = prat;
            aux->ant = prat;
            printf("\n\n");
            printf("                     =                                                                  Produto cadastrado!                                                                           =\n");
            printf("\n\n");
        }
    }
    printf("                     =================================================================================================================================================================\n");
}

/*Criar novo Catalogo*/
Catalogo *NovoCatalogo(void)
{

    /*aloca-se a memoria para o novo catalogo*/
    Catalogo *C = (Catalogo *)malloc(sizeof(Catalogo));

    /*atribuindo os valores*/
    C->prat_ini = NULL;
    C->prat_fim = NULL;
    return C;
}

Produto *ProcurarProduto(Catalogo *C, char *nome_prod)
{
    Prateleira *aux;
    aux = C->prat_ini;
    while (aux != NULL)
    {
        if (strcmp(aux->produto->nome_prod, nome_prod) == 0)
        {
            return aux->produto;
        }
        aux = aux->prox;
    }
    return NULL;
}

void RemoverProduto(Catalogo *C, char *nome_prod)
{

    Prateleira *aux;
    aux = C->prat_ini;

    /*procura o produto a ser removido*/
    while (aux != NULL)
    {
        if (strcmp(aux->produto->nome_prod, nome_prod) == 0)
        {
            break;
        }
        aux = aux->prox;
    }

    /*se nao encontrou o produto*/
    if (aux == NULL)
    {
        printf("Produto nao encontrado.\n");
        return;
    }

    /*se o produto for o primeiro da lista*/
    if (aux == C->prat_ini)
    {
        C->prat_ini = aux->prox;
        if (C->prat_ini != NULL)
        {
            C->prat_ini->ant = NULL;
        }
        free(aux);
        return;
    }

    /*se o produto for o ultimo da lista*/
    if (aux == C->prat_fim)
    {
        C->prat_fim = aux->ant;
        C->prat_fim->prox = NULL;
        free(aux);
        return;
    }

    /*se o produto estiver no meio da lista*/
    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;
    free(aux);

    return;
}

void SugerirProduto(Catalogo *C)
{
    printf("\n\n");
    int flag = 1;
    Prateleira *auxProdutoExterno = C->prat_ini;

    /*percorre a lista de produtos*/
    while (auxProdutoExterno != NULL)
    {

        No *auxNos = auxProdutoExterno->produto->usuarios->primeiro;

        /*percorre a lista de lances*/
        while (auxNos != NULL)
        {

            Prateleira *auxProdutoInterno = C->prat_ini;

            /*percorre a lista de produtos para sugerir ao comprador*/
            while (auxProdutoInterno != NULL)
            {

                /*se não for o mesmo produto*/
                if (auxProdutoInterno != auxProdutoExterno)
                {
                    /*se usuario não tiver feito lance no produto*/
                    if (!ProcurarUsuario(auxProdutoInterno->produto, auxNos->nome))
                    {
                        printf("                                                                              \"%s\", que tal dar um lance em \"%s\"\n?", auxNos->nome, auxProdutoInterno->produto->nome_prod);
                        flag = 0;
                    }
                }

                auxProdutoInterno = auxProdutoInterno->prox;
            }
            auxNos = auxNos->prox;
        }
        auxProdutoExterno = auxProdutoExterno->prox;
    }
    if (flag)
    {
        printf("                                                                              Não há sugestões a fazer");
    }
    return;
}