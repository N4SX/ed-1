#include <stdio.h>
#include <stdlib.h>

struct jogador { // nossa struct aluno vai estar reponsavel em receber os dados dos nossos jogadores
    
    int idade, camisa;
    float altura;
    char nome[20],posicao[20];
    
};

typedef struct jogador Jogador; // Assim vamos usar a função typedef para diminuir a questão da chamada da struct

void preencher(Jogador* J,int quantidade){ // a função preencher que vai receber os dados dos jogadores e preencher os campos
    
    int i; // tendo assim um contador i que vai entrar no laço de repetição 
    
    for(i = 0; i < quantidade; i++){ // e verificar a quantidade de jogadores que vai entrar
        
        printf("Jogador %d\n\n",i + 1);
        
        printf("Nome:");
        scanf(" %[^\n]s",J[i].nome); // vetor j na posição i vai receber o nome do jogador
        
        printf("Idade:");
        scanf("%d",&J[i].idade); // vetor j na posição i vai receber a idade do jogador
        
        printf("Altura:");
        scanf("%f",&J[i].altura); // vetor j na posição i vai receber a altura do jogador
        
        printf("Numero da Camisa:");
        scanf("%d",&J[i].camisa); // vetor j na posição i vai receber o numero da camisa do jogador
        
        printf("Posicao:");
        scanf(" %[^\n]s",J[i].posicao); // vetor j na posição i vai receber a posição do jogador
        
        system("cls");
    }
}

void maisAlto(Jogador* J,float *Maior,int quantidade){ // Já a função maisAlto vai ser responsavel de fazer a verificação dos jogadores
    
    int i;
    
    for(i = 0; i < quantidade; i++){ // fazendo o retorno para o jogador mais alto
        
        if(J[i].altura > *Maior){ //se a altura for maior do que o nosso ponteiro Maior
            *Maior = J[i].altura; // o nosso ponteiro maior vai receber o valor de altura no qual vai ser a maior altura do jogador
        }
    }
}

int menorIdade(Jogador* J,int quantidade){ // Entrando nesta função menorIdade temos que
    
    int i,cont = 0; // começamos nosso contador i e nossa variavel cont 
    float menor; // ea variavel menor do tipo float pois vamos armazenar o menor tamanho 
    
    menor = J[0].altura; //
    
    for(i = 1; i < quantidade; i++){ 
        
        if(J[i].altura < menor){ // se a altura for menor que a variavel menor
            
            menor = J[i].altura; // fazemos o encremento
            cont = i; // o cont vai ser responsavel para armazenar o indice da idade do menor jogador
        }
    }
    
    return J[cont].idade; // depois é feita o retorno da idade do menor jogador
}

float mediaAltura(Jogador* J,int quantidade){ // Agora na variavel mediaAltura vai ser responsavel em fazer o retorno pela função a media dos jogadores
    
    int i;
    float media = 0.0; // sendo assim a nossa variavel media que vai ser zerada
    
    for(i = 0; i < quantidade; i++){ // e nosso lanço de repetição vai fazer a verificação das alturas ea quantidade de jogadores
        media += J[i].altura; // sendo que nossa variavel media vai receber o nosso vetor J de jogadores e suas respectivas alturas
    }
    
    media = media/quantidade; // pegando o calculo da média e armazenando dentro da variavel media
    return media; // depois faz o retorno
}

