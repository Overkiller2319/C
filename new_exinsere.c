#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
        char nome [30];
        int idade;
        struct lista *proximo;
        struct lista *inicio;
        struct lista *fim;
}lista;

        lista* cria_lista(void *a) {
                 a = (lista*) malloc(sizeof(lista));
                if(a != NULL) {
                a= NULL;
                 }
                return a;
         }

void insere (struct lista *a, int tam){
        lista *novo; 
        lista *velho=a->proximo;
        
        velho=(lista*)malloc(sizeof(lista));
        novo=(lista*) malloc (sizeof(lista));
       
                if(novo==NULL){
               printf("ERRO AO ALOCAR MEMORIA\n");
                return 2;
       }
       if(velho==NULL){
               printf("ERRO AO ALOCAR MEMORIA\n");
                return 2;
       }
                 
                printf("\nDigite um nome: ");
                scanf("%s", &novo->nome);
                printf("\nDigite uma idade: ");
                scanf("%d", &novo->idade);
                
                if(a->inicio==NULL){
                         novo->proximo=a->inicio;
                        a->inicio=novo;                       
                        printf("\n\nChegamos No if a->inicio==NULL!"); 
                                }
                else {
                
                        novo->proximo=a->inicio;
                        a->inicio=novo;
                        
                        }        
                                          
           printf("\nChegamos ate aqui!");     
}

void listar (struct lista *a, int tam ){
        struct lista *inicio=a->inicio;
        struct lista *fim=a->fim ;           

        while(inicio!=NULL){
                printf("\nNome da Pessoa: %s", inicio->nome);
                printf("\nIdade da Pessoa: %d", inicio->idade);
                inicio=inicio->proximo;
                inicio++;
                }
        printf("\nFim da lista\n");

}
void pop (struct lista *a){
        if(a->proximo == NULL){
        printf("Nada aqui.Volte na proxima\n");
         }else{
                struct lista *x;
                x = a->proximo;
                a->proximo = x->proximo;
                free(x);
                }
        }
}
void clear (struct lista *a){
         strcut lista *x;
             x = a->proximo;
             a->proximo = x->proximo;
             free(x);
             
        
}

int main (){
struct lista *pdf;
int tam=0, i=0;

pdf=(lista*)malloc(sizeof(lista));

printf("\nVezes a executar: ");
scanf("%d", &tam);

for (i=0;i<tam;i++){
insere(pdf, tam);
}
listar(pdf, tam);
printf("\nERRO 404\n");
pop(pdf);
limpa(pdf);

system ("pause");

    return 0;
}
