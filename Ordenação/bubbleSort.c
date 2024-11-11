#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n){
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        // Se não houve a troca de elementos
        if (!swapped)
            break;
    }
}

int main(){
    int escolha;
    printf("\nCaso 1: vetor previamente preechindo\n");
    printf("Caso 2: preencher vetor manualmente\n");
    printf("\nEscolha: ");
    scanf("%d",&escolha);
    printf("\n");

    switch(escolha){
        case 1:
            int vet[10] = {1,3,2,4,7,5,8,6,10,9};
            int tamanho = sizeof(vet) / sizeof(vet[0]);

            printf("\nVetor atual: ");
            for(int i = 0; i < tamanho; i++){
                printf("%d ",vet[i]);
            }
            printf("\n");

            bubbleSort(vet, tamanho);

            printf("\nVetor ordenado: ");
            for(int i = 0; i < tamanho; i++){
                printf("%d ",vet[i]);
            }
            printf("\n");
        break;

        case 2:
            int n;
            int *v;
            printf("Insira o tamanho do vetor desejado: ");
            scanf("%d", &n);

            v = (int*)malloc(n * sizeof(int));

            for(int i = 0; i < n; i++){
                printf("Insira o valor da posicao %d do vetor: ",i);
                scanf("%d",&v[i]);
            }

            printf("\nVetor atual: ");
            for(int i = 0; i < n; i++){
                printf("%d ",v[i]);
            }
            printf("\n");

            bubbleSort(v, n);

            printf("\nVetor ordenado: ");
            for(int i = 0; i < n; i++){
                printf("%d ",v[i]);
            }
            printf("\n");

            free(v);
        break;
    }
}