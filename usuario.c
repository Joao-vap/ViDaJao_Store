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

void inserir_usuario(Usuarios* user, char *nome){

    No *no = (No*) malloc(sizeof(No));
    strcpy(no->nome, nome);

    if(user->primeiro == NULL){
        user->primeiro = no;
        user->retirar = no;
        user->primeiro->prox = NULL;
    }
    else{
        No *aux = user->primeiro;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
        no->prox = NULL;
    }

}

char* retirar_usuario(Usuarios* user){
    
    if(user->retirar == NULL){
        return 0;
    }
    else{
        No *aux = user->retirar;
        if (user->retirar->prox == NULL){
            user->retirar = user->primeiro;
        }
        else{
            user->retirar = user->retirar->prox;
        }
        return aux->nome;
    }
}