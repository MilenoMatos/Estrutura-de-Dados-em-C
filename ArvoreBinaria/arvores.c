#include <stdio.h>
#include <stdlib.h>

typedef struct noArvore{
    int valor;
    struct noArvore *esq, *dir;
}no;

no *alocaNo(int valor){
    no *novoNo = (no*)malloc(sizeof(no));
    novoNo->valor = valor;
    novoNo->esq = NULL;
    novoNo->dir = NULL;

    return novoNo;
}

no *insereNo(no *raiz, no *noInserido){
    if(raiz == NULL){
        return raiz;
    }else if(raiz->valor < noInserido->valor){
        return insereNo(raiz, )
    }else if(raiz->valor > noInserido->valor){

    }

    return raiz;
}

int main(){

    return 0;
}