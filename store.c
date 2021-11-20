#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */
#include <string.h>
#include "lance.h"
#include "produto.h"
#include "catalogo.h"
#include "users.h"

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