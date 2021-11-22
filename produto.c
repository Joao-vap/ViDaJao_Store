#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h>  /* printf */
#include <string.h>
#include "produto.h"
#include "usuario.h"

void PrintarLances(Produto *P)
{

    Lance *aux = P->topo_lance;

    /*percorre-se printando lance por lance*/
    while (aux != NULL)
    {
        printf("                                                                                      %s %f\n", aux->info->nome, aux->info->valor);
        aux = aux->prox_lance;
    }
    return;
}

int NovoLance(Produto *P, char *pessoa, float valor_lancado)
{
    if (P->topo_lance != NULL)
    {
        if (valor_lancado < P->topo_lance->info->valor)
        {
            return 1;
        }
    }

    if (valor_lancado < P->valor_min)
    {
        return 2;
    }

    /*aloca-se a memoria para o novo lance*/
    Lance *novo = (Lance *)malloc(sizeof(Lance));
    novo->info = (Info *)malloc(sizeof(Info));
    strcpy(novo->info->nome, pessoa);
    novo->info->valor = valor_lancado;

    if (P->topo_lance == NULL)
    {
        /*se for o primeiro lance:*/
        P->topo_lance = novo;
        novo->prox_lance = NULL;
        novo->ant_lance = NULL;
        /*atualizando o maior lance*/
        P->topo_lance = novo;
        /*Adiciona o usurio*/
        inserir_usuario(P->usuarios, pessoa);

    }
    else
    {   
        if (valor_lancado == P->topo_lance->info->valor){
            
            /*atualizando os ponteiros de ordem*/
            if (P->topo_lance->prox_lance == NULL)
            {
                P->topo_lance->prox_lance = novo;
                novo->ant_lance = P->topo_lance;
                novo->prox_lance = NULL;
            }
            else
            {
                novo->prox_lance = P->topo_lance->prox_lance;
                P->topo_lance->prox_lance->ant_lance = novo;
                P->topo_lance->prox_lance = novo;
                novo->ant_lance = P->topo_lance;
            }

            /*Adiciona o usurio*/
            inserir_usuario(P->usuarios, pessoa);
        }
        else 
        {
            /*atualizando os ponteiros de ordem*/
            P->topo_lance->ant_lance = novo;
            novo->prox_lance = P->topo_lance;
            novo->ant_lance = NULL;

            /*atualizando o maior lance*/
            P->topo_lance = P->topo_lance->ant_lance;

            /*Adiciona o usurio*/
            inserir_usuario(P->usuarios, pessoa);
        }
    }

    /*tudo certo*/
    return 0;
}

Produto *NovoProduto(char *nome_produto, float valor_min)
{
    /*aloca-se a memoria para o novo produto*/
    Produto *novo = (Produto *)malloc(sizeof(Produto));
    Usuarios *usuarios = (Usuarios *)malloc(sizeof(Usuarios));

    /*atribuindo os valores*/
    strcpy(novo->nome_prod, nome_produto);
    novo->usuarios = usuarios;
    novo->valor_min = valor_min;
    novo->topo_lance = NULL;
    //novo->maior_lance = NULL;
    //novo->menor_lance = NULL;

    return novo;
}

