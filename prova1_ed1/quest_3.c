#include <stdio.h>

int maiusculas_vogais(char string[], int *maiuscula, int vogal){ // Neste codigo utilizamos uma função recursiva que nos seus parâmetros
 //                                                             tem um ponteiro maiuscula e a int vogal que vai ser responsaveis pelo retorno e apontar as vogais e maiusculas das strings
    int i; // esta variavel vai ser responsavel em percorrer a string

    for(i = 0; string[i] != '\0' ; i++){ // Utilizando a tabela Ascii temos esse comando que cada codigo representa caracteres maiusculos e minusculos

        if(string[i] >= 65 && string[i] <= 90){ // No caso se a string receber valor maior igual 65 que representa A maiusculo 
            //                                  e menor igual a 90 que presenta a minusculo o ponteiro maiusculo vai receber o incremento de +1
            *maiuscula += 1;
        }

        if(string[i] == 65 || string[i] == 97){ // Porém neste caso se a string receber o valor de 65 que representa A maiusculo
            //                                  ou receber 97 que representa e minusculo 
            vogal++; // sera incrementado a variavel vogal +'
        }

        else if(string[i] == 69 || string[i] == 101){ // Senão ele também vai verificar 69 para E maiusculo e 101 para e minusculo

            vogal++; // vogal incrementa +1
        }

        else if(string[i] == 73 || string[i] == 105){ // 73 para I maiusculo e 105 para i minusculo

            vogal++; // recebe +1 no incremento
        }

        else if(string[i] == 79 || string[i] == 111){ // 79 para O maiusculo e 111 para o minusculo

            vogal++; // incremento
        }

        else if(string[i] == 85 || string[i] == 117){ // 85 para U maiusculo e 117 para u minusculo

            vogal++; // incremento
        }
    }

    return vogal; // 
}

void main(){ 

    int maiuscula = 0, vogal = 0; // declarando as variaveis que vão receber as letras maiuscula e minusculas

    char string_01[20],string_02[20]; // sendo que as duas strings lidas teram 20 posiçoes começando do 0 e indo 19

    printf("Digite uma Palavra:"); // leitura das duas strings
    scanf("%s",string_01);

    printf("Digite uma Palavra:");
    scanf("%s",string_02);

    vogal = maiusculas_vogais(string_01, &maiuscula, vogal); // a variavel vogal vai fazer a chamada da função com os parametros eo endereço de memoria de maiusculas e vogal
    printf("Quantidade de Maiusculas String 1:%d",maiuscula); // e logo após é printado o total de maiusculas

    maiuscula = 0; // Em todo caso esta variavel a variavel maiuscula que estava dentro dos parametros deve começar em 0 pois é uma forma de limpeza para não pegar restos de conteudo na mesma

    vogal = maiusculas_vogais(string_02, &maiuscula, vogal); // e pegando a logica acima temos que pegar o valor das duas strings e mostrar o valor total de vogais
    printf("\nQuantidade de Maiusculas String 2:%d",maiuscula);
    printf("\nQuantidade Total de Vogais:%d",vogal);
}