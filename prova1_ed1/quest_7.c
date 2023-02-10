#include <stdio.h>
#include <string.h>

void nova_string(char string_01[], char string_02[], char *string_03, int maior){ // inicio da função

    int i,cont = 0;

    for(i = 0; i < maior; i++){ // Este laço de repetição vai ser responsavel para percorrer da primeira até a maior string
    
        if(string_01[i] == 97 || string_01[i] == 101 || string_01[i] == 105 || string_01[i] == 111 || string_01[i] == 117){
            
            *(string_03 + cont) = string_01[i]; // depois ele vai analizar se a primeira string tem vogais, caso representadas por numeros da tabela ascii
            cont++; // após verificar que a string tem vogais em determinada posição , vai ser armazenada para o proximo indice
            // neste caso a string_03 vai receber a vogal armazenada em string_01
        }
        
        if(string_02[i] == 97 || string_02[i] == 101 || string_02[i] == 105 || string_02[i] == 111 || string_02[i] == 117){

            *(string_03 + cont) = string_02[i]; // isto ocorre do mesmo jeito também, verificar se a string_02 tem vogais
            cont++; //caso a string_02 tenha vogais, a string_03 vai receber a vogal de string_02 
        }
        
    } // pois a string_03 é responsavel pela nova palavra sem consoantes

    *(string_03 + cont) = '\0'; //na ultima posição da string_03 vai receber /0 para representar o fim da mesma
}

void main(){

    int i, cont_01 = 0, cont_02 = 0, maior; // variaveis cont_ são responsaveis pelo tamanho da da palavra que o usuário vai digitar
    char string_01[20], string_02[20], string_03[20]; // declarando tamanho de cada um dos vetores 

    printf("Digite uma Palavra:"); // leitura da string_01
    scanf("%s", string_01);

    printf("Digite outra Palavra:"); // Leitura da string_02
    scanf("%s", string_02);

    cont_01 = strlen(string_01); // está recebendo o tamanho da string_01
    cont_02 = strlen(string_02); // está recebendo o tamanho da string_02
    
    if(cont_01 > cont_02){ // verificação para saber qual string é maior

        maior = cont_01;
    }
    else if(cont_02 > cont_01){ // verificação para saber qual string é maior

        maior = cont_02; // maior vai receber string_02
    }else{
        maior = cont_01; // se ambas forem igual , independente de tudo o maior vai ser a string_01
    }

    nova_string(string_01, string_02, string_03, maior); // mostrando a nova string , palavra apenas com as vogais das 2 strings anteriores
    printf("string intercalada:%s",string_03);
}