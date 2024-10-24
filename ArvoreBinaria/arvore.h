#ifndef ARVORE_H
#define ARVORE_H

#include <stdbool.h>

// Definição da estrutura do nó da árvore
typedef struct noArvore {
    int valor;                // Valor inteiro a ser inserido
    struct noArvore *esq;    // Ponteiro para o filho da esquerda
    struct noArvore *dir;    // Ponteiro para o filho da direita
} no;

// Funções para manipulação da árvore
no *alocaNo(int valor);             // Aloca e inicializa um novo nó
no *insereNo(no *raiz, no *noInserido); // Insere um nó na árvore
void liberaNo(no *raiz);            // Libera a memória de um nó
void preOrdem(no *raiz);            // Percurso em pré-ordem
void emOrdem(no *raiz);             // Percurso em ordem
void posOrdem(no *raiz);            // Percurso em pós-ordem (libera a memória)
bool busca(no *raiz, int valor);     // Busca um valor na árvore

#endif // ARVORE_H
