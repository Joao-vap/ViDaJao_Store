#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h>  /* printf */
#include <string.h>
#include "usuario.h"

Usuarios* criar_usuarios_lista()
{
    Usuarios *usuarios = (Usuarios*) malloc(sizeof(Usuarios));
    usuarios->primeiro = NULL;
    usuarios->retirar = NULL;
    return usuarios;
}

void inserir_usuario(Usuarios* users, char *nome){

    No *no = (No*) malloc(sizeof(No));
    strcpy(no->nome, nome);

    if(users->primeiro == NULL){
        users->primeiro = no;
        users->retirar = no;
        users->primeiro->prox = NULL;
    }
    else{
        No *aux = users->primeiro;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
        no->prox = NULL;
    }

}

char* retirar_usuario(Usuarios* users){
    
    if(users->retirar == NULL){
        return 0;
    }
    else{
        No *aux = users->retirar;
        if (users->retirar->prox == NULL){
            users->retirar = users->primeiro;
        }
        else{
            users->retirar = users->retirar->prox;
        }
        return aux->nome;
    }
}