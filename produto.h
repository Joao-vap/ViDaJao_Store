/*Estrutura para o lance dado em um produto*/
typedef struct inf {
    char *nome;
    float valor;
} Info;

/*Estrutura para a lista de lances de um produto*/
typedef struct lan {
    Info *info;
    struct lan *prox_lance, *ant_lance;
} Lance;

/*Estrutura para o produto*/
typedef struct prod {
    char *nome_prod;
    int valor_min;
    Lance *maior_lance, *menor_lance;
} Produto;

/*Cria um novo produto*/
Produto* NovoProduto(char *nome_produto, float valor_min);

/*Cria um novo lance no produto, inserção em ordem de grandeza (menor->maior)*/
void NovoLance(Produto *P, char *pessoa, float valor_lancado, int erro);

/*Escreve os lances de um produto*/
void PrintarLances(Produto *P);