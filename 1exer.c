#include<stdio.h> 
#include<stdlib.h>

typedef struct diagonal{
    int ordem;
    int* v;
}Diagonal;

Diagonal* criacao_mat(){
    Diagonal* d = (Diagonal*)malloc(sizeof(Diagonal));
    printf("digite o tamanho da sua matriz(ordem)\n");
    scanf("%d", &d->ordem);   
    d->v = (int*)malloc(d->ordem * sizeof(int));
    return d;
}

void  preencher_mat(Diagonal* d){
    for(int i = 0; i < d->ordem; i++){
        printf("digite os valores de sua diagonal principal\n");
        scanf("%d", &d->v[i]);
    }
}

void impressao_mat(Diagonal* d){
    printf("diagonal principal de sua matriz: \n");
    for(int i = 0; i < d->ordem; i++){
        for(int j = 0; j < d->ordem; j++){
            if(i == j){
                printf("%d", d->v[i]);
            }else{
                printf("0");
            }
            printf("  ");
        }
        printf("\n");
    }
}

void buscar_ele(Diagonal* d){
    int i, j;
    printf("digite a linha e a coluna do seu elemento\n");
    scanf("%d %d", &i , &j);
    if(i == j){
        printf("%d", d->v[i]);
    }else{
        printf("0");
    }
}

void liberar(Diagonal* d){
    free(d->v);
    free(d);
}
int main(){
    Diagonal* d;
    d = criacao_mat();
    preencher_mat(d);
    impressao_mat(d);
    buscar_ele(d);
    liberar(d);
    return 0;
}
