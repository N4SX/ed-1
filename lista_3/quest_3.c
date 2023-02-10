#include <stdio.h>
#include <stdlib.h>

#define NOTAS 3 // definição definitiva para nossa variavel notas onde o aluno vai receber 3 notas

struct aluno { // Declaração da nossa struct aluno onde vai receber os dados a serem utilizados
    
    char nome[81];
    char matricula[8];
    char turma;
    float notas[NOTAS]; 
    
};

typedef struct aluno Aluno; 

void preencher(Aluno** turmas,int n){ // Entrando na nossa função preencher temos nossos parametros o ponteiro para ponteiro ALuno e turmas e a variavel n
    
    for(int i = 0; i < n; i++){ // nosso for vai funcionar para verificar e contar, para saber e preencher o alunos nas turmas matriculadas
        
        printf("Aluno %d\n\n",i + 1); 

        printf("Nome:"); // vai ser digitado o nome do nosso aluno 
        scanf(" %[^\n]s",turmas[i]->nome); // vai ler e ser incrementado na posição i da turma
        
        printf("Matricula:"); // a mesma coisa vai ser com a matricula 
        scanf(" %[^\n]s",turmas[i]->matricula); // vai ler o inteiro que representa a matricula do aluno e vai ser salva dentro de turmas
    
        printf("Turma (A) (B) (C):"); // Agora será dada a opção para a escolha da turma a ser salva no caso turma a, b ou c
        scanf(" %c",&turmas[i]->turma); // conforme acima o caractere que o usuário digitar vai ser salvo dentro das turmas

        for(int j = 0; j < NOTAS; j++){ // Nosso int J, vai servir como um contador das notas dos alunos, a condição sempre será satisfativel caso seja menor que NOTAS
           //                             pois NOTAS tem valor definido 3 que é a quantidade de notas permitidas
            printf("Digite a %d nota:",j + 1);
            scanf("%f",&turmas[i]->notas[j]); // assim vai ser mostrada a imagem na tela do usuário onde ele vai digitar a nota e essa nota vai ser salva no nosso vetor notas declarado com valor 3
        }
        system("cls");
    }
}

float calcularMedia(float *Notas){ // Agora entrando nesta função temos a função calcularMedia 
    //                              ela vai ser responsavel em pegar o valor as notas armazenadas e fazer o calculo
    float media = 0.0; // sendo assim começando a nossa função com uma variavel float zerada
    
    for(int i = 0; i < NOTAS; i++){ // se tiverem notas no nosso vetor NOTAS vai ser contado o encremento
        media += Notas[i]; // e adicionado a nossa variavel media
    }
    
    media = (media / NOTAS); // Assim vamos fazer o calculo das medias pegando as notas alocadas dentro do vetor NOTAS e fazendo o calculo
    return media; // depois de fazer o calculo e dado o retorno da variavel media.
}

void imprime_aprovados(Aluno** turmas,int n){ // Agora nesta função temos a parte que pegaremos a nossa variavel media
    
    int cont = 0; // nossos contadores de verificação são zerados
    float media = 0.0;
    
    for(int i = 0; i < n; i++){ // vai ser feito uma verificação 
        
        media = calcularMedia(turmas[i]->notas); // Nesta verificação vamos utilizar o vetor turmas na posição i e verificar as notas dos aluno
        
        if(media >= 7){ // caso a condição seja satisfativel , no caso a média das notas do aluno seja igual ou maior do que 7 vai ser mostrada
            
            printf("Aluno Aprovado!\n\n"); // a mensagem que o aluno foi aprovado , depois o nome do aluno , a sua matricula e sua turma
            printf("Nome:%s\n",turmas[i]->nome);
            printf("Numero da Matricula:%s\n",turmas[i]->matricula);
            printf("Turma:%c\n\n",turmas[i]->turma); 
            cont = 1; 
        }
    }

    if(cont == 0){ // caso a condição não seja satisfativel , ou seja se um aluno em sua media não chegou a media maior igual 7 
        
        system("cls");
        printf("Nao existe Alunos Aprovados!"); // vai ser mostrada esta mensagem
    }
}

float* media_turma(Aluno** turmas, char turma, int n){ 
    
    int cont = 0; // pegando nosso contador e zerando
    
    for(int i = 0; i < n; i++){ //vai verificar a quantidade de alunos
        
        if(turmas[i]->turma == turma){ // vai fazer a verificação e informar se o aluno está em determinada turma
            cont++;
        }
    }
    
    float *medias = (float*) malloc((cont) *sizeof(float)); // utilizando a alocação de memoria, para armazenar as medias dos alunos da turma
    cont = 0;
    
    for(int i = 0; i < n; i++){
        
        if(turmas[i]->turma == turma){ // vai verificar se todos os alunos até achar um aluno com a turma marcada
            
            medias[cont] = calcularMedia(turmas[i]->notas); // as medias na posição cont vai receber a media 
            cont++; // já o cont++ vai ser responsavel para ir ao seguinte aluno
        }
    }
    return medias; // fazendo assim o retorno da media final
}

void imprime_medias(Aluno** turmas, float* Medias, char turma, int n){ // Já está imprime_medias é responsavel em mostrar as médias 
    
    int cont = 0;
    
    for(int i = 0; i < n; i++){
        
        if(turmas[i]->turma == turma){
            
            printf("Nome:%s\n",turmas[i]->nome);
            printf("Media:%.2f\n\n",Medias[cont]);
            cont++;
        }
    }
}

void main(){ // Entrando na nossa função principal simplesmente temos as chamadas das funções eos prints, junto do nosso menu iterativo
    
    int TAM;
    float *Medias;
    
    Aluno **Alunos;
    Alunos = malloc((TAM) * sizeof(Aluno*));

    for(int i = 0; i < TAM; i++){
        Alunos[i] = malloc(sizeof(Aluno));
    }
    
    while(1){ // onde o usuário vai digitar a seguinte operação
        
        int opcao;
        char turma;
        
        printf("1-Criar Classe\n2-Imprime Alunos Aprovados\n3-Media de Alunos de uma Turma\n0-Sair\n"); // menu iterativo
        scanf("%d",&opcao);
        
        system("cls");
        
        if(opcao == 0){
            break;
        }
        
        switch(opcao){
            
            case 1:
            
                printf("Quantidade de Alunos para Cadastro:");
                scanf("%d",&TAM);
                
                system("cls");
                
                preencher(Alunos,TAM);
                break;
                
            case 2:
            
                imprime_aprovados(Alunos,TAM);
                break;
                
            case 3:
            
                printf("Escolha a Turma (A) (B) (C):");
                scanf(" %c",&turma);
                
                Medias = media_turma(Alunos,turma,TAM);
                imprime_medias(Alunos,Medias,turma,TAM);
                break;
        }
    }
    
    free(Alunos);
    free(Medias);
}