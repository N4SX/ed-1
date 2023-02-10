#include <stdio.h.>
#include <stdlib.h>
#include <string.h>

#define TAM 100

int* repeteLetra(char* string, char letra, int* tamanho){

    int *vetor = (int*) malloc((1) * sizeof(int));
    int cont = 0;

    for(int i = 0; string[i] != '\0'; i++){

        if(string[i] == letra){

            vetor[cont] = i;
            cont++;
            vetor = (int*) realloc(vetor,(cont + 1) * sizeof(int));
        }
    }
    *tamanho = cont;
    return vetor;
}

void main(){

    char *string, letra;
    int tamanho = 0, *indice;

    string = (char*) malloc((TAM) * sizeof(char));

    printf("Digite:");
    scanf(" %[^\n]s", string);

    printf("Letra:");
    scanf(" %c",&letra);

    indice = repeteLetra(string, letra, &tamanho);

    printf("Indices:");

    for(int i = 0; i < tamanho; i++){
        printf("[%d]", indice[i]);
    }
    printf("\nTamanho do vetor:%d", tamanho);

    free(string);
}