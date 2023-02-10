#include <stdio.h>

int primo(int m){ // declaração da função

    int i,aux = 0;

    for(i = 1; i <= m; i++){ // este laço de repetição mostra que se o numero for satisfativel até o numero ser informado será verdadeira

        if(m % i == 0){ // caso o resto da divisão inteira seja = o , então temos que este numero também é divisivel pelo numero digitado
            aux++;
        } // neste caso temos que a variavel aux vai ser responsavel em armazenar o numeros divisiveis pelo numero digitado , se a condição for satisfativel
    }

    if(aux == 2){ // se este numero tem apenas dois divisores
        return 1; // ele retornará para 1 se o numero for primo , isto quer dizer , ele divide por 2 ou por ele mesmo
    }else{
        return 0; // a função se encerra pois este numero não é primo
    }
}

void maior_menor(int m, int *p1, int *p2){ // declaração da função maior_menor que será responsavel em informar o maior e menor primo

    int i;

    for(i = 1; i < m; i++){
        
        if(primo(i) == 1){ // o numero é apontado pelo ponteiro p1 caso ele seja primo
            *p1 = i;
        }
    }

    i = 1;

    while(1){ // será chamada a função primo caso o primeiro numero seja primo

        if (primo(m+i) == 1){
            
            *p2 = m+i; // depois o ponteiro p2 vai ser responsavel a mostrar o segundo primo após o primeiro ser informado
            break;
        }
        else{
            i++;
        }
    }
}

void main(){ // função principal 

    int m, p1 = 0, p2 = 0; // onde nossas variaveis ponteiros começam zeradas

    printf("Digite um numero m:"); // preenchimento do numero e exibindo na tela
    scanf("%d",&m); 

    maior_menor(m, &p1, &p2); // depois vai ser apontado pelos ponteiros p1 e p2 quem é o maior e menor primo

    printf("Maior Primo menor que M:[%d]",p1); // exibindo os ponteiros 
    printf("\nMenor Primo maior que M:[%d]",p2); 
}