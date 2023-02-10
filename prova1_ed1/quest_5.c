#include <stdio.h>

char *cont_letra(char *string, int *Quantidade){ // iniciamos o nosso codigo com a função cont_letra 

    int i,j,aux = 0,cont = 0;
    char *Letras = (char*) malloc((27) * sizeof(char)); // Utilizando a aritmetica de ponteiros temos que o ponteiro Letras vai se comportar como um vetor
    //                                                  assim alocando dinamicamente usando o malloc o nosso ponteiro vai poder apontar a 27 posiçoes
    for(i = 0; *(string + i) != '\0'; i++){ // aqui vai simplesmente percorrer o ponteiro/vetor 
        
        for(j = 0; Letras[j] != '\0'; j++){ // se o caractere for diferente na posição 0 então vai ser armazenado na string
            
            if( *(string + i) == Letras[j]){ // porem vai ser percorrido novamente a string , se encontrar um caractere igual na string
                
                *(Quantidade + j) += 1; // Neste caso o ponteiro Quantidade vai receber +1 conforme a string tiver a mesma quantidade de caracteres iguais
                aux = 1; // no caso a variavel aux vai receber +1 para cada caractere igual
            }
        }
        
        if(aux == 0){ // no caso se a variavel aux for igual a 0 quer dizer que aquele caractere não se repetiu 
            Letras[cont] = *(string + i); // neste comando mostra quando é adicionado uma nova letra 
            *(Quantidade + cont) = 1; // adicionou a letra e depois o ponteiro quantidade recebe cont +1 para mostrar a quantidade do caractere digitado
            cont++; // depois o cont recebe ele +1 para pular o caractere digitado e receber um novo caractere
        }
        
        aux = 0; // assim pegando a variavel aux e zerando para não ter o caractere antigo na posição , assim passando um novo
    }
    
    Letras[cont] = '\0'; // Nest caso , depois de preenchido e declarado o final do vetor de caracteres
    return Letras; // e retornando para nossa variavel Letras
}

void main(){

    int i,Quantidade[26]; // neste caso temos o vetor quantidade que vai ser responsavel pelas letras diferente , no caso as 26 letras do alfabeto
    char string[100],*P; // e aqui o tamanho total da string e o ponteiro P responsavel em apontar a quantidade de letras da função cont_letra

    for(i = 0; i < 26; i++){  // Já aqui mostra a iteração responsavel onde o nosso vetor vai conferir as letras diferentes
        
        Quantidade[i] = 0;
    }

    printf("Digite:"); // lendo a string
    scanf("%[^\n]",string);
    
    P = cont_letra(string,Quantidade); // apontando a função cont_letra que dentro de seus parametros tem a string e sua quantidade de letras
    
    for(i = 0; *(P + i) != '\0'; i++){ //mostrand o resultado final 
        
        printf("%c:[%d] ",*(P + i), Quantidade[i]); // ponteiro p responsavel pelas letras juntos com a quantidade
    }
}