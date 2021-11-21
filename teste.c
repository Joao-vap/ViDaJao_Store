#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h>  /* printf */
#include <string.h>
#include "produto.h"
#include "catalogo.h"

int main(void)
{
    Catalogo *L = NovoCatalogo();
    for (;;)
    {

        CadastrarProduto(L, "aa", 50);
        CadastrarProduto(L, "bb", 120);

        int erro;
        Prateleira *p;
        p = p->prox;

        NovoLance(p->produto, "lucas", 799);
        NovoLance(p->produto, "joao", 800);
        p = L->prat_ini;
        NovoLance(p->produto, "vitor", 1000);
        NovoLance(p->produto, "camila", 1099);

        PrintarLances(p->produto);

        p = p->prox;

        NovoLance(p->produto, "lucas", 799);
        NovoLance(p->produto, "joao", 800);

        PrintarLances(p->produto);

        CadastrarProduto(L, "Kit RaspberryPi 3.0", 450);

        // p = p->prox;
        NovoLance(p->produto, "ale", 3099);
        NovoLance(p->produto, "nic", 3000);
        NovoLance(p->produto, "igor", 3100);

        PrintarLances(p->produto);

        // p = p->ant;
        // NovoLance(p->produto,"yuk",850,erro);

        // p = p->ant;
        // NovoLance(p->produto,"him",1200,erro);
        // NovoLance(p->produto,"beto",1500,erro);

        // p = p->prox->prox;
        // NovoLance(p->produto,"sr.tiao",4000,erro);

        PrintarProdutos(L);

        // EncerrarCatalogo(L);
    }

    return 0;
}


