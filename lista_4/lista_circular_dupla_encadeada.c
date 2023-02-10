#include <stdio.h>
#include <stdlib.h>

struct no{ //Iniciamos a nossa struct no com o:
    //      Nossa int valor responsavel em receber o valor digitado pelo usuario
	//       O nosso ponteiro no para o proximo nó
	//       Eo nosso ponteiro no pra o nó anterior
	int valor; 
	struct no *proximo; 
	struct no *anterior; 
	
};

typedef struct no NO; //Assim vamos resumir a nomenclatura da nossa struct no para melhor manuseio

NO *inicializarLista(){ 
    
	return NULL; //Depois vamos retornar para nulo na função para inicializar
}

NO *inserirInicio(NO *lista, int valor){ //Nosso funçao inserirInicio vai ser responsavel em mostrar valores e sempre adicionar ao inicio da lista
	
	NO *novo = (NO*) malloc(sizeof(NO));//Vai alocar memoria para o novo nó que será criado pelo nosso usuario
	novo->valor = valor; //Vai ser adicionado valor a este novo no

	if(lista == NULL){ //Se a lista estiver nula/vazia
	    
		novo->proximo = novo; //O nosso ponteiro próximo vai receber novo nó
		novo->anterior = novo; //Eo ponteiro anterior receber nó
	}
	else{ //Se não, no caso a nossa lista não estiver vazia
	
	    NO *aux; //Criamos assim nossa variavel no auxiliar
	    
		novo->proximo = lista; //O nosso ponteiro proximo do novo nó vai receber lista
		lista->anterior = novo; //A nossa lista anterior vai receber novo nó
		
		for(aux = lista; lista != aux->proximo; aux = aux->proximo); //Vai verificar ate o início ser igual ao fim e armazenar em nossa variavel auxiliar o fim
		    
		aux->proximo = novo; //O nosso proximo nó depois do último nó será o novo nó
		novo->anterior = aux; //O nosso nó anterior ao novo colocado será o último que tinha na lista
		
	}
	return novo; //Retornando para novo
}

NO *inserirFinal(NO *lista, int valor){ //Nossa funçao InserirFinal vai ser responsavel em inserir valores e sempre adicionar no final da lista	
    
	NO *novo = (NO*) malloc(sizeof(NO)); //Alocando memoria para o nosso novo nó
	novo->valor = valor; 

	if(lista == NULL){ //Se neste caso a nossa lista estiver nula/vazia
	    
		novo->proximo = novo; //O nosso ponteiro proximo do novo nó vai receber novo nó
		novo->anterior = novo; //E o ponteiro anterior vai receber novo nó
		
		return novo; //Fazendo o retorno para o novo
	}
	else{ //Se não neste caso a lista não estiver vazia
	    
		NO *aux; //A nossa variavel nó aux que vai auxiliar até encontrar o ultimo nó
		aux = lista; //Assim a nossa variável no aux recebe o inicio da nossa lista
		
		lista->anterior = novo; //A nossa variavel anterior vai apontar para o novo nó adicionado que eo ultimo 
		novo->proximo = lista; //Neste caso o nosso próximo nó depois do último sera o início da nossa lista
		
		for(aux = lista; lista != aux->proximo; aux = aux->proximo);//E nosso laço de repetiçao vai verificar toda nossa lista
		
		aux->proximo = novo; //Neste caso o proximo nó do nosso aux vai receber o novo
		novo->anterior = aux; //Depois o nó anterior do novo nó vai receber aux
		return lista;         //Depois retornando a nossa lista
	}
}

void mostrarLista(NO *lista){ //Nossa função mostrarLista vai ser responsavel em mostrar todos os nós da lista
    
    NO *aux = lista; //Nosso ponteiro auxiliar vai receber inicio da lista
    
	if(lista == NULL){ //Se nossa lista estiver nula/vazia mostrara a seguinte mensagem
		printf("Lista Vazia!\n\n");//Assim mostrando a seguinte mensagem
	}
	else{ //Se não vai ser mostrada nossa lista
	    
		printf("LISTA:");
		
		do{ //Nossa laço de repetição do while vai executar para que o primeiro no seja executado
		
			printf("[%d]",aux->valor);
			aux = aux->proximo;
			
		}while(aux != lista); //Vai verificar se o próximo nó é o nó de inicio
		printf("\n\n");
	}
}

