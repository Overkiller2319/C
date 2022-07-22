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
        NODO* cria_lista(void *a) {
        NODO* pilha = (NODO*) malloc(sizeof(NODO));
        if(pilha != NULL) {
        pilha= NULL;
        }
        return pilha;
        }


void insereini (struct NODO *a, int tam){
        lista *novo; int i =0;
        lista *velho;
                
        novo=(lista*) malloc (sizeof(lista));
       
       if(novo==NULL){
               printf("ERRO AO ALOCAR MEMORIA\n");
                return 2;
       }
        for(i=0;i<tam;i++){                     //Adiciona um n° de elementos igual a tam
        printf("\nDigite um nome: ");
        scanf("%s", &novo->nome);
        printf("\nDigite uma idade: ");
        scanf("%d", &novo->idade);

             if(a->inicio==NULL){
                novo->proximo=a->inicio;
                a->inicio=novo;
                   free(novo);
                          }
             else {
                    novo->proximo=a->inicio;
                    a->inicio=novo; 
                    novo->proximo=NULL;        
                  }        
        }     
        return 1;
        
}

void imprime (struct NODO *a, int tam ){
        struct lista *inicio=a->inicio;
                

        while(inicio!=NULL){
                printf("\nNome da Pessoa: %s", inicio->nome);
                printf("\nIdade da Pessoa: %d", inicio->idade);
                inicio=inicio->proximo;
                }
        printf("\nFim da lista\n");

}


int main (){
struct NODO *pdf;
int tam=0;

pdf= (NODO*) malloc(sizeof(NODO));
printf("\nDigite quantas pessoas deseja iserir: ");
scanf("%d", &tam);
insereini(pdf,tam);
imprime(pdf, tam);




    return 0;
}