#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* repete(char *s, int n){ // Nossa função repete vai ser responsavel em receber as palavras com determinados tamanhos
    
    int tam_palavra = strlen(s); // a palavra vai receber determinado tamanho de string
    
    char *nova_string = (char*) malloc((tam_palavra * n) + (n - 1) * sizeof(char)); // assim vamos alocar dinamicamente, o tamanho da palavra, ea quantidade das repetiçoes da mesma
    
    strcpy(nova_string, s);
    // a variavel nova_string vai receber uma nova palavra
    for(int i = 0; i < n; i++){ // neste caso temos um laço de repetição onde vai ser responsavel pela quantidade de vezes que a palavra vai ser repetida
        
        if(i < n - 1){ // Se nao for a ultima palavra na repetição
            
            strcat(nova_string," "); // o comando strcat com a nova_string vai juntar " "
            strcat(nova_string,s); //o strcat junta mais outra vez com nova_string a palavra
        }
    }
    return nova_string; // fazendo o retorno para a variavel nova_string
}

void main(){ // Nossa função principal simplesmente vai fazer os prints ea chamadas das seguintes funções
    
    int n;
    char *string = (char*) malloc((20) * sizeof(char));
    char *nova_string;
    
    printf("Informe a palavra:"); // ler a palavra que o usuário digitou
    scanf(" %[^\n]s",string);
    
    printf("Quantas repeticoes:"); // ler a quantidade de vezes que tal palavra vai ser repetida
    scanf("%d",&n);
    
    nova_string = repete(string,n);
    
    printf("Nova String:%s",nova_string); // imprimindo a string repetida
    
    free(string); // liberar a memoria alocada
    free(nova_string); // O mesmo vai acontecer com a variavel nova_string
}