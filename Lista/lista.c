#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

no *alocaNo(int valor){
    no *novoNo = (no*)malloc(sizeof(no));
    novoNo->valor = valor;
    novoNo->prox = NULL;
    return novoNo;
}

void insereNo(no *ptlista,no *noInserido){
    no *aux = ptlista->prox;

    while(aux->prox != NULL){
        aux = aux->prox;
    }

    aux->prox = noInserido;
}

void removeNo(no *ptlista, int valor){
    no *aux = ptlista->prox;
    
    while(aux != NULL || ){

    }
}


int main(){

    return 0;
}