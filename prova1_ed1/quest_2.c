#include <stdio.h>

int soma_recursiva(int A, int soma, int B){ // Já neste codigo a gente utilizou um pouco da lógica parecida da questão 01
 //                   pois vamos pegar o numero após a variavel A e antes da variavel B fazendo sua soma
    if(A == B || A - 1 == B){ // Então se o usuário digitar os valores iguais 

        return 0; // o programa se encerra 
    }
 //    recursão quase igual a da questão 01
    soma += soma_recursiva(A + 1, soma, B); // Porem caso o usuário digite um valor diferente vai ser feito o incremento na primeira variavel
    soma +=A; // O valor da variavel A será incrementado +1 começando ser o primeiro a ser contado para a soma dos proximos até o penultimo antes de B

    return soma; // Dadas todas operanções vai ser dado o retorno na variavel soma onde ocorreu a recursão da função soma_recursiva
} // e o resultado vai ser armazenado nesta variavel

void main(){ // entrando na função principal do codigo temos as variaveis principais do codigo

    int A,B,soma,aux; // preenchimentodas variaveis

    printf("Digite o valor de A:");
    scanf("%d",&A);

    printf("Digite o valor de B:");
    scanf("%d",&B);

    if (B < A){ //No caso se o valor de B for menor que o valor de A vai ser feita a troca dos valores utilizando a variavel aux

        aux = B;
        B = A;
        A = aux;
    }
    
    soma = soma_recursiva(A + 1, 0, B); // depois vai receber o incremento e printando o resultado 

    printf("Soma = %d",soma); 
}