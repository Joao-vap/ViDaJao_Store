#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */
#include <string.h>
#include "lance.h"
#include "produto.h"
#include "catalogo.h"
#include "users.h"
#include "main_fake.h"

int main_fake(void){
    Catalogo *L = NovoCatalogo();

    CadastrarProduto(L, "Kit Arduino Pro+", 50);

    CadastrarProduto(L, "Kit Arduino Starter", 120);
    
    int erro;
    Produto *p;
    p = L->prod_ini;
    NovoLance(p,"vitor",1000,erro);
    NovoLance(p,"camila",1099,erro);

    p = p->prox_prod;
    NovoLance(p,"davi",799,erro);
    NovoLance(p,"joao",800,erro);

    CadastrarProduto(L, "Kit RaspberryPi 3.0", 450);

    p = p->prox_prod;
    NovoLance(p,"ale",3099,erro);
    NovoLance(p,"nic",3000,erro);
    NovoLance(p,"igor",3100,erro);

    p = p->ant_prod;
    NovoLance(p,"yuk",850,erro);

    p = p->ant_prod;
    NovoLance(p,"him",1200,erro);
    NovoLance(p,"beto",1500,erro);

    p = p->prox_prod->prox_prod;
    NovoLance(p,"sr.tiao",4000,erro);

    PrintarProdutos(L);

    EncerrarCatalogo(L);
}