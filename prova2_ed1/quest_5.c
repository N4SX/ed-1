#include <stdio.h.>
#include <stdlib.h>
#include <time.h>

void ler_aposta(int *aposta, int n){

    for(int i = 0; i < n; i++){
        
        while(1){

            printf("Informe o %d valor:",i + 1);
            scanf("%d", &aposta[i]);

            if(aposta[i] > 1 && aposta[i] < 100){
                break;
            }
            else{
                printf("Valor Invalido Digite Novamente!!!\n\n");
            }
        }
    }
}

void sorteia_valores(int *sorteio, int n){

    for(int i = 0; i < n; i++){
        sorteio[i] = 1 + rand() % 100;
        printf("%d ",sorteio[i]);
    }

}

int* compara_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int ns){

    int *vetor = (int*) malloc((1) * sizeof(int));
    int cont = 0;

    for(int i = 0; i < na; i++){
        for(int j = 0; j < ns; j++){

            if(aposta[i] == sorteio[j]){

                vetor = (int*) realloc(vetor,(cont + 1) * sizeof(int));
                vetor[cont] = sorteio[j];
                cont++;
            }
        }
    }
    *qtdacertos = cont;
    return vetor;
}

void main(){

    srand(time(NULL));
    int quant_aposta, quant_sorteio, qtdacertos = 0, *vetor_acertos;

    while(1){

        printf("Quantos Numeros deseja Apostar(1 ate 20):");
        scanf("%d", &quant_aposta);

        if(quant_aposta >= 1 && quant_aposta <= 20){
            break;
        }
        else{
            printf("Quantidade Invalida Digite novamwente!!!\n\n");
        }
    }

    system("cls");

    int *vetor_aposta = (int*) malloc((quant_aposta) * sizeof(int));
    ler_aposta(vetor_aposta, quant_aposta);

    system("cls");

    while(1){

        printf("Quantos Numeros deseja Sortear(1 ate 20):");
        scanf("%d", &quant_sorteio);

        if(quant_sorteio >= 1 && quant_sorteio <= 20){
            break;
        }
        else{
            printf("Quantidade Invalida Digite novamwente!!!\n\n");
        }
    }

    int *vetor_sorteio = (int*) malloc((quant_sorteio) * sizeof(int));

    sorteia_valores(vetor_sorteio, quant_sorteio);
    vetor_acertos = compara_aposta(vetor_aposta, vetor_sorteio, &qtdacertos, quant_aposta, quant_sorteio);

    for(int i = 0; i < qtdacertos; i++){
        printf("\nAcertou:%d",vetor_acertos[i]);
    }

    printf("\nAcertou %d numeros", qtdacertos);

    free(vetor_aposta);
    free(vetor_sorteio);
    free(vetor_acertos);
}