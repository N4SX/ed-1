#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct disciplina { // declaração da nossa struct disciplina que vai ter os dados informados
    
    char codigo_disciplina[20]; 
    char codigo_curso[20];
    int periodo;
    int horas;
    char nome[50];
    
};

typedef struct disciplina Disciplina;

struct curso { // já aqui temos a nossa struct curso onde vai ter os dados do curso na hora da sua criação
    
    char codigo[20];
    int quant_periodo;
    char nome[50];
    Disciplina *disciplinas_curso; // aqui temos o nosso ponteiro/vetor de structs
    
};

typedef struct curso Curso;

void criarCurso(Curso *cursos, int cont_curso){ // agora entrando na nossa função temos a criação do nosso curso temos
    
    printf("Nome do Curso:"); // que vamos digitar o nome do curso e vai ser adicionado dentro da nossa estrutura 
    scanf(" %[^\n]s",cursos[cont_curso].nome);
    
    printf("Codigo do Curso:");
    scanf(" %[^\n]s",cursos[cont_curso].codigo);// isto vai acontecer para os proximos atributos como codigo e abaixo a quantidade de periodos
    
    printf("Quantidade de Periodos:");
    scanf("%d",&cursos[cont_curso].quant_periodo); // sendo estes elementos referenciados

    system("cls");
}

void criarDisciplina(Curso* cursos,int cont_curso, int cont_disciplina){ //igual a função acima O mesmo vai acontecer com as disciplinas
 //                                                                      vai ser criada a disciplina este dados vai ter relacionamento com os elementos da struct
    printf("Nome da Disciplina:");
    scanf(" %[^\n]s",cursos[cont_curso].disciplinas_curso[cont_disciplina].nome); // as criações está sendo referenciadas dentro da struct como ponteiro

    printf("Codigo da Disciplina:");
    scanf(" %[^\n]s",cursos[cont_curso].disciplinas_curso[cont_disciplina].codigo_disciplina);

    printf("Periodo:");
    scanf("%d",&cursos[cont_curso].disciplinas_curso[cont_disciplina].periodo);

    printf("Carga Horaria:");
    scanf("%d",&cursos[cont_curso].disciplinas_curso[cont_disciplina].horas);

    system("cls");
}

int verifCurso(Curso *cursos, int cont_curso){ // Nesta função temos o seguinte comando , vai verificar se tal curso existe de acordo com seu codigo cadastrado

    int iguais;
    char string[20];

    printf("Informe o codigo referente ao Curso:"); // ler o codigo do curso
    scanf(" %[^\n]s",string);

    for(int i = 0; i <= cont_curso; i++){ // ele vai fazer a verificação dos codigos dos cursos

        iguais = strcmp(string, cursos[i].codigo); // porém se o codigo que foi digitado for igual a outro codigo de curso este valor vai ser retornado a 0

        if(iguais == 0){ // 
            return i;
        }
    }
    return -1; // porém se não existir curso com determinado codigo vai receber o retorno -1
}

void imprimeCursos(Curso *cursos, int cont_curso, int cont_disciplina[]){ // Já nesta função temos que vai mostrar os cursos e seus determinados e referentes atributos
    
    printf("Cursos Cadastrados Abaixo\n\n");
    
    for(int i = 0; i <= cont_curso; i++){ // ele vai verificar a quantidade de cursos existentes
        
        printf("Nome do Curso:%s\n",cursos[i].nome);
        printf("Codigo do Curso:%s\n",cursos[i].codigo);
        printf("Periodos:%d\n\n",cursos[i].quant_periodo);

        if(cont_disciplina != 0){ // a condição vai ser satisfativel quando a cont_disciplinas for diferente de 0

            for(int j = 0; j < cont_disciplina[i]; j++){ // vai verificar a quantidade de disciplinas 

                printf("[%s] - ",cursos[i].disciplinas_curso[j].nome);
                printf("Periodo:%d - ",cursos[i].disciplinas_curso[j].periodo);
                printf("Carga Horario:%d:00hs - ",cursos[i].disciplinas_curso[j].horas);
                printf("Codigo:%s\n",cursos[i].disciplinas_curso[j].codigo_disciplina);
            }
            printf("\n");
        }
        else if(cont_disciplina == 0){ // caso essa condição não for satisfativel , ou seja cont_disciplina for igual a 0
            printf("Nao existe disciplinas cadastradas!");
        }
    }

    system("pause");
    system("cls");
}

void maisPeriodo(Curso* cursos, int cont_curso){ // Já aqui nesta temos que mostrar o curso com mais periodos

    int maior = 0, aux;

    for(int i = 0; i <= cont_curso; i++){ // vai fazer a verificação de todos os cursos

        if(cursos[i].quant_periodo > maior){ // se a a variavel maior for menor que a quant_periodo
            
            maior = cursos[i].quant_periodo; // a variavel maior vai receber a quantidade de cursos, sendo a maior quantidade
            aux = i;
        }
    }

    printf("Curso com a maior quantidade de Periodos:%s com %d Periodos\n\n",cursos[aux].nome, cursos[aux].quant_periodo); 
}

