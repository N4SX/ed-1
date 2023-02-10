#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct livro {
    
    int codigo;
    int ano;
    int quantidade;
    char titulo[50];
    char autor[50];
    char editora[50];
    
};
typedef struct livro Livro;

void inicializar(Livro** livros,int MAX){
    
    for(int i = 0; i < MAX; i++){
        livros[i] = NULL;
    }
}

void adicionarLivro(Livro** livros, int n){

    system("cls");

    if(livros[n] == NULL){
        livros[n] = malloc(sizeof(Livro));
    }

    printf("Titulo:");
    scanf(" %[^\n]s", livros[n]->titulo);

    printf("Autor:");
    scanf(" %[^\n]s", livros[n]->autor);

    printf("Editora:");
    scanf(" %[^\n]s", livros[n]->editora);

    printf("Ano:");
    scanf("%d", &livros[n]->ano);

    printf("Quantidade:");
    scanf("%d", &livros[n]->quantidade);

    printf("Codigo:");
    scanf("%d", &livros[n]->codigo);

    system("cls");
}

void imprimeLivro(Livro** livros, int n){

    system("cls");

    int aux = 0;

    for(int i = 0; i < n; i++){

        if(livros[n] != NULL){
            
            printf("Titulo:%s\n", livros[i]->titulo);
            printf("Autor:%s\n", livros[i]->autor);
            printf("Editora:%s\n", livros[i]->editora);
            printf("Ano:%d\n", livros[i]->ano);
            printf("Quantidade:%d\n", livros[i]->quantidade);
            printf("codigo:%d\n\n", livros[i]->codigo);
            aux = 1;
        }
    }

    if(aux == 0){
        printf("Nao existe Livros cadastrados!\n\n");
    }

    system("pause");
    system("cls");
}

void buscarAutor(Livro** livros, int n){

    char busca[50];
    int verificar, aux = 0;

    system("cls");
    printf("Informe o Autor(Igual ao Registro):");
    scanf(" %[^\n]s", busca);
    system("cls");

    for(int i = 0; i < n; i++){

        verificar = strcmp(livros[i]->autor, busca);
        
        if(verificar == 0){

            printf("Titulo:%s\n", livros[i]->titulo);
            printf("Autor:%s\n", livros[i]->autor);
            printf("Editora:%s\n", livros[i]->editora);
            printf("Ano:%d\n", livros[i]->ano);
            printf("Quantidade:%d\n", livros[i]->quantidade);
            printf("codigo:%d\n\n", livros[i]->codigo);
            aux = 1;
        }
    }
    
    if(aux == 0){
        printf("Nao existe Livros com esse Autor!\n\n");
    }
    system("pause");
    system("cls");
}

void buscarEditora(Livro** livros, int n){

    char busca[50];
    int verificar, aux = 0;

    system("cls");
    printf("Informe a Editora(Igual ao Registro):");
    scanf(" %[^\n]s", busca);
    system("cls");

    for(int i = 0; i < n; i++){

        verificar = strcmp(livros[i]->editora, busca);
        
        if(verificar == 0){

            printf("Titulo:%s\n", livros[i]->titulo);
            printf("Autor:%s\n", livros[i]->autor);
            printf("Editora:%s\n", livros[i]->editora);
            printf("Ano:%d\n", livros[i]->ano);
            printf("Quantidade:%d\n", livros[i]->quantidade);
            printf("codigo:%d\n\n", livros[i]->codigo);
            aux = 1;
        }
    }

    if(aux == 0){
        printf("Nao existe Livros com essa Editora!\n\n");
    }
    system("pause");
    system("cls");
}

int removerLivro(Livro** livros, int n){

    int busca;

    system("cls");
    printf("Informe o Codigo do Livro:");
    scanf("%d", &busca);

    for(int i = 0; i < n; i++){

        if(livros[i]->codigo == busca){

            printf("O Livro %s foi removido!\n\n", livros[i]->titulo);

            free(livros[i]);
            livros[i] = NULL;

            system("pause");
            system("cls");

            return 1;
        }
    }
    return 0;
}

void main(){
    
    int MAX,cont = 0;
    
    printf("Informe a Quantidade Maxima do Conjunto:");
    scanf("%d",&MAX);
    system("cls");
    
    Livro **Livros;
    Livros = malloc((MAX) * sizeof(Livro*));

    inicializar(Livros, MAX);
    
    while(1){
        
        int opcao, verificar;
        
        printf("1-Adicionar Livro\n");
        printf("2-Exibir Livros\n");
        printf("3-Buscar por Autor\n");
        printf("4-Buscar por Editora\n");
        printf("5-Remover Livro\n");
        printf("0-sair\n");
        printf("Opcao:");
        scanf("%d",&opcao);

        if(opcao == 0){
            break;
        }
        
        switch(opcao){
            
            case 1:

                if(cont < MAX){

                    adicionarLivro(Livros, cont);
                    cont++;
                }
                else{

                    printf("Conjunto no Limite!\n\n");
                    system("pause");
                    system("cls");
                }
                break;
                
            case 2:

                imprimeLivro(Livros, cont);
                break;

            case 3:

                buscarAutor(Livros, cont);
                break;

            case 4:

                buscarEditora(Livros, cont);
                break;

            case 5:

                verificar = removerLivro(Livros, cont);

                if(verificar == 1){
                    cont--;
                }
                else{

                    printf("Livro nao encontrado!\n\n");
                    system("pause");
                    system("cls");
                }
                break;
        }
    }
}