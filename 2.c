#include <stdlib.h>
#include<stdio.h>
typedef struct lista{
    int linha;
    int coluna;
    int info;
    struct lista* prox;
}Lista;

typedef struct esparsa{
    int linhas;
    int colunas;
    struct lista* prim;
}Esparsa;

Esparsa* cria_mat(){
    Esparsa* m;
    m = (Esparsa*)malloc(sizeof(Esparsa));
    printf("digite o numero de linas e colunas da sua matriz\n");
    scanf("%d %d", &m->linhas, &m->colunas);
    m->prim = NULL;
    return m;
}

Lista* preencher_mat(Lista* l){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    printf("digite a linha e a coluna do seu valor\n");
    scanf("%d %d", & novo->linha, &novo->coluna);
    printf("digite o valor\n");
    scanf("%d", & novo->info);
    novo->prox = l;
    return novo;
}
int buscar(Lista* l, int li, int c){
    Lista* p;
    for(p  = l; p != NULL; p = p->prox){
        if(li == p->linha){
            if(c == p->coluna){
                return p->info;
            }
        }
    }
    return 0;
}

void impressao(Lista* l, Esparsa* m){
    Lista* p = l;
    for(int i = 0; i < m->linhas; i++){
        for(int j = 0; j < m->colunas; j++){
            int n = buscar(p, i, j);
            printf("%d", n);
            printf("  ");
        }
        printf("\n");
    } 
}
void somatorio(Lista* l, int li){
    Lista* p;
    int soma = 0;
    for(p = l; p != NULL;p = p->prox){
        if(li == p->linha){
            soma += p->info;
        }
    }
    printf("soma = %d", soma);
}
void percentual_n_nulos(Esparsa* m){
    Lista* p;
    int cont = 0;
    for(p = m->prim; p != NULL; p = p ->prox){
        if(p->info != 0){
            cont++;
        }
    }
    float percent = (float) cont/ (m->colunas * m->linhas) * 100;
    printf("o percentual de numeros não nulos: %.2f", percent);
}
void liberar_lista(Esparsa* m) {
    Lista* p = m->prim;
    Lista* temp;
    while (p != NULL) {
        temp = p->prox; 
        free(p); 
        p = temp;     
    }
    free(m);
}

int main(){
    Esparsa* m;
    int n;
    m = cria_mat();
    printf("digite quantos valores voce ira inserir\n");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        m->prim = preencher_mat(m->prim);  
    }
    impressao(m->prim, m);
    int li, c;
    printf("digite a linha e a coluna do elemento que seja procurar\n");
    scanf("%d %d", &li, &c);
    printf("seu numero e: %d\n", buscar(m->prim, li, c));
    int lin;
    printf("digite a linha que vc deseja somar\n");
    scanf("%d", &lin);
    somatorio(m->prim, lin);
    percentual_n_nulos(m);
    liberar_lista(m);
}
