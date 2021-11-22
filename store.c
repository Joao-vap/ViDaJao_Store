#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h>  /* printf */
#include <string.h>
#include "produto.h"
#include "catalogo.h"
#include "usuario.h"
#include "funcAux.h"


int main(void)
{
    /*Header de boas vindas*/
    Header();

    /*Criação do catalogo*/
    Catalogo *leilao = NovoCatalogo();

    /*loop principal*/
    for (;;)
    {

        /*Ler a opção do usuário*/
        int entrada;
        
        /*Opções de ação na loja*/
        printf("\n\n");
        entrada = PrintarOpcoes();

        /*Verificação da opção do usuário*/
        switch (entrada)
        {
        case 1:
            /*Cadastrar um produto*/

            /*Ler o nome do produto*/
            printf("                     =                                                       Opcao Selecionada: Cadastrar um Produto                                                                 =\n");
            printf("                     =---------------------------------------------------------------------------------------------------------------------------------------------------------------=\n");
            printf("                                                                                 Insira o nome do produto: ");
            char nome_produto[50];
            scanf("%s", nome_produto);

            /*Ler o preço do produto*/
            printf("                                                                        Insira o valor de lance inicial (valor minimo): ");
            float valor_min;
            scanf("%f", &valor_min);

            /*Cadastrar o produto*/
            CadastrarProduto(leilao, nome_produto, valor_min);
            printf("                     =================================================================================================================================================================\n");

            break;

        case 2:
            /*printar produtos e lances*/
            PrintarProdutos(leilao);
            break;


        case 3:
            /*cadastrar um lance*/
            printf("                     =                                                            Opcao Selecionada: Dar um Lance                                                                    =\n");
            printf("                     =---------------------------------------------------------------------------------------------------------------------------------------------------------------=\n");
            printf("                                                                                          Qual produto ?: ");
            char nome_do_produto[50];
            scanf("%s", nome_do_produto);

            printf("                                                                                 Qual valor a ser lancado ?: ");
            float valor_de_lance;
            scanf("%f", &valor_de_lance);

            printf("                                                                                        Insira seu nome: ");
            char nome_pessoa[50];
            scanf("%s", nome_pessoa);

            if (ProcurarProduto(leilao, nome_do_produto) == NULL)
            {
                printf("                     =                                                                 Produto nao encontrado!                                                                       =\n");
                break;
            }
    
            int status;
            /*0-> tudo certo    1->valor abaixo do lance atua   2->valor abaixo do minimo*/
            status = NovoLance(ProcurarProduto(leilao, nome_do_produto), nome_pessoa, valor_de_lance);

            if (status == 0)
            {
                printf("                                                                                         Lance efetuado!                                                                             =\n");
            }
            else if (status == 1)
            {
                printf("                                                                             Valor de lance abaixo do lance atual!                                                                   =\n");
            }
            else if (status == 2)
            {
                printf(                     "=                                                        Valor de lance abaixo do minimo!                                                                       =\n");
            }
            printf("                     =================================================================================================================================================================\n");
            break;

        case 4:
            /*sugerir produtos*/
            SugerirProduto(leilao);
            break;

        case 5:
            /*remover um produto*/
            printf("                     =                                                         Opcao Selecionada: Remover um Produto                                                                 =\n");
            printf("                     =---------------------------------------------------------------------------------------------------------------------------------------------------------------=\n");
            printf("                                                                                Qual Produto Deseja remover?: ");
            char produto[50];
            scanf("%s", produto);

            RemoverProduto(leilao, produto);
            printf("                     =================================================================================================================================================================\n");
            break;

        case 6:
            /*encerrar o leilao*/
            EncerrarCatalogo(leilao);
            return 0;

        case 7: ;
            char nome_do_prod[50];
            Produto* p;
            p = ProcurarProduto(leilao, nome_do_prod);
            // if (p == NULL){
            //     printf("");
            // }
            // else{

            // }

        default:
            printf("                     =                                                                        Opcao invalida!                                                                        =\n");
            printf("                     =================================================================================================================================================================\n");
        }
    }
}

