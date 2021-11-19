#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */
#include <string.h>
#include "lance.h"
#include "produto.h"
#include "catalogo.h"

Produto* NovoProduto(char *nome_produto, float valor_min){
    Produto *P = (Produto*) malloc(sizeof(Produto));
    P->nome_prod = nome_produto;
    P->lance_min = valor_min;
    P->lance_high = NULL;
    return P;
}

void NovoLance(Produto *P, char *pessoa, float valor_lancado, int erro){
    Lance *lancar = (Lance*) malloc(sizeof(Lance));
    lancar->pessoa = pessoa;
    lancar->valor = valor_lancado;
    if (valor_lancado > P->lance_min){
        if (P->lance_high == NULL) {
            P->lance_high = lancar;
            P->lance_high->prox_lance = NULL;
            P->lance_high->ant_lance = NULL;
            P->lance_min = valor_lancado;
            erro = 0;
        }
        else {
            if (lancar->valor >= P->lance_high->valor){
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

Catalogo* NovoCatalogo(void){
    Catalogo *C = (Catalogo*) malloc(sizeof(Catalogo));
    C->prod_fim = NULL;
    return C;
}

void CadastrarProduto(Catalogo *C, char *nome_produto, float valor_min){
    Produto *P = NovoProduto(nome_produto, valor_min);
    if (C->prod_fim == NULL){
        C->prod_fim = P;
        C->prod_fim->prox_prod = NULL;
    }
    else {
        C->prod_fim->prox_prod = P;
        C->prod_fim->prox_prod->ant_prod = C->prod_fim;
        C->prod_fim = C->prod_fim->prox_prod;
        C->prod_fim->prox_prod = NULL;
    }
}

void PrintarProdutos(Catalogo *C){
    if (C->prod_fim == NULL){
        printf("=> Ainda nao ha produtos no leilao.\n");
    }
    else {
        Produto *prod;
        prod = C->prod_fim;
        while (prod != NULL) {
            printf(">>> Produto: %s, Valor minimo para lance: R$ %f\n", prod->nome_prod, prod->lance_min);
            PrintarLances(prod);
            prod = prod->ant_prod;
        }
    }
}

void EncerrarCatalogo(Catalogo *C){
    if (C->prod_fim == NULL){
        printf("Leilao encerrado. Nao haviam produtos cadastrados, nem lances efetuados.\n");
    }
    else {
        printf("Leilao encerrado! Confira os produtos e vencedores:\n");
        Produto *p;
        p = C->prod_fim;
        while (p != NULL) {
            printf("O vencedor do produto \"%s\" é \"%s\"! Comprado por R$ %f\n",p->nome_prod, p->lance_high->pessoa,p->lance_high->prox_lance);
            p = p->ant_prod;
        }
    }
}

void main(void){
    printf("Suas opcoes sao:\n");
    printf("0) encerrar o programa\n");
    printf("1) cadastrar um produto\n");
    printf("2) listar produtos e lances\n");
    printf("3) dar um lance\n");
    /*
    printf("4) listar outros produtos para lances\n");
    */
    printf("5) encerrar leilao\n");
    

    Catalogo *leilao = NovoCatalogo();

    for(;;) {
        int entrada;
        printf("\nO que deseja fazer?\n");
        scanf("%d", &entrada);
        printf("\n");

        if (entrada == 0) {
            for (;;) {
                char saida;
                printf("Tem certeza que deseja encerrar o programa? (y / n) ");
                scanf(" %c", &saida);
                if (saida == 'y') {
                    goto LEAVE;
                }
                else if (saida == 'n') {
                    goto KEEP;
                }
            }
            LEAVE: printf("Programa encerrado!\n"); break;
            KEEP: printf("\n");
        }

        else if (entrada == 1) {
            char nome_produto[50];
            printf("Insira o nome do produto: ");
            scanf(" %s", &nome_produto);

            float valor_min;
            printf("Insira o valor de lance inicial (valor minimo): ");
            scanf("%f", &valor_min);
            
            CadastrarProduto(leilao, nome_produto, valor_min);
            printf("Produto cadastrado!\n");

            /*
            CadastrarProduto(leilao, "aaa", 1);
            CadastrarProduto(leilao, "bbb", 2);
            CadastrarProduto(leilao, "ccc", 3);
            CadastrarProduto(leilao, "ddd", 4);

            printf("Produtos cadastrados!\n");
            */
        }

        else if (entrada == 2) {
            PrintarProdutos(leilao);
        }

        else if (entrada == 3) {
            char nome_do_produto[50];
            printf("Qual produto ?: ");
            scanf(" %s", &nome_do_produto);

            char nome_pessoa[50];
            printf("Insira seu nome: ");
            scanf(" %s", &nome_pessoa);

            float valor_de_lance;
            printf("Qual valor a ser lancado ?: ");
            scanf("%f", &valor_de_lance);

            int erro; 
            Produto *prod;
            prod = leilao->prod_fim;
            for (;;) {
                if (prod == NULL) {
                    erro = 1;
                    break;
                }
                else if (prod->nome_prod == nome_do_produto) {
                    NovoLance(prod, nome_pessoa, valor_de_lance, erro);
                    break;
                }
                else {
                    erro = 2;
                    break;
                }
                prod = prod->ant_prod;
            }
            
            if (erro == 0) {
                printf("Lance efetuado!\n");
            }
            else if (erro == 3) {
                printf("Seu lance foi invalido!");
                printf(" O valor lancado deve ser maior o minimo requisitado");
                printf(" ou maior que o valor do ultimo lance.\n");
            }
            else if (erro == 1) {
                printf("\nProduto inexistente! Verifique a ortografia\n.");
            }
        }
        
        else if (entrada == 5) {
            EncerrarCatalogo(leilao);
            break;
        }
        else {
            printf("Opcao invalida!\n\n");
        }
    }
};
