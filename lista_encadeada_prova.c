#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
        char nome [30];
        int idade;
        struct lista *proximo

}lista;

typedef struct NODO{
        int tam;
        struct lista *inicio;
}NODO;

void insere (struct NODO *a, int tam){
        lista *novo; int i=0;
        novo=(lista*) malloc (sizeof(lista));
        

        printf("\nDigite um nome: ");
        scanf("%s", &novo->nome);
        printf("\nDigite uma idade: ");
        scanf("%d", &novo->idade);
        novo->proximo=a->inicio;
        a->inicio=novo;
        
}

void lista (struct NODO *a, int tam ){
        struct lista *inicio=a->inicio;
        while(inicio!=NULL){
                printf("Nome da Pessoa, %s", inicio->nome);
                printf("Idade da Pessoa: %d", inicio->idade);
                inicio=inicio->proximo;
                }
        printf("\n\n");

}

void pop (struct NODO *a){
        lista *p;
        if(a->tam == 0){
        printf("Erro ao alocar.\n");
    }else{
        p = a->inicio;
        a->inicio = a->inicio->proximo;
        free(p);
        a->tam--;
    }
}
void clear (struct NODO *a){
    lista *x;
    
    if(a->tam == 0){
        printf("erro. pilha vazia.\n");
    }else{
        while(a->tam != 0){
            x = a->inicio;
            a->inicio = a->inicio->proximo;

            free(x);
            a->tam--;
        }
    }
}

int main (){
struct NODO *pdf;
int tam=0;

pdf=(lista*)malloc(sizeof(lista));
printf("\nDigite quantas pessoas deseja iserir: ");
scanf("%d", &tam);
printf("\nDigite 1 -para inserir\n2-para listar\n3-para remover\n4-para limpar\n5-para sair do programa");
while(op!=5){
scanf("%d", &op);
switch (op) {

case 1:
	insere(pdf,tam);
	break;
case 2:	
	lista(pdf, tam);
	break;
case 3: 	
	pop(pdf);
	break;
case4: 	
	clear(pdf);
break; 
case 5:
	printf("\nVoce Desligou o programa");
	exit;
break;	
}
}
    return 0;
}
