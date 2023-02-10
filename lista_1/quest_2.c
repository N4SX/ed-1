#include <stdio.h> // standard input output

void fatoraPotencia(int numero,int *base,int *expoente){ // função contendo os parametros
    
    int i,j,soma = 1;
    
    for(i=2; numero != soma && numero != 0 ;i++){  // esse comando ira fazer iteraçoes onde o menor numero na fatoração da potencia vai ser mostrado
        
        soma = 1;
        
        for(j=0; soma < numero;j++){                
            
            soma *= i;
            
        }
    }

    if(numero == 0){ // este laço é responsavel em mostrar a base eo expoente

        *base = 0; // na matemática se a base for 0 o expoente sempre será 1
        *expoente = 1;

    }

    if(numero != 0){ // ja se for um numero diferente de 0 ae entra no caculo utilizando o ponteiro base e ponteiro expoente

        *base = i-1;
        *expoente = j;

    }
}

void main(){ // função principal onde vai ser digitado os valores 
    
    int valor,base = 0,expoente = 0; // valores começados em o para nao pegarem lixo de memoria 
    
    printf("Digite um Valor: ");
    scanf("%d",&valor);
    
    fatoraPotencia(valor,&base,&expoente); // chamada da função onde será exibida o valor da base e do expoente 
    
    printf("Base = %d Expoente = %d",base,expoente); // printando o menor numero para a base e expoente 

}