void quantDisciplina(Curso* cursos,int cont_curso, int cont_disciplina){ // Este função vai ser responsavel para mostrar a quantidade de disciplinas que o usuário pedir

    printf("Curso:%s com %d disciplinas\n\n",cursos[cont_curso].nome, cont_disciplina);
}

void disciplinaPeriodo(Curso *cursos, int cont_curso, int cont_disciplina){ // Esta função função vai exibir quantidades de disciplinas de determinado periodo pedidas pelo usuário

    int periodo, cont = 0;

    printf("Escolha o Periodo:"); // Ler o periodo digitado pelo usuário
    scanf("%d",&periodo);

    for(int i = 0; i < cont_disciplina; i++){

        if(periodo == cursos[cont_curso].disciplinas_curso[i].periodo){
            cont++;
        }
    }

    printf("Quantidade de Disciplinas no Periodo:%d\n\n",cont);
}

void main(){ // Já chegando no nosso main , simplesmente temos os prints do nosso menu iterativo junto com as chamadas da função relacionadas as structs
    
    int i, opcao,aux_1 = 0, aux_2 = 0, *cont_disciplina, cont_curso = 0;
    
    cont_disciplina = (int*) malloc((1) * sizeof(int));
    cont_disciplina[0] = 0;

    Curso *Cursos;
    Cursos = (Curso*) malloc((1) * sizeof(Curso));

    Cursos->disciplinas_curso = (Disciplina*) malloc((1) * sizeof(Disciplina));

    while(1){ // menu iterativo onde o usuário vai digitar a opção desejada
        
        printf("1-Criar Curso\n");
        printf("2-Criar Disciplina\n");
        printf("3-Exibir cursos\n");
        printf("4-Curso com mais Periodos\n");
        printf("5-Quantidade de Disciplinas\n");
        printf("6-Quantidade de Disciplinas de um Periodo\n");
        printf("0-Sair\n");
        scanf("%d",&opcao);
        
        system("cls");
        
        if(opcao == 0){
            break;
        }
        
        switch(opcao){
            
            case 1:
            
                if(aux_1 == 0){
                    
                    criarCurso(Cursos,0);
                    aux_1++;
                }
                else{
                    
                    cont_curso++;
                    Cursos = (Curso*) realloc(Cursos,(cont_curso + 1) * sizeof(Curso));
                    Cursos[cont_curso].disciplinas_curso = (Disciplina*) malloc(sizeof(Disciplina));
                    
                    cont_disciplina = (int*) realloc(cont_disciplina, (cont_curso + 1) * sizeof(int));
                    cont_disciplina[cont_curso] = 0;

                    criarCurso(Cursos,cont_curso);
                }
                
                break;

            case 2:

                i = verifCurso(Cursos, cont_curso);

                if(i != -1){
                    
                    if(aux_2 == 0){
                        
                        criarDisciplina(Cursos, i, 0);
                        cont_disciplina[0] = 1;
                        aux_2++;
                    }
                    else{
                        
                        cont_disciplina[i] += 1;                        
                        Cursos[i].disciplinas_curso = (Disciplina*) realloc(Cursos[i].disciplinas_curso, ((cont_disciplina[i]) * sizeof(Disciplina)));
                        
                        criarDisciplina(Cursos, i, cont_disciplina[i] - 1);
                    }
                }
                else{

                    printf("Nao existe curso com o referente codigo!\n\n");
                    system("pause");
                    system("cls");
                }

                break;

            case 3:

                imprimeCursos(Cursos,cont_curso,cont_disciplina);
                break;

            case 4:
                
                maisPeriodo(Cursos,cont_curso);
                break;

            case 5:

                i = verifCurso(Cursos, cont_curso);

                if(i == -1){

                    printf("Nao existe curso com o referente codigo!\n\n");
                    system("pause");
                    system("cls");
                }
                else{
                    quantDisciplina(Cursos, i, cont_disciplina[i]);
                }
                break;

            case 6:

                i = verifCurso(Cursos, cont_curso);

                if(i == -1){

                    printf("Nao existe curso com o referente codigo!\n\n");
                    system("pause");
                    system("cls");
                }
                else{
                    disciplinaPeriodo(Cursos, i, cont_disciplina[i]);
                }
                break;
        }
    }
    free(cont_disciplina); // Desalocando a memoria utilizada na nossa variavel contadora de disciplinas
    free(Cursos); // o mesmo desalocamento acontece em Cursos
}