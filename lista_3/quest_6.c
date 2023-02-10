#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherMatriz(int** Matriz, int colunas, int linhas){ // Nossa função preencher matrix 

    for(int i = 0; i < linhas; i++){ // Onde vamos fazer a verificação da quantidade de linhas
        for(int j = 0; j < colunas; j++){ // e do numero de colunas
            Matriz[i][j] = rand() % 10; // no caso nossa matriz tera numeros aleatorios de 0 até 9 pois o 0 conta como 1 posição
        }
    }
} // onde i são as linhas e j são as colunas

void imprimeMatriz(int** Matriz, int colunas, int linhas){ // Já aqui estamos mostrando nossas matrizes uma por uma 

    for(int i = 0; i < linhas; i++){ 

        for(int j = 0; j < colunas; j++){
            printf("%d ",Matriz[i][j]); 
        }
        printf("\n");
    }
    printf("\n\n");
}

int** soma_matriz(int** Matriz_A, int** Matriz_B, int colunas, int linhas){ //a Nova matroz vai receber a quantidade de linhas da matriz A, porém para executar tal adição a matriz resultante
 //                                                                         tem que ser do mesmo tamanho da Matriz A ou B
    int **Matriz = (int**) malloc((linhas) * sizeof(int*));

    for(int i = 0; i < linhas; i++){ // ele vai verificar as linhas alocadas
        Matriz[i] = (int*) malloc((colunas) * sizeof(int)); // vai alocar a quantidade de colunas em cada linha da matriz
    } 

    for(int i = 0; i < linhas; i++){

        for(int j = 0; j < colunas; j++){

            Matriz[i][j] = Matriz_A[i][j] + Matriz_B[i][j];// a matriz C na linha i e coluna j vai receber a soma da linha i e coluna j da matriz b
        }
    }

    return Matriz; // retornando a matriz C
}

int** subtrair_matriz(int** Matriz_A, int** Matriz_B, int colunas, int linhas){ // Neste caso temos um esquema parecido a adição

    int **Matriz = (int**) malloc((linhas) * sizeof(int*)); // Continuando a alocação das linhas e colunas

    for(int i = 0; i < linhas; i++){ 
        Matriz[i] = (int*) malloc((colunas) * sizeof(int));
    }

    for(int i = 0; i < linhas; i++){ // No caso a matriz C vai receber linha e coluna da matriz A - linha e coluna da matriz B

        for(int j = 0; j < colunas; j++){
            Matriz[i][j] = Matriz_A[i][j] - Matriz_B[i][j]; 
        }
    }

    return Matriz;
}

int** multiplicar_matriz(int** Matriz_A, int** Matriz_B, int colunas_A, int linhas_A, int colunas_B, int linhas_B){ // multiplicar as matrizes

    int **Matriz = (int**) malloc((linhas_A) * sizeof(int*)); // alocação das linhas da matriz A
    int soma = 0;

    for(int i = 0; i < colunas_B; i++){ // vai fazer a verificação das colunas de B
        Matriz[i] = (int*) malloc((colunas_B) * sizeof(int)); // E teremos tambem a alocação da coluna B
    }

    for(int i = 0; i < linhas_A; i++){ // a multiplicação de matrizes nada mais é do que sucessivas multiplicações

        for(int j = 0; j < colunas_B; j++){
            
            for(int k = 0; k < linhas_B; k++){ // a multiplicação da matriz a com a linha i e coluna B vezes a matriz B 
                soma += Matriz_A[i][k] * Matriz_B[k][j];
            }
            
            Matriz[i][j] = soma; // a soma é zerada para ser utilizada na proxima repetição
            soma = 0;
        }
    }

    return Matriz; // fazendo assim o retorno da matriz C que éo resultado
}

