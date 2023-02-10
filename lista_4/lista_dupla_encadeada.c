#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{ //Nossa struct elemento onde teremos os nossos nós onde teremos
    //                   //Ponteiro proximo para o nó seguinte
    //                   //Ponteiro para o nó anterior 

    int valor;
    struct elemento *proximo; 
    struct elemento *anterior; 
    
}No;

typedef struct{ //Assim resumindo a nomenclatura para usar nossa struct
    
    No *inicio; //Ponteiro nó inicio que vai representar o inicio da lista do nó
    No *fim; //Ponteiro nó fim que vai representar o fim da lista do nó
    int tam; //Variavel tam que representa a quantidade do nó 
    
}Lista;

void inicializar(Lista *lista){ //Nossa funçao inicializar que vai iniciar o ponteiro inicio da lista e fim da lista com valores nulo
    
    lista->inicio = NULL; //Nossa variavel inicio vai receber nulo
    lista->fim = NULL;   //Nossa variavel fim vai receber nulo 
    lista->tam = 0; //Nossa variavel tam que vai ser responsavel pelo tamanho da lista inicializado com 0
}

int inserir(Lista *lista, int valor){ //Nossa funçao vai ser responsavel por inserir um nó sempre ao final da lista
    
    No *novo = (No*) malloc(sizeof(No)); //Alocando memoria para o novo nó
    No *atual; //Ponteiro que vai indicar o nó atual da nossa lista
    
    if(novo == NULL){//Se o novo nó nao seja alocado ou seja o novo nó é igual a nulo
        return -1; 
    }
    
    novo->valor = valor; //Vai adicionar valor ao novo nó
    novo->proximo = NULL; //Nosso ponteiro que indica o proximo nó recebe nulo
    
    if(lista->inicio == NULL){ //Se a lista esteja vazia/nulo
        
        novo->anterior = NULL; //Ponteiro que indica o nó anterior vai receber nulo 
        lista->inicio = novo; //O nosso ponteiro inicio vai apontar para o novo nó
        lista->fim = novo; //Eo ponteiro fim vai apontar para o novo nó
    }
    else{ //Se não, a lista não estiver vazia

        atual = lista->inicio; //O nosso ponteiro atual vai receber o inicio da lista

        while(atual->proximo){ //Enquanto nao for o fim da lista
            atual = atual->proximo; //O nó atual vai receber proximo nó
        }

        novo->anterior = atual; //Ponterio anterior do novo nó vai receber nó atual
        lista->fim->proximo = novo; //Ponterio que indica o fim da lista um nó a frente vai receber novo nó
        lista->fim = novo; //Ponteiro que indica o fim da lista vai receber novo nó
    }
    
    lista->tam += 1; //O tamanho da nossa lista incrementa +1
    return 0; //Retornando em 0
}

int remover(Lista *lista, int valor){ //Nossa funçao remover vai ser responsavel em excluir um valor informado pelo nosso usuario
    
    No *atual = lista->inicio; //Ponteiro atual vai receber o inicio da nossa lista
    No *aRemover = NULL; //Ponteiro aRemover vai indicar qual nó vai ser excluído
    
    if(atual != NULL && lista->inicio->valor == valor){ //Se o valor esteja no primeiro nó
        
        aRemover = lista->inicio; //O ponteiro aRemover vai receber o inicio da nossa lista
        lista->inicio = aRemover->proximo; //O novo inicio será o proximo nó depois do nó removido
        
        if(lista->inicio == NULL){ //Se o novo inicio seja nulo
            lista->fim = NULL; //O nosso ponteiro fim tambem vai receber nulo pois não tem mais nó
        }
        else{ //Se não o novo inicio nao seja nulo
            lista->inicio->anterior = NULL; //O nosso ponteiro anterior vai receber nulo
        }
    }
    else{ //Se não o nosso valor não esteja no primeiro nó
        
        while(atual != NULL && atual->proximo != NULL && atual->proximo->valor != valor){ //Enquanto verifica a lista ate encontra o valor ou nó nulo
            atual = atual->proximo;
        }
        
        if(atual->proximo){ //Se encontrar o nó a frente não seja nulo
            
            aRemover = atual->proximo; //Ponteiro vai receber o nó referente ao valor
            atual->proximo = aRemover->proximo; //O nosso nó vai receber o seu proximo nó
            
            if(atual->proximo == NULL){ //Se neste caso o proximo nó seja nulo
                lista->fim = atual; //O nosso ponteiro que indica o final da nossa lista vai receber nó atual
            }
            else{ //Se não neste caso o proximo nó nao for nulo
                atual->proximo->anterior = atual; //O ponteiro do proximo nó que representa o seu nó anterior vai receber agora o nó atual
            }
        }
    }
    if(aRemover){

        lista->tam -= 1; //Decrementa o tamanho da lista em -1
        free(aRemover); //Libera a memoria alocada para o nó que foi removido
        return 0; // retornando para 0
    }
    return -1; //Vai retorna -1 caso aconteça algum erro
}

