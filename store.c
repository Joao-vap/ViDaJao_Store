#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h>  /* printf */
#include <string.h>
#include "produto.h"
#include "catalogo.h"
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
        entrada = PrintarOpcoes();
        PrintarOpcaoSelecionada(entrada);

        /*Verificação da opção do usuário*/
        switch (entrada)
        {
        case 1:
            /*Cadastrar um produto*/

            /*Ler o nome do produto*/
            printf("                                                                                 Insira o nome do produto: ");
            char nome_produto[50];
            scanf("%s", nome_produto);

            /*Ler o preço do produto*/
            printf("                                                                        Insira o valor de lance inicial (valor minimo): ");
            float valor_min;
            scanf("%f", &valor_min);

            /*Cadastrar o produto*/
            CadastrarProduto(leilao, nome_produto, valor_min);

            break;

        case 2:
            /*printar produtos e lances*/
            PrintarProdutos(leilao);
            break;


        case 3:
            /*cadastrar um lance*/
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
                PrintarProdInexistente();
                break;
            }
    
            int status;
            /*0-> tudo certo    1->valor abaixo do lance atua   2->valor abaixo do minimo*/
            status = NovoLance(ProcurarProduto(leilao, nome_do_produto), nome_pessoa, valor_de_lance);

            if (status == 0)
            {
                PrintarLanceEfetuado();
            }
            else if (status == 1)
            {
                PrintarLanceAbaixoAtual();
            }
            else if (status == 2)
            {
                PrintarLanceAbaixoMinimo();
            }
            break;

        case 4:
            /*sugerir produtos*/
            SugerirProduto(leilao);
            break;

        case 5:
            /*remover um produto*/
            printf("                                                                                Qual Produto Deseja remover?: ");
            char produto[50];
            scanf("%s", produto);

            RemoverProduto(leilao, produto);
            break;

        case 6:
            printf("                                                                                Qual Produto Deseja Visualizar?: ");
            char nome_do_prod[50];
            scanf("%s",nome_do_prod);
            Produto *p;
            p = ProcurarProduto(leilao, nome_do_prod);
            if (p == NULL){
                PrintarProdInexistente();
            }
            else{
                PrintarLances(p);
            }

        case 7:
            /*encerrar o leilao*/
            EncerrarCatalogo(leilao);
            return 0;

        default:;
            
        }
    }
}