void main(){ // chegando em nossa função principal o nosso usário vai começar a preencher as linhas e colunas das matrizes A e B

    int coluna_A, linha_A, coluna_B, linha_B;
    srand(time(NULL));

    printf("Informe a quantidade de Colunas da Matrizes A:");
    scanf("%d",&coluna_A);

    printf("Informe a quantidade de Linhas da Matrizes A:");
    scanf("%d",&linha_A);

    printf("Informe a quantidade de Colunas da Matrizes B:");
    scanf("%d",&coluna_B);

    printf("Informe a quantidade de Linhas da Matrizes B:");
    scanf("%d",&linha_B);
    
    system("cls");

    int **Matriz_A = (int**) malloc((linha_A) * sizeof(int*)); // fazendo a alocação respectiva matriz A com a linha A
    int **Matriz_B = (int**) malloc((linha_B) * sizeof(int*)); // fazendo a alocação respectiva matriz B com a linha B
    int **Matriz_C; // ea matriz C que éo resultante das duas matrizes A e B 

    for(int i = 0; i < linha_A; i++){ // fazendo a verificação das linhas A 
        Matriz_A[i] = (int*) malloc((coluna_A) * sizeof(int)); // a matriz A na posição i com a coluna A
    }
    
    for(int i = 0; i < linha_B; i++){ // O mesmo acontece com a matriz B
        Matriz_B[i] = (int*) malloc((coluna_B) * sizeof(int));
    }

    preencherMatriz(Matriz_A, coluna_A, linha_A); // chamada da função preencher matriz
    preencherMatriz(Matriz_B, coluna_B, linha_B); // chamada da função preencher matriz

    while(1){ // enquanto for verdade a opção teremos a entrada no nosso menu

        int opcao; // Menu iterativo onde nosso usuário vai digitar o numero da opção desejada
        
        printf("1-Adicao\n");
        printf("2-subtracao\n");
        printf("3-Multiplicar\n");
        printf("0-Sair\n");
        printf("Opcao:");
        scanf("%d",&opcao);
        system("cls");
        
        if(opcao == 0){ 
            break;
        }

        switch(opcao){

            case 1:

                if(coluna_A == coluna_B && linha_A == linha_B){

                    Matriz_C = soma_matriz(Matriz_A, Matriz_B, coluna_A, linha_A);
                    imprimeMatriz(Matriz_A, coluna_A, linha_A);
                    imprimeMatriz(Matriz_B, coluna_B, linha_B);
                    imprimeMatriz(Matriz_C, coluna_A, linha_A);
                }
                else{
                    printf("Nao pode ser executador pois as Matrizes sao diferentes!\n\n");
                }
                break;

            case 2:

                if(coluna_A == coluna_B && linha_A == linha_B){
                    
                    Matriz_C = subtrair_matriz(Matriz_A, Matriz_B, coluna_B, linha_B);
                    imprimeMatriz(Matriz_A, coluna_B, linha_B);
                    imprimeMatriz(Matriz_B, coluna_B, linha_B);
                    imprimeMatriz(Matriz_C, coluna_B, linha_B);
                }
                else{
                    printf("Nao pode ser executador pois as Matrizes sao diferentes!\n\n");
                }
                break;

            case 3:

                if(coluna_A == linha_B){

                    Matriz_C = multiplicar_matriz(Matriz_A, Matriz_B, coluna_A, linha_A, coluna_B, linha_B);
                    imprimeMatriz(Matriz_A, coluna_A, linha_A);
                    imprimeMatriz(Matriz_B, coluna_B, linha_B);
                    imprimeMatriz(Matriz_C, linha_A, coluna_B);
                }
                else{
                    printf("O numero de colunas da Matriz A nao e igual ao de Linhas na Matriz B!\n\n");
                }
                break;
        }
    }
    free(Matriz_A); // e nesse final temos o desalocamento da memoria utilizada na Matriz A , B e na Matriz C que é a matriz resultante da operação das duas
    free(Matriz_B);
    free(Matriz_C);
}