#include <stdio.h> 
#include <stdlib.h> // biblioteca para a utilização do comando de alocação dinâmica malloc

void media_aluno(float notas[], float *media){ // inicia a função com o valor soma iniciado em 0 para nao pegar lixo de memoria

    float soma = 0.0;
    int i;

    for(i=1; i<=3; i++){  // esse laço de repetição vai pegar as 3 notas do aluno e acrescentar na variavel soma 

        soma += notas[i-1]; //  vai fazer o decremento do vetor notas
    
    }

    *media = soma/3; // assim pegando o valor da média e passando a soma dividido por 3

}

void main(){ // chegando nessa função principal temos o vetor notas preenchido com os 3 valores 

    float notas[3];
    float *M;

    M = (float *) malloc(sizeof(float));  // está alocando dinamicamente espaço de mamoria para um dado tipo float

    int i;

    for(i = 1; i <= 3; i++){  // nesta iteranção está recebendo o vetor notas onde vai receber e alocar no primeiro indice

        float x;

        printf("\nDigite a nota %d: ",i);
        scanf("%f",&x);

        notas[i-1] = x;

    }

    media_aluno(notas,M);  // e anexar nesta variavel 
    
    if(*M >= 7){  // condição para mostrar se o aluno foi ou não aprovado usando o ponteiro M 

        printf("Aluno Aprovado com media %.1f",*M);  

    }else{

        printf("Aluno Reprovado com media %.1f",*M);
    }

}