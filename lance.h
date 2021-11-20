/*tipo exportado*/
typedef struct lance{
    char *pessoa;
    float valor;
    struct lance *prox_lance, *ant_lance;
    } Lance;
    