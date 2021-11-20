/*cada nó do catálogo é uma 'prateleira'*/
typedef struct prat {
    Produto *produto;
    struct prat *prox,*ant;
} Prateleira;

/*o catalogo mantém um nó inicial e final das prateleiras em estoque*/
typedef struct catalogo{
    Prateleira *prat_fim, *prat_ini;
} Catalogo;

/*cria um catalogo*/
Catalogo* NovoCatalogo(void);

/*cria uma nova prateleira com produto no catálogo*/
void CadastrarProduto(Catalogo *C, char *nome_produt, float valor_min);

/*escreve os produtos no catálogo*/
void PrintarProdutos(Catalogo *C);

/*encerra o catálogo*/
void EncerrarCatalogo(Catalogo *C);