#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h>  /* printf */
#include <string.h>
#include "usuario.h"

/*Criar lista de usuarios*/
Usuarios* criar_usuarios_lista()
{
    /*Aloca memoria para a lista*/
    Usuarios *usuarios = (Usuarios*) malloc(sizeof(Usuarios));
    usuarios->primeiro = NULL;
    usuarios->retirar = NULL;
    return usuarios;
}

/*Inserir usuario na lista*/
void inserir_usuario(Usuarios* users, char *nome){

    /*Aloca memoria para o novo no*/
    No *no = (No*) malloc(sizeof(No));
    strcpy(no->nome, nome);

    /*Se a lista estiver vazia*/
    if(users->primeiro == NULL){
        users->primeiro = no;
        users->retirar = no;
        users->primeiro->prox = NULL;
    }
    else{
        /*Se nao estiver vazia, insere no final*/
        No *aux = users->primeiro;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
        no->prox = NULL;
    }

}

/*Retirar usuario da lista*/
char* retirar_usuario(Usuarios* users){
    
    if(users->retirar == NULL){
        /*Se a lista estiver vazia*/
        return 0;
    }
    else{
        /*Se nao estiver vazia, retira o primeiro*/
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