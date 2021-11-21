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
        KEEP:
            printf("%s", "\n");
            break;

        case 1:
            printf("%s", "Insira o nome do produto: ");
            char nome_produto[50];
            scanf("%s", nome_produto);
            //testar-> char *nome_produto = (char*)malloc(50*sizeof(char));


            float valor_min;
            printf("%s", "Insira o valor de lance inicial (valor minimo): ");
            scanf("%f", &valor_min);

            CadastrarProduto(leilao, nome_produto, valor_min);
            //testar-> free(nome_produto);

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

            if (ProcurarProduto(leilao, nome_do_produto) == NULL)
            {
                printf("%s", "Produto nao encontrado.\n");
                break;
            }
 
            int status;
            /*0-> tudo certo    1->valor abaixo do lance atua   2->valor abaixo do minimo*/
            status = NovoLance(ProcurarProduto(leilao, nome_do_produto), nome_pessoa, valor_de_lance);

            if (status == 0)
            {
                printf("%s", "Lance efetuado!.\n");
            }
            else if (status == 1)
            {
                printf("%s", "Valor de lance abaixo do lance atual.\n");
            }
            else if (status == 2)
            {
                printf("%s", "Valor de lance abaixo do minimo.\n");
            }

            break;

        case 4:
            EncerrarCatalogo(leilao);
            return 0;

        default:
            printf("%s", "Opcao invalida.\n");
        }
    }
}

