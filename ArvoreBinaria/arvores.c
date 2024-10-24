#include <stdio.h>
#include <stdlib.h>

//Como se trata de uma arvore binaria comum não precisamos de altura já que ela não possui balanceamento
typedef struct noArvore{
    int valor; //Valor inteiro a ser inserido
    struct noArvore *esq, *dir; //ponteiros para filhos a esquerda e direita 
}no;

no *alocaNo(int valor){ //Passamos o valor inteiro a ser inserido na memoria
    no *novoNo = (no*)malloc(sizeof(no)); //Aloca o novo nó na memoria
    novoNo->valor = valor; //inserimos o inteiro no struct
    novoNo->esq = NULL; //apontamos esquerda como nulo pois esse nó ainda n tem filho
    novoNo->dir = NULL; //apontamos direita como nulo pois esse nó ainda n tem filho

    return novoNo; //retornamos o endereço do nó que acaba de ser alocado
}

no *insereNo(no *raiz, no *noInserido){
    if(raiz == NULL){ //se a raiz for nula encontramos o local para inserir o nó
        return noInserido; //retornamos o nó que vai ser inserido na arvore
    }else if(raiz->valor < noInserido->valor){//caso o valor seja menor anda para esquerda na arvore
        return insereNo(raiz->dir,noInserido);
    }else if(raiz->valor > noInserido->valor){//caso valor for maior anda para direita na arvore
        return insereNo(raiz->esq, noInserido);
    }
    return raiz; //se não for possivel inserir (o valor ja existe) retornamos o proprio valor
}

void preOrdem(no *raiz){
    //função ou ação 
    if(raiz->esq != NULL) return raiz->esq; //anda para esquerda na arvore
    if(raiz->dir != NULL) return raiz->dir; //anda para direita na arvore
}

void emOrdem(no *raiz){
    if(raiz->esq != NULL) return raiz->esq; //anda para esquerda na arvore
    //função ou ação 
    if(raiz->dir != NULL) return raiz->dir; //anda para direita na arvore
    
}

void posOrdem(no *raiz){
    if(raiz->esq != NULL) return raiz->esq; //anda para esquerda na arvore
    if(raiz->dir != NULL) return raiz->dir; //anda para direita na arvore
    free(raiz);
}



int main(){
    no *raiz = NULL; //inicia a raiz da arvore como nulo para a primeira inserção estar correta
    int contador = 10; //contador de quantos elementos seram inseridos na arvore
    
    for(int i = 0; i < contador; i++){
        raiz = insereNo(raiz, alocaNo(i+1)); // insere o nó na arvore de 1 a 10
    }
    
    posOrdem(raiz); // função para liberar todos os nós na arvore
    raiz = NULL;

    return 0;
}