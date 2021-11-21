#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h>  /* printf */
#include <string.h>
#include "produto.h"
#include "catalogo.h"

int main(void)
{

    printf("%s", "Suas opcoes sao:\n");
    printf("%s", "0) encerrar o programa\n");
    printf("%s", "1) cadastrar um produto\n");
    printf("%s", "2) listar produtos e lances\n");
    printf("%s", "3) dar um lance\n");
    printf("%s", "4) encerrar leilao\n");

    Catalogo *leilao = NovoCatalogo();

    for (;;)
    {
        int entrada;
        printf("%s", "\nO que deseja fazer?\n");
        scanf("%d", &entrada);
        printf("%s", "\n");

        switch (entrada)
        {
        case 0:
            for (;;)
            {
                char saida;
                printf("%s", "Tem certeza que deseja encerrar o programa? (y / n) ");
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
            EncerrarCatalogo(leilao);
            exit(0);
            break;
        KEEP:
            printf("%s", "\n");
            break;

        case 1:
            printf("%s", "Insira o nome do produto: ");
            char nome_produto[50];
            scanf("%s", nome_produto);

            float valor_min;
            printf("%s", "Insira o valor de lance inicial (valor minimo): ");
            scanf("%f", &valor_min);

            CadastrarProduto(leilao, nome_produto, valor_min);

            printf("%s", "Produto cadastrado!\n");
            break;

        case 2:
            PrintarProdutos(leilao);
            break;

        case 3:
            printf("%s", "Qual produto ?: ");
            char nome_do_produto[50];
            scanf("%s", nome_do_produto);

            printf("%s", "Qual valor a ser lancado ?: ");
            float valor_de_lance;
            scanf("%f", &valor_de_lance);

            printf("%s", "Insira seu nome: ");
            char nome_pessoa[50];
            scanf("%s", nome_pessoa);

            int erro;
            Prateleira *prat;

            prat = leilao->prat_ini;
            
            for (;;)
            {
                if (prat == NULL)
                {
                    erro = 1;
                    goto ERROS_LANCE;
                    break;
                }
                else if (strcmp(prat->produto->nome_prod, nome_do_produto))
                {
                    goto LANCAR;
                }
                else
                {
                    erro = 2;
                    goto ERROS_LANCE;
                }

                prat = prat->prox;

            }

            LANCAR:
                NovoLance(prat->produto, nome_pessoa, valor_de_lance, erro);

            ERROS_LANCE:;
                // if (erro == 0)
                // {
                //     printf("%s", "Lance efetuado!\n");
                // }
                // else if (erro == 3)
                // {
                //     printf("%s", "Seu lance foi invalido!");
                //     printf("%s", " O valor lancado deve ser maior o minimo requisitado");
                //     printf("%s", " ou maior que o valor do ultimo lance.\n");
                // }
                if (erro == 1)
                {
                    printf("%s", "Produto inexistente!\n");
                }
                else if (erro == 2)
                {
                    printf("%s", "Erro de lancamento. Tente novamente.\n");
                }
                else
                {
                    printf("%s", "Lance efetuado!\n");
                }
            break;

        case 4:
            EncerrarCatalogo(leilao);
            break;

        default:
            printf("%s", "Opcao invalida.\n");
        }
    }
}