float *medianaAltura(Jogador* J,int quantidade){ 
    
	float *VetAux = (float*) malloc((quantidade) *sizeof(float)); // o nosso vetor VetAux vai ser responsavel em receber todas as alturas e ordenar os valores ordenados
	float *jogadores = (float*) malloc((quantidade) * sizeof(float)); // ja nosso vetor jogadores está alocado dinamicamente para receber a quantidade de jogadores e fazer a mediana

	int i, j, cont = 0;
	float aux, mediana;
	
	for(i = 0; i < quantidade; i++){ // Este for vai percorrer a quantidade de jogadores
	    VetAux[i] = J[i].altura; // sendo assim nosso vetor auxiliar vai receber jogadores na posição i com a altura
	}

	for (i = 0; i < quantidade; i++){ 
	    
	    for (j = i + 1; j < quantidade; j++){
	        
	        if (VetAux[i] > VetAux[j]){ // O nosso vetor auxiliar vai fazer a verificação das duas posição sendo que se o vetor Aux na posição i for maior que a posição j
	            aux = VetAux[i]; // ele vai ordenar e fazer a troca
	            VetAux[i] = VetAux[j];
	            VetAux[j] = aux;
	        }
	    }
	}

    if(quantidade % 2 != 0){ // caso o numero de jogadores for par 

        for(i = 0; i < quantidade; i++){ // o nosso contador i vai verificar os jogadores

            if(J[i].altura == VetAux[quantidade / 2]){ // se altura de algum jogador for igual a mediana

                jogadores[cont] = i; // o nosso vetor de jogadores vai armazenar os jogadores
                cont++; //           com a altura media , pois pode acontecer o caso de todos os jogadores terem o mesmo tamanho
            }
        } // e nosso cont++ vai encrementar mais 1 espaço

        jogadores[cont] = -1; // Então o nosso vetor vai receber este -1 para indicar o fim

    }else{

        mediana = VetAux[quantidade / 2 - 1] + VetAux[quantidade / 2]; // Agora se os nossos jogadores tiverem idades diferentes de par
        
        for(i = 0; i < quantidade; i++){ // o nosso contador i vai verificar os jogadores
            
            if(J[i].altura == mediana){ // caso algum jogador de altura mediana
            
                jogadores[cont] = i; //o nosso vetor de jogadores vai receber a posição 
                cont++; //           que tenha o jogador com a altura media na
            }
        }
        jogadores[cont] = -1; // e nosso vetor vai receber -1 para marcar o fim
    }
    
    free(VetAux); // vai fazer a limpeza no caso a liberação da memoria do nosso vetor auxiliar que guardava os valores ordenados
    return jogadores;
}

void imprime_jogadores(Jogador* J,int quantidade){ // Simplesmente a nossa função onde vai receber os nossos valores e dados de jogadores
    
    printf("Jogadores Cadastrados\n\n"); // e imprimir todos os jogadores
    
    for(int i = 0; i < quantidade; i++){ // nossos ponteiros J , de jogadores junto com a estrutura seguida no caso , nome, idade altura etc
        
        printf("Nome:%s\n",J[i].nome);
        printf("Idade:%d\n",J[i].idade);
        printf("Altura:%.2f\n",J[i].altura);
        printf("Camisa:%d\n",J[i].camisa);
        printf("Posicao:%s\n\n",J[i].posicao);
    }
}

void main(){ // Agora na nossa função principal temos só a chamada das funções onde o usuário vai cadastrar o usuário
    
    int quant_jogador, menor_idade, cont;
    float mais_alto = 0.0,media_altura, *nome_jogadores;
    
    printf("Informe a quantidade de Jogadores:");
    scanf("%d",&quant_jogador);

    system("cls");
    
    Jogador *J;
    
    J = (Jogador*) malloc((quant_jogador) * sizeof(Jogador));
    nome_jogadores = (float*) malloc((quant_jogador) * sizeof(float));
    
    preencher(J,quant_jogador);
    maisAlto(J,&mais_alto,quant_jogador);
    menor_idade = menorIdade(J,quant_jogador);
    media_altura = mediaAltura(J,quant_jogador);
    nome_jogadores = medianaAltura(J,quant_jogador);
    imprime_jogadores(J,quant_jogador);
    
    printf("Jogador Mais Alto tem:%.2f\n",mais_alto); // linha 177 a 179: mostrando o resultados
    printf("Idade do Jogador Mais Baixo:%d\n",menor_idade);
    printf("Media das Alturas:%.2f\n",media_altura);
    
    if(nome_jogadores[0] == -1){ // nome_jogadores na posição receber -1 então não vai rodar pois o -1 representa o fim 
        printf("Nao ha jogadores com a Altura mediana!");
        
    }
    else{
        
        for(int i = 0; nome_jogadores[i] != -1; i++){ // caso for a condição da linha 181 diferente a condição se torna verdadeira e entramos no print da linha 190
            
            cont = nome_jogadores[i];
            printf("Jogador com Altura mediana:%s\n",J[cont].nome);
        }
    }
    
    free(J); // o nosso free vai ser responsavel em desalocar a memoria que foi utilizada no nosso vetor J de jogadores
    free(nome_jogadores); // vamos dar o free denovo para desalocar a memoria que foi utilizada nas posiçoes alocadas para mediana
}