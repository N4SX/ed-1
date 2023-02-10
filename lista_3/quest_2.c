#include <stdio.h>
#include <stdlib.h>

#define TAM 5 // definindo o tamanho fixo para 5

void imprimeVetor(int* V,int meio){ // Nossa função imprimir vetor V de tamanho 5
    
    printf(" %d\n",V[meio]); // vamos printar esse o meio desse vetor V, no caso 3 pois fica entre 2 e 4 
    
    for(int i = 1; i <= meio; i++){ // Este laço esta fazendo a verificação dos valores da variavel meio
        printf("%d %d\n",V[meio - i],V[meio + i]); // sendo que primeiro vamos fazer os incrementos e decrementos de 3 
    }

} // no caso meio -i e meio + i

void main(){ // Entramos na nossa função principal 
    
    int *V, meio; // temos a declaração das nossas variaveis , sendo V com tamanho 5 de 1 a 5 e nosso meio que pega 3
    
    V = (int*) malloc((TAM) * sizeof(int)); // o ponteiro V está alocado dinamicamente usando
    
    for(int i = 0; i < TAM; i++){ // preenchimento do nosso vetor com o tamanho definido TAM no caso de 1 até 5
        V[i] = i + 1;
    }

    meio = TAM / 2; // recebe o tamanho definido TAM que é 5 dividido por 2

    if(TAM % 2 != 0){ // caso a condição seja verdadeira no caso 5 que éo valor impar do nosso vetor V , vai ser imprimido o V completo começando pelo seu meio
        imprimeVetor(V,meio);
    }
    else{
        printf("Vetor nao e impar!"); // caso a condição do nosso vetor TAM não seja impar ele vai imprimir a seguinte mensagem
    }
    free(V); // Já no final temos nosso free que limpa nossa memoria alocada do nosso Vetor V
}