#include <stdio.h>
#include <stdlib.h>

typedef struct Fila {
    struct Info *pFirst;
    struct Info *pLast;

}Fila;

typedef struct Produto {
    int idade;
    char nome [40];
    }Produto;

typedef struct Info {
    struct Produto  info;
    struct Fila *pNext;
}Info;

 Info* cria_lista(void *a) {
        Info* pilha = (Info*) malloc(sizeof(Info));
        if(pilha != NULL) {
        pilha= NULL;
        }
        return pilha;
        }

void PUSH (Fila *aFila, Produto *aProd){
    struct Info *pNovo;
    pNovo=(Info*)malloc(sizeof(Info));
    pNovo->info = *aProd;
    pNovo->pNext = NULL;

        if (aFila->pLast!=NULL){
            aFila->pLast->pNext = pNovo;
        }
        else {
            aFila->pFirst= pNovo;
        }
        aFila->pLast=pNovo;
    
}

void IMPRIME (Fila *aFila, Produto *aProd){
        struct Info *pNovo;
        pNovo=(Info*)malloc(sizeof(Info));
        pNovo->info= aFila->pFirst->info;

        while(aProd != NULL){
            printf("\nIdade: %d", pNovo->info.idade);
            printf("\nNome: %s", pNovo->info.nome);
            printf("\n\n");
            pNovo->info= pNovo->pNext->pFirst->info;
        }

}

void POP (Fila *aFila, Produto *pProd){
    Info *pNodo;

    if (aFila->pFirst == NULL){
        puts("Nada na Fila");
        return 0;
    }
    else {
        pNodo=aFila->pFirst;
        *pProd = aFila->pFirst->info;
        aFila->pFirst = aFila->pFirst->pNext;
        
        }
    if (aFila->pFirst == NULL){
        aFila->pLast = NULL;
    }
    
    free(pNodo);
    printf("\nNÃO EH PARA APARECER NADA\n");
    printf("Codigo: %d", pNodo->info.idade);
    printf("Nome: %s", pNodo->info.nome);
    return 1;
    
}


int main (){
Produto *ptr;
Fila *primeiro;

ptr=(Produto*)malloc(sizeof(Produto));
primeiro=(Fila*)malloc(sizeof(Fila));


printf("Digite um codigo: ");
scanf("%d", &ptr->idade);
printf("\nDigite um nome: ");
scanf("%s", &ptr->nome);

PUSH(primeiro, ptr);
IMPRIME(primeiro, ptr);
POP(primeiro, ptr);



    return 0;
}