#include "usuario.h"

/*Estrutura para o lance dado em um produto*/
typedef struct inf {
    char nome[50];
    float valor;
} Info;

/*Estrutura para a lista de lances de um produto*/
typedef struct lan {
    Info *info;
    struct lan *prox_lance, *ant_lance;
} Lance;

/*Estrutura para o produto*/
typedef struct prod {
    char nome_prod[50];
    int valor_min;
    // Lance *maior_lance, *menor_lance;
    Lance *topo_lance;
    Usuarios *usuarios;
} Produto;

/*Cria um novo produto*/
Produto* NovoProduto(char *nome_produto, float valor_min);

/*Cria um novo lance no produto, inserção em ordem de grandeza (menor->maior)*/
int NovoLance(Produto *P, char *pessoa, float valor_lancado);

/*Escreve os lances de um produto*/
void PrintarLances(Produto *P);

int ProcurarUsuario(Produto *P, char *nome);
