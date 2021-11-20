/*tipo exportado*/
typedef struct produto {
    char *nome_prod;
    Lance *lance_high;
    float lance_min;
    struct produto *prox_prod, *ant_prod;
} Produto;

void PrintarLances(Produto *P);

void NovoLance(Produto *P, char *pessoa, float valor_lancado, int erro);

Produto* NovoProduto(char *nome_produto, float valor_min);