/*tipo exportado*/
typedef struct catalogo{
    Produto *prod_fim;
    Produto *prod_ini;
} Catalogo;

void EncerrarCatalogo(Catalogo *C);

void PrintarProdutos(Catalogo *C);

void CadastrarProduto(Catalogo *C, char *nome_produt, float valor_min);

Catalogo* NovoCatalogo(void);