int buscar(Lista *lista, int valor){ //Nossa função buscar vai ser responsavel em buscar um valor digitada pelo nosso usuário
    
    int i = 1;
    No *atual = lista->inicio; //Ponteiro atual vai receber inicio da lista
    
    while(atual != NULL){ //Nossa laço de repetição vai percorrer toda a lista
        
        if(atual->valor == valor){ //Caso o valor na lista seja igual ao informado pelo nosso usuario
            printf("Valor Encotrada no Indice %d\n",i);//Vai ser mostrada a seguinte mensagem
        }
        
        i++; //E nosso contador encrementa +1
        atual = atual->proximo; //A nossa variavel atual vai receber proximo nó
    }
    return -1;
}

int imprime(Lista *lista){ //Nossa funcao imprime vai ser responsavel em mostrar todos os nó da lista e seus respectivos valores
    
    No *atual = lista->inicio; //Ponteiro atual vai receber inicio da nossa lista 

    if(atual == NULL){ //Caso a variavel atual for igual a nulo
        return -1; //A nossa lista esteja vazia será retornado -1
    }
    
    printf("Tamanho atual da Lista:%d\n",lista->tam);
    printf("Valores:");
    
    while(atual != NULL){ //Enquanto atual for diferente de nulo , ela vai verificar toda nossa lista
        
        printf("[%d]",atual->valor);
        atual = atual->proximo; //Nosso ponteiro atual vai receber proximo nó
    }
    printf("\n\n");
    return 0;
}

int imprimeReverso(Lista *lista){ //Nossa função imprimeReverso vai ser responsavel em mostrar os nós , porém mostra do ultimo até o primeiro
 //                                Neste caso imprimindo em ordem decrescente , do maior valor para o menor
    No *ultimo = lista->inicio; //Ponteiro ultima vai receber inicio da lista

    if(ultimo == NULL){ //Se nassa variavel ultimo for igual nulo
        return -1;//Retorna -1 caso a lista esteja vazia
    }

    while(ultimo->proximo){ //Nosso laço de repetição enquanto vai verificar toda nossa lista
        ultimo = ultimo->proximo; //Nossa variavel ultimo vai receber o ultimo nó
    }

    printf("Tamanho atual da Lista:%d\n",lista->tam);
    printf("Valores:");
    
    while(ultimo){ //Enquanto ultimo vai ser executado ate ultimo ser igual a nulo
        
        printf("[%d]",ultimo->valor);
        ultimo = ultimo->anterior; //Nosso ultimo nó vai receber o nó anterior
    }
    printf("\n\n");
    return 0;
}

void liberarLista(Lista *lista){ //Nossa função liberarLista vai ser responsavel em liberar todos os espaços de memoria alocado para os nós
    
    No *atual = lista->inicio; //Nosso ponteiro atual vai receber inicio da lista
    No *proximo = NULL; //Nosso ponteiro proximo será um ponteiro auxiliar
    
    while(atual != NULL){ //Enquanto o nó atual nao for nulo
        
        proximo = atual->proximo; //Ponteiro proximo vai receber um nó a frente do atual
        free(atual); //Libera a memoria alocada do nosso nó atual
        atual = proximo; //Nossa variavel atual vai receber o proximo nó
    }
}

void main(){ //Nosso main que vai ser responsavel em mostrar os resultados e ter o retorno das nossas funções
    
    int op = 1, valor, retorno;
    
    Lista *lista = (Lista*) malloc(sizeof(Lista)); //Vai alocar memoria para a nossa lista de nó
    inicializar(lista); 
    
    while(op != 0){ //Enquanto nosso valor for diferente de 0 ele vai entrar no nosso menu iterativo
        
        printf("1-Inserir Valor\n");
        printf("2-Buscar Valor\n");
        printf("3-Remover Valor\n");
        printf("4-Imprime Lista\n");
        printf("5-Imprime Reverso\n");
        printf("6-Liberar Lista\n");
        printf("0-Sair\n");
        printf("Opcao:");
        scanf("%d", &op);
        system("cls");
        
        switch(op){ //Onde nosso usuário vai digitar o valor da operação desejada
            
            case 1:
            
                printf("Informe Valor para Inserir:");
                scanf("%d", &valor); 
                
                retorno = inserir(lista,valor);
                
                if(retorno == 0){
                    printf("Valor Inserido com Sucesso!\n\n");
                }
                else{
                    printf("Erro ao Inserir Valor!\n\n");
                }
                break;
                
            case 2:
            
                printf("Informe Valor para Buscar:");
                scanf("%d", &valor); 
                
                retorno = buscar(lista,valor);
                
                if(retorno == -1){
                    printf("Valor não Encontrado!\n\n");
                }
                break;
                
            case 3:
            
                printf("Informe Valor para Remover:");
                scanf("%d", &valor); 
                
                retorno = remover(lista,valor);
                
                if(retorno == 0){
                    printf("Valor Removido!\n\n");
                }
                else{
                    printf("Valor não Encontrado!\n\n");
                }
                break;
                
            case 4:
            
                retorno = imprime(lista);

                if(retorno == -1){
                    printf("Lista Vazia!\n\n");
                }
                break;
                
            case 5:
            
                retorno = imprimeReverso(lista);

                if(retorno == -1){
                    printf("Lista Vazia!\n\n");
                }
                break;
            
            case 6:

                liberarLista(lista);
                inicializar(lista); 
                printf("Espaco de Memoria Liberado!\n\n");
                break;
        }
    }
}