void mostrarInverso(NO *lista){ //Nossa função MostrarInverso vai mostrar todos os nós da lista só que de maneira inversa , de traz para frente
    
    NO *aux = lista->anterior; //Nosso ponteiro aux vai receber nó anterior ao início da nossa lista
    
	if(lista == NULL){ //Se neste caso a lista esteja nula/vazia
		printf("Lista Vazia!\n\n"); //Vai printar a seguinte mensagem
	}
	else{ //Se nao vai mostrar a nossa lista invertida
	    
		printf("LISTA INVERTIDA:");
		
		while(lista != aux){ //Nossa laço de repetiçao enquanto vai verificar até o primeiro nó ser igual ao ultimo
		    
		    printf("[%d]",aux->valor);
		    aux = aux->anterior; //Depois nosso aux vai receber o nó anterior
		}
		printf("[%d]",aux->valor); //Vai mostrar o ultimo valor caso o inicio seja igual ao fim
		printf("\n\n");
	}
}

int buscar(NO *lista, int valor){ //Nossa função buscar vai fazer uma busca na lista a partir de um valor que o usuario digitou
    
    NO *aux = lista; //Nossa variavel auxiliar vai receber inicio da lista
    
	if(lista == NULL){ //Se a nossa lista estiver vazia/nula
		printf("Lista Vazia!\n\n");//Mostra a seguinte mensagem
	}
	else if(lista->valor == valor){ //Se não o valor informado pelo usuario estiver no primeiro nó
	    printf("Valor encontrado!\n\n");//Vai ser mostrada a seguinte mensagem
	    return 1;
	}
	else{ //Se não neste caso a lista não estiver vazia/nula
	    
		while(lista != aux->proximo){ //Enquanto lista for diferente ela vai pecorrer todos os nó da lista ate que o primeiro seja igual ao último
		    
			if(aux->valor == valor){ //Se o valor de algum nó seja igual ao que o usuario digitou
				printf("Valor encontrado!\n\n"); //Mostra a seguinte mensagem
				return 1;
			}
			aux = aux->proximo; //E nossa variavel auxiliar vai receber o proximo nó
		}
		if(aux->valor == valor){ //Se o nosso valor for encontrado na verificação 
		    printf("Valor encontrado!\n\n"); //Vai ser mostrado a seguinte mensagem
		    return 1;
		}
		return 0;
	}
}

NO* remover(NO *lista, int valor){ //Nossa função remover vai ser responsavel em remover um nó da lista pelo nosso usuario
    
	if(lista == NULL){ //Se a nossa lista estiver com valor nulo/vazio
	    
		printf("Lista Vazia!\n\n"); //Vai mostrar a seguinte mensagem
		return lista;
	}
	else{ //Se não neste caso a lista não seja vazia/nula
	
	    if(lista->proximo == lista){ //Se existe apenas um nó na lista
	    
	        if(lista->valor == valor){ //Se o valor do nó seja igual ao que o usuário informou
	            
	            return NULL; //Fazendo o retorno para nulo pois não tem mais nó na nossa lista
	        }
	        else{//Se não ele vai mostrar a seguinte mensagem

	            printf("Valor nao encontrado!\n\n");
	            return lista; //E fazendo o retorno na lista
	        }
	    }
	    
	    NO *aux;
		
		if(lista->valor == valor){ //Se neste caso o primeiro nó seja o digitado pelo nosso usuario para referida remoçao
		    
			printf("Valor Removido!\n\n", valor); //Vai mostrar a mensagem que tal valor foi removido
			
			for(aux = lista; lista != aux->proximo; aux = aux->proximo);//Vai fazer uma verificaçao ate o nó aux ser igual ao nó do incio
			
			lista = lista->proximo; //O inicio da nossa lista agora vai ser um nó seguinte
			lista->anterior = aux; //Eo nosso nó anterior do novo início vai apontar para o último nó
			
			return lista; //Assim depois de todo o processo vai fazer o retorno para a lista
		}
		
		for(aux = lista; lista != aux->proximo; aux = aux->proximo){ //Vai fazer a verificaçao ate que o início seja igual ao ultimo
		    
			if(aux->proximo->valor == valor){ //Se neste caso o proximo nó tenha o valor igual ao que o nosso usuário digitou
			    
				NO *local; //Assim vai guardar qual nó sera excluido
				local = aux->proximo->proximo; //Nosso ponteiro local vai receber qual o removido apontava
				aux->proximo = local; //Depois o próximo nó depois do atual vai receber local
				local->anterior = aux; //Na variavel local tem como seu anterior valor o último nó
				
				printf("Valor Removido!\n\n", valor);//Vai mostrar a seguinte mensagem
				return lista;
			}
		}
		printf("Valor:%d nao encontrado!\n\n", valor); //Caso a condição acima nao for satisfativel vai mostrar a mensagem
		return lista;
	}
}

