#include <stdio.h.>
#include <stdlib.h>
#include <time.h>

#define MAX 10000;

int menor = MAX;
int intervalo;

void preencherMatriz(int** Matriz, int colunas, int linhas){

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            Matriz[i][j] = 1 + rand() % MAX;
        }
    }
}

void imprimeMatriz(int** Matriz, int colunas, int linhas){

    for(int i = 0; i < linhas; i++){ 

        for(int j = 0; j < colunas; j++){
            printf("%d ",Matriz[i][j]); 
        }
        printf("\n");
    }
    printf("\n\n");
}

int *ocorrencias(int **mat, int l, int c){

    int cont = 0, maior = 0;

    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){

            if(mat[i][j] > maior){
                maior = mat[i][j];
            }

            if(mat[i][j] < menor){
                menor = mat[i][j];
            }
        }
    }

    intervalo = maior - menor;
    intervalo++;

    int *vetor = (int*) malloc((intervalo) * sizeof(int));
    
    for(int i = 0; i < intervalo; i++){
        for(int j = 0; j < l; j++){
            for(int k = 0; k < c; k++){

                if((menor + i) == mat[j][k]){
                    cont++;
                }
            }
        }

        vetor[i] = cont;
        cont = 0;
    }
    return vetor;
}

void main(){
    
    srand(time(NULL));

    int coluna, linha, *vetor;

    printf("Informe a quantidade de Colunas da Matrizes:");
    scanf("%d",&coluna);

    printf("Informe a quantidade de Linhas da Matrizes:");
    scanf("%d",&linha);

    system("cls");

    int **Matriz = (int**) malloc((linha) * sizeof(int*));

    for(int i = 0; i < linha; i++){
        Matriz[i] = (int*) malloc((coluna) * sizeof(int));
    }

    preencherMatriz(Matriz, coluna, linha);

    imprimeMatriz(Matriz, coluna, linha);
    vetor = ocorrencias(Matriz, linha, coluna);

    for(int i = 0; i < intervalo; i++){

        printf("Valor %d ocorrencias %d\n", menor+i, vetor[i]);
    }
    free(vetor);
}