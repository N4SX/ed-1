#include <stdio.h>

void troca(int *Vetor, int i, int j){ //Começamos o codigo com a função troca onde temos os parametros

    int temp; // esta variavel temp vai ser responsavel para a troca na hora de ordenar

    temp = *(Vetor + i); // primeiro a variavel temp vai receber o endereço de memoria do ponteiro Vetor mais a variavel i
    *(Vetor + i) = *(Vetor + j); // logo em seguida vai ser a troca do endereço de memoria sendo a variavel i vai receber o valor de j
    *(Vetor + j) = temp; // E por ultimo a variavel j vai receber o valor de temp que tem o valor original de i
}

int dividir_vetor(int *Vetor, int inicio, int fim){ // inciamos a nossa função dividir_vetor

    int pivo,i,j; // que vai ser responsavel para ver os valores do vetor principal e dividir

    pivo = *(Vetor + inicio); // assim tendo a variavel pivo , onde vai servir como comparação dos numeros
    i = inicio + 1;
    j = fim;

    while (i <= j) { // tendo assim a condição ,para verificar as variaveis i e j e comparar com o pivo

        while (i <= j && *(Vetor + i) <= pivo){ // sendo a variavel i responsavel pelo inicio do vetor
            i = i + 1;
        }
        
        while (i <= j && *(Vetor + j) > pivo){ // ea variavel j como o fim do vetor
            j = j - 1;
        }
        
        if (i < j) { // se as condições de ambas se satisfazerem será chamada a função troca
            troca(Vetor, i, j);
        }
    }

    troca(Vetor, inicio, j); // depois de chamar a função troca e retornado a variavel j , onde é responsavel pelo fim do vetor dividido
    return j;
}

void juntar(int *Vetor, int *Vetor_C, int inicio, int tam){ // assim pegando os vetores divididos e ordenados e armazenando seus valores dentro de um terceiro vetor
    
    if(inicio < tam){
        
        *(Vetor_C) = *(Vetor);
        juntar(Vetor + 1, Vetor_C + 1, inicio + 1, tam); // no caso o vetor C vai receber os dois vetores
    }
}
    
void quick_sort(int *Vetor, int inicio, int fim){ // iniciando nossa função quick_sort que vai ser responsavel em ordenar os dois vetores

    if (inicio < fim){

        int q;
        
        q = dividir_vetor(Vetor, inicio, fim);
        quick_sort(Vetor, inicio, q - 1);
        quick_sort(Vetor, q + 1, fim);
    } //                                      depois de pegar os dois vetores e colocar dentro do vetor c , acontece mais uma ordenação dentro do vetor c
} //                                          sendo responsavel em organizar os valores de menor para maior dentro do vetor c

void main(){ // função principal onde vai ser digitado e mostrado os valores do primeiro e segundo vetor fazendo anexação dentro do vetor C

    int tam_01,tam_02,i;

    printf("Informe o tamanho do Vetor A:"); 
    scanf("%d",&tam_01); // a variavel tam_01 vai ser responsavel para guardar o tamanho do Vetor A

    printf("Informe o tamanho do Vetor B:");
    scanf("%d",&tam_02); // a variavel tam_02 vai ser responsavel para guardar o tamanho do Vetor B

    int vetor_A[tam_01],vetor_B[tam_02],vetor_C[tam_01 + tam_02]; // declaração de vetores e seus respectivos tamanhos

    printf("\nPreencha o Vetor A\n"); // preenchimento do primeiro vetor , Vetor A

    for(i = 0; i < tam_01; i++){

        printf("Digite o %d valor:",i+1);
        scanf("%d", &vetor_A[i]); // apos ser digitado o primeiro valor este valor vai ser indexado ao primeiro endereço de memoria 
    } // e depois os demais valores vão ser preenchidos a frente dos outros endereços

    printf("\nPreencha o Vetor B\n"); // preenchimento do segundo vetor , Vetor B

    for(i = 0; i < tam_02; i++){

        printf("Digite o %d valor:",i+1);
        scanf("%d",&vetor_B[i]);
    }

    quick_sort(vetor_A, 0, tam_01 - 1); // na nossa ordenação quicksort o nosso vetor A , vai receber o primeiro valor na endereço 0
    quick_sort(vetor_B, 0, tam_02 - 1); // mesma coisa ocorre no tamanho B , vai receber o endereço de memoria 0 no primeiro valor 
    
    juntar(vetor_A, vetor_C, 0, tam_01); // agora na chamada da nossa função juntar temos o nosso Vetor A depois o Vetor B
    juntar(vetor_B, vetor_C + tam_01, 0, tam_02);
    
    quick_sort(vetor_C, 0, tam_01 + tam_02 - 1);

    printf("\nVetor A Ordenado:");//ordenar e printar Vetor A

    for(i = 0; i < tam_01; i++){ // ele vai fazer a comparação e ordenar o Vetor A e armazenar na menor posição determinado numer
        printf("[%d] ",vetor_A[i]);
    }

    printf("\n\nVetor B Ordenado:"); //depois ele vai fazer o mesmo com b , vai verificar os numeros e ordenar cada um deles em suas posições de acordo com seu tamanho

    for(i = 0; i < tam_02; i++){
        printf("[%d] ",vetor_B[i]); // printar e ordenar Vetor B
    }

    printf("\n\nVetor A + B Ordenado:"); // e por fim ele vai pegar os dois vetores ordenados e ordenar eles dentro do Vetor C

    for(i = 0; i < tam_01 + tam_02; i++){
        printf("[%d] ",vetor_C[i]); // printar e ordenar Vetor C
    }
}