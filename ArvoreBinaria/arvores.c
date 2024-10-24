#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

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
    }else if(noInserido->valor < raiz->valor){//caso o valor seja menor anda para esquerda na arvore
        raiz->esq = insereNo(raiz->esq, noInserido);
    }else if(noInserido->valor > raiz->valor){//caso valor for maior anda para direita na arvore
        raiz->dir= insereNo(raiz->dir,noInserido);
    }
    return raiz; //se não for possivel inserir (o valor ja existe) retornamos o proprio valor
}

void liberaNo(no *raiz){
    free(raiz);
}

void preOrdem(no *raiz){
    if(raiz != NULL){
        printf("\n%d",raiz->valor); //exibe o valor do no atual
        preOrdem(raiz->esq); //anda para esquerda na arvore
        preOrdem(raiz->dir); //anda para direita na arvore
    }
}

void emOrdem(no *raiz){
    if(raiz != NULL){
        emOrdem(raiz->esq); //anda para esquerda na arvore
        printf("\n%d",raiz->valor); //exibe o valor do no atual
        emOrdem(raiz->dir); //anda para direita na arvore
    }
}

void posOrdem(no *raiz){
    if(raiz != NULL){
        posOrdem(raiz->esq); //anda para esquerda na arvore
        posOrdem(raiz->dir); //anda para direita na arvore
        liberaNo(raiz); //libera o nó
    }
}

bool busca(no *raiz, int valor){
    if(raiz == NULL) return false; //caso não encontre o valor
    if(raiz->valor == valor) return true; //se o valor que estamos procuramos está na arvore retornamos verdadeiro
    if(raiz->valor < valor) return busca(raiz->dir, valor); //se o valor for maior procuramos pra direita
    return busca (raiz->esq, valor); //se o valor for menor procuramos pela esquerda
}

int main(){
    no *raiz = NULL; //inicia a raiz da arvore como nulo para a primeira inserção estar correta
    int contador = 10; //contador de quantos elementos seram inseridos na arvore
    
    for(int i = 0; i < contador; i++){
        raiz = insereNo(raiz, alocaNo(i+1)); // insere o nó na arvore de 1 a 10
    }
    
    printf("Buscando 5: %s\n", busca(raiz, 5) ? "TRUE" : "FALSE");// procuramos o valor 5 na arvore (deve retornar true)
    printf("Buscando 20: %s\n", busca(raiz, 20) ? "TRUE" : "FALSE");//procuramos o valor 20 na arvore (deve retornar false)
    
    printf("\nPercurso em pré-ordem:\n");
    preOrdem(raiz);

    printf("\nPercurso em ordem:\n");
    emOrdem(raiz);

    posOrdem(raiz); // função para liberar todos os nós na arvore
    raiz = NULL;

    return 0;
}