/*tipo exportado*/
typedef struct produto {
    char *nome_prod;
    Lance *lance_high;
    float lance_min;
    struct produto *prox_prod, *ant_prod;
} Produto;
