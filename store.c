#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h>  /* printf */
#include <string.h>
#include "produto.h"
#include "catalogo.h"

int main(void)
{

    printf("Suas opcoes sao:\n");
    printf("0) encerrar o programa\n");
    printf("1) cadastrar um produto\n");
    printf("2) listar produtos e lances\n");
    printf("3) dar um lance\n");
    printf("4) encerrar leilao\n");

    Catalogo *leilao = NovoCatalogo();

    for (;;)
    {
        int entrada;
        printf("\nO que deseja fazer?\n");
        scanf("%d", &entrada);
        printf("\n");

        if (entrada == 0)
        {
            for (;;)
            {
                char saida;
                printf("Tem certeza que deseja encerrar o programa? (y / n) ");
                scanf("%c", &saida);
                if (saida == 'y')
                {
                    goto LEAVE;
                }
                else if (saida == 'n')
                {
                    goto KEEP;
                }
            }
        LEAVE:
            printf("Programa encerrado!\n");
            break;
        KEEP:
            printf("\n");
        }

        else if (entrada == 1)
        {
            printf("Insira o nome do produto: ");
            char nome_produto[50];
            scanf("%s", nome_produto);

            float valor_min;
            printf("Insira o valor de lance inicial (valor minimo): ");
            scanf("%f", &valor_min);

            CadastrarProduto(leilao, nome_produto, valor_min);
            printf("Produto cadastrado!\n");
        }

        else if (entrada == 2)
        {
            PrintarProdutos(leilao);
        }

        else if (entrada == 3)
        {
            printf("Qual produto ?: ");
            char nome_do_produto[50];
            scanf("%s", nome_do_produto);

            printf("Insira seu nome: ");
            char nome_pessoa[50];
            scanf("%s", nome_pessoa);

            printf("Qual valor a ser lancado ?: ");
            float valor_de_lance;
            scanf("%f", &valor_de_lance);

            int erro;
            Prateleira *prod;
            prod = leilao->prat_ini;
            printf("nomes: %s e %s\n", prod->produto->nome_prod, nome_do_produto);
            for (;;)
            {
                if (prod == NULL)
                {
                    erro = 1;
                    goto ERROS_LANCE;
                    break;
                }
                else if (strcmp(prod->produto->nome_prod, nome_do_produto))
                {
                    goto LANCAR;
                }
                else
                {
                    erro = 2;
                    goto ERROS_LANCE;
                }
                prod = prod->prox;
            }
        LANCAR:
            NovoLance(prod->produto, nome_pessoa, valor_de_lance, erro);
        ERROS_LANCE:;
            if (erro == 0)
            {
                printf("Lance efetuado!\n");
            }
            else if (erro == 3)
            {
                printf("Seu lance foi invalido!");
                printf(" O valor lancado deve ser maior o minimo requisitado");
                printf(" ou maior que o valor do ultimo lance.\n");
            }
            else if (erro == 1)
            {
                printf("Produto inexistente!\n");
            }
            else if (erro == 2)
            {
                printf("Erro de lancamento. Tente novamente.\n");
            }
        }

        else if (entrada == 4)
        {
            EncerrarCatalogo(leilao);
            break;
        }

        else if (entrada == 7)
        {
            char vento[50];
            printf("insira uma palavra\n");
            scanf("%s", vento);

            char ar[50];
            printf("insira uma palavra\n");
            scanf("%s", ar);

            printf("suas palavras: %s %s %i\n", vento, ar, strcmp(vento, ar));
        }
        else
        {
            printf("Opcao invalida!\n\n");
        }
    }
    return 0;
}
