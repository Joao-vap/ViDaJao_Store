#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */
#include <string.h>
#include "produto.h"
#include "catalogo.h"
#include "main_fake.h"

int main_fake(void){

    Catalogo *L = NovoCatalogo();

    /*PrintarProdutos(L); primeiro print*/

    CadastrarProduto(L, "CCC", 1);

    CadastrarProduto(L, "BBB", 2);

    PrintarProdutos(L);
    
    /*PrintarProdutos(L); teste do segundo print*/

    int erro;
    Prateleira *pr;
    pr = L->prat_ini;
    
    NovoLance(pr->produto, "comprador 1", 0.5, erro);   
    NovoLance(pr->produto, "comprador 2", 2, erro); 
    NovoLance(pr->produto, "comprador 3", 1, erro);  
    NovoLance(pr->produto, "comprador 4", 3, erro);  

    PrintarProdutos(L);

    pr = pr->prox;
    NovoLance(pr->produto, "comprador 1", 1.9, erro);   
    NovoLance(pr->produto, "comprador 2", 2, erro); 
    NovoLance(pr->produto, "comprador 3", 5, erro);  
    NovoLance(pr->produto, "comprador 4", 4, erro);  
    
    PrintarProdutos(L);

    CadastrarProduto(L, "AAA", 3);

    PrintarProdutos(L);

    pr = pr->prox;
    NovoLance(pr->produto, "comprador 1", 3, erro);   
    NovoLance(pr->produto, "comprador 2", 4, erro); 
    NovoLance(pr->produto, "comprador 3", 5, erro);  
    NovoLance(pr->produto, "comprador 4", 6, erro);  
    
    PrintarProdutos(L);


    PrintarProdutos(L);
    EncerrarCatalogo(L);

    return 0;
}
