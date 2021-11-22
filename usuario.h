#pragma once /* incluir uma vez */

typedef struct no
{
    char nome[50];
    struct no *prox;
} No;

typedef struct usuario
{
    No* primeiro;
    No* retirar;
} Usuarios;

/*Criar uma lista de usuarios*/
Usuarios* criar_usuarios_lista();

/*Inserir um usuario na lista*/
void inserir_usuario(Usuarios* users, char* nome);

/*Retirar um usuario da lista (primeiro a entrar, sem retirar)*/
char* retirar_usuario(Usuarios* users); 
