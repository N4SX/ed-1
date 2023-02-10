#include <stdio.h>

int soma_recursiva(int soma, int i){ // Neste codigo temos uma função recursiva e seus parâmetros 

    if(i == 0){ // Iniciando o codigo temos que se o usuário digitar o valor 0 o programa é encerrado

        return 0;
    }
 // aqui está acontecendo a recursividade pois a variavel soma está fazendo as operações na função soma recursiva
    soma += soma_recursiva(soma, i - 1); // porém se o usuário digitar um valor alto será decrementado este valor
    soma += i; // em recursivas vezes decrementando -1 e salvando na variavel soma 

    return soma; // depois esses valores decrementados vão ser somados e seu resultado vai ser printado na variavel soma
}

void main(){ // já entrando neste main temos simplesmente ela vai receber o numero k e printando a variavel soma

    int k,soma; 

    printf("Dgite o valor de k:"); 
    scanf("%d",&k);
    
    soma = soma_recursiva(0, k); // a variavel soma vai receber a função recursiva e seus paramêtros
    //                           da variavel k que vai ser o numero até o 0 que vai ser sua condição de parada
    printf("Soma = %d",soma); 
}