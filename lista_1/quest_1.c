#include <stdio.h> // standard input output

float media (double vet[],int N, int *i){ //função media onde está armazenada os parametros utilizados no codigo

    int j;
    float media, soma = 0.0, menor = 100.0, aux[N]; 
    
    for(j=1; j<=N; j++){    // este comando vai fazer com que percorra todo vetor e suas posiçoes
        
        soma += vet[j-1]; // a variavel soma recebe todos os valores do vetor vet e soma
        
    }
    
    media = soma/N;       // esta variavel vai receber a a soma e dividir por N , sendo N indica o tamanho do vetor
    
    for(j=1; j<=N; j++){   

        float maiorBase,menorBase;      
        
        if(media > vet[j-1]){   // este comando de decisão vai servir como indicador de qual a maior variavel média ou valor do vetor
            
            maiorBase = media; // se a variavel maior base receber a média então a menor base vai receber o decremento no vetor vet
            menorBase = vet[j-1]; 
           
        }else{           // isso se aplica também no else 
            
            maiorBase = vet[j-1]; // se a menor base receber a média no caso a variavel maior base vai receber o decremento do vetor vet
            menorBase = media;
        }
        
        aux[j-1] = maiorBase - menorBase; // esta variavel aux vai receber a diferença do maior valor menos o menor valor
        
        if(aux[j-1] < menor){   
            
            menor = aux[j-1];
        }
    }
    
    for(j=1; j<=N; j++){  
        
        if(menor == aux[j-1]){  // sendo esse j o contador para a variavel auxiliar  e fazendo o returno para a função media
            
            *i = j-1;   
            break;
        }
    }
    
    return media;
}

int main(){ // passando a função principal esses comandos servem a informar o vetor 
    
    int N,i,j;                   

    printf("Tamanho do Vetor: ");  // esse vetor vai receber a quantidade de numeros que vai fazer o calculo da média
    scanf("%d", &N);      
    
    double vet[N]; 
    
    for(j=1; j<=N; j++){    // função para preenchimento do vetor N
        
        int x;
        
        printf("Digite um numero para adicionar ao indice %d: ",j-1);
        scanf("%d", &x);
        
        vet[j-1] = x;
        
    }
    
    printf("Media = %.2f\n",media(vet,N,&i));   
    printf("Indice mais proximo %d",i);    
    
    return 0;
}