void liberarMemoria(NO *lista){ //Nossa funçao liberarMemoria vai limpar/liberar a memoria alocada a todos nós
    
    if(lista == NULL){ //Se a lista for igual nula
		free(lista);  //Vai liberar a memoria da lista
	}

	else{ //Se a condiçao nao for satisfativel

		NO *aux = lista; //Nossa ponteiro do tipo no aux vai receber lista

		void liberando(NO *lista){

			if(lista->proximo != aux){ //Se tal condiçao for satisfativel
				liberando(lista->proximo);
			}
			free(lista);
		}
		liberando(lista);
		free(lista); //Liberando memoria alocada lista
		free(aux);   //Liberando memoria alocada do nosso aux
	}
}

void main(){ //E na nossa função principal teremos nosso menu iterativo , onde nosso usuário vai digitar a opçao desejada e ter a chamada das funçoes
    
    NO *lista;
    int valor, busca;
    
    lista = inicializarLista();

    while(1){
        
        int op_menu;
        
        printf("************ MENU **************\n");
        printf(" 1 - Inserir no Inicio\n");
        printf(" 2 - Inserir no Fim\n");
        printf(" 3 - Exibir\n");
        printf(" 4 - Exibir Invertida\n");
        printf(" 5 - Buscar Elemento\n");
        printf(" 6 - Remover Elemento\n");
        printf(" 7 - Liberar Memoria \n");
        printf(" 0 - SAIR\n");
        printf("*********************************\n");
        printf("Digite a opcao: ");
        scanf("%d", &op_menu);
        system("cls");
        
        switch(op_menu){
            
            case 1:
            
                printf("Numero a inserir: ");
                scanf("%d",&valor);
                
                lista = inserirInicio(lista, valor);
                
                if(lista != NULL){
                    printf("Valor Inserido!\n\n");
                }
                break;
    
            case 2:
            
                printf("Numero a inserir: ");
                scanf("%d", &valor);
                
                lista = inserirFinal(lista, valor);
                
                if(lista != NULL){
                    printf("Valor Inserido!\n\n");
                }
                break;
    
            case 3:
            
                mostrarLista(lista);
                break;
    
            case 4:
                
                mostrarInverso(lista);
                break;
                
            case 5:
            
                printf("Numero para Busca: ");
                scanf("%d", &valor);
                
                busca = buscar(lista, valor);
                
                if(busca == 0){
                    printf("Valor nao encontrado!\n\n");
                }
                break;
                
            case 6:
            
                printf("Numero para remover: ");
                scanf("%d", &valor);
                
                lista = remover(lista,valor);
                break;
                
            case 7:
            
                liberarMemoria(lista);
                lista = inicializarLista();
                printf("Memoria Liberada!\n\n");
                break;
                
            case 0:
                break;
        }
    }
}