#include <stdio.h>

void troca(char *string){ // Nesta questão vamos utilizar os numeros da tabela ascii a que diz os caracteres vogais, cada numero representa a posição do caractere na tabela ascii

    int i; // variavel i que vai utilizar para percorrer o vetor

    for(i = 0; *(string + i) != '\0' ; i++){ // utilizando a aritmetica de ponteiros temos que se i na posição 0 onde inicia a string for diferente de 0
        //     vai ser feito o encremento                             
        if(*(string + i) == 97){ //          no caso se a string receber o valor 97 que representa o caractere 'a' 

            *(string + i) = 'u'; // o conteudo dessa string vai receber o caractere 'u'
        }

        else if(*(string + i) == 101){ // isto acontece quando a string recebe o caractere 'e'

            *(string + i) = 'o'; // então vai ser trocada pelo caractere 'o'
        }

        else if(*(string + i) == 105){ // seguindo neste sentido 105 vai representar o caractere 'i'

            *(string + i) = 'u'; // pegando o valor do ponteiro string e trocar pelo caractere 'u'
        }

        else if(*(string + i) == 111){ // o ponteiro que carrega o caractere 'o'

            *(string + i) = 'a'; // vai ser trocado pelo caractere 'a'
        }

        else if(*(string + i) == 117){ //o ponteiro quando estiver com o caractere 'u'

            *(string + i) = 'e'; //vai ser trocada pelo caractere 'e'
        }
    }
}

void main(){         // já aqui nesta função principal vai ser responsavel por receber e printar a string modificada

    char string[100]; // vetor de caracteres com 100 posições

    printf("Digite ate 100 letras:"); 
    scanf("%[^\n]",string); 

    troca(string); // depois é chamada a função troca 

    printf("String Alterada:%s",string); // depois de chamar a função troca da string e printada a string modificada

}