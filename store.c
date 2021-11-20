#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */
#include <string.h>
#include "lance.h"
#include "produto.h"
#include "catalogo.h"

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
    C->prod_ini = NULL;
    C->prod_fim = NULL;
    return C;
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

void SugestaoDeLances(void){
    return;
}

int main_fake(void){
    Catalogo *L = NovoCatalogo();

    CadastrarProduto(L, "Kit Arduino Pro+", 50);

    CadastrarProduto(L, "Kit Arduino Starter", 120);
    
    int erro;
    Produto *p;
    p = L->prod_ini;
    NovoLance(p,"vitor",1000,erro);
    NovoLance(p,"camila",1099,erro);

    p = p->prox_prod;
    NovoLance(p,"davi",799,erro);
    NovoLance(p,"joao",800,erro);

    CadastrarProduto(L, "Kit RaspberryPi 3.0", 450);

    p = p->prox_prod;
    NovoLance(p,"ale",3099,erro);
    NovoLance(p,"nic",3000,erro);
    NovoLance(p,"igor",3100,erro);

    p = p->ant_prod;
    NovoLance(p,"yuk",850,erro);

    p = p->ant_prod;
    NovoLance(p,"him",1200,erro);
    NovoLance(p,"beto",1500,erro);

    p = p->prox_prod->prox_prod;
    NovoLance(p,"sr.tiao",4000,erro);

    PrintarProdutos(L);

    EncerrarCatalogo(L);
}

int main_real(void){
    printf("Suas opcoes sao:\n");
    printf("0) encerrar o programa\n");
    printf("1) cadastrar um produto\n");
    printf("2) listar produtos e lances\n");
    printf("3) dar um lance\n");
    /*
    printf("4) listar outros produtos para lances\n");
    */
    printf("5) encerrar leilao\n");
    printf("7) funcao teste\n");
    

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
                scanf("%c", &saida);
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
            printf("Insira o nome do produto: ");
            char nome_produto[50];
            scanf("%s", nome_produto);
            
            float valor_min;
            printf("Insira o valor de lance inicial (valor minimo): ");
            scanf("%f", &valor_min);
            
            CadastrarProduto(leilao, nome_produto, valor_min);
            printf("Produto cadastrado!\n");
        }

        else if (entrada == 2) {
            PrintarProdutos(leilao);
        }

        else if (entrada == 3) {
            printf("Qual produto ?: ");
            char nome_do_produto[50];
            scanf("%s",nome_do_produto);

            printf("Insira seu nome: ");
            char nome_pessoa[50];
            scanf("%s",nome_pessoa);

            printf("Qual valor a ser lancado ?: ");
            float valor_de_lance;
            scanf("%f", &valor_de_lance);

            int erro; 
            Produto *prod;
            prod = leilao->prod_ini;
            printf("nomes: %s e %s\n", prod->nome_prod, nome_do_produto);
            for (;;) {
                if (prod == NULL) {
                    erro = 1;
                    goto ERROS_LANCE;
                    break;
                }
                else if (strcmp(prod->nome_prod,nome_do_produto)) {
                    goto LANCAR;
                }
                else {
                    erro = 2;
                    goto ERROS_LANCE;
                }
                prod = prod->prox_prod;
            }
            LANCAR: NovoLance(prod, nome_pessoa, valor_de_lance, erro);
            ERROS_LANCE:;
            if (erro == 0) {
                printf("Lance efetuado!\n");
            }
            else if (erro == 3) {
                printf("Seu lance foi invalido!");
                printf(" O valor lancado deve ser maior o minimo requisitado");
                printf(" ou maior que o valor do ultimo lance.\n");
            }
            else if (erro == 1) {
                printf("Produto inexistente!\n");
            }
            else if (erro == 2) {
                printf("Erro de lancamento. Tente novamente.\n");
            }
        }
        
        else if (entrada == 5) {
            EncerrarCatalogo(leilao);
            break;
        }
        else if (entrada == 7) {
            char vento[50];
            printf("insira uma palavra\n");
            scanf("%s",vento);

            char ar[50];
            printf("insira uma palavra\n");
            scanf("%s",ar);

            printf("suas palavras: %s %s %i\n", vento, ar, strcmp(vento,ar));
        }
        else {
            printf("Opcao invalida!\n\n");
        }
    }
    return 0;
}

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