#include <stdio.h> // 

void minutosHoras(int totalMinutos,int *horas,int *minutos){ // está função ira receber parametros tais eles ponteiros 

    *horas = totalMinutos/60; // esses ponteiros vão receber a conversão no caso ponteiros horas convertido para minutos
    *minutos = totalMinutos - (*horas * 60); // e total minutos

}

void main(){  // na função principal será digitada o tatal de minutos e depois vai receber seu total

    int total,h,m; // sendo que h para o ponteiro horas , e m para o ponteiro minutos 

    printf("Digite o total de minutos: "); 
    scanf("%d",&total);

    minutosHoras(total,&h,&m); // chamada da função minutosHoras onde tem os parametros de total , h , e m

    printf("Horas: %d Minutos: %d",h,m);

}