/*Estrutura para o lance dado em um produto*/
typedef struct info {
    char nome;
    float valor;
} Info;

/*Estrutura para a lista de lances de um produto*/
typedef struct lance {
    Info *info;
    struct lance *prox_lance, *ant_lance;
} Lance;

/*Estrutura para o produto*/
typedef struct produto {
    char nome_prod;
    int valor_min;
    Lance *maior_lance, *menor_lance;
} Produto;

/*Cria um novo produto*/
Produto* NovoProduto(char nome_produto, float valor_min);

/*Cria um novo lance no produto, inserção em ordem de grandeza (menor->maior)*/
void NovoLance(Produto *P, char pessoa, float valor_lancado, int *erro);

/*Escreve os lances de um produto*/
void PrintarLances(Produto *P);