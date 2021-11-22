#pragma once

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

Usuarios* criar_usuarios_lista();

void inserir_usuario(Usuarios* users, char* nome);

char* retirar_usuario(Usuarios* users); 
