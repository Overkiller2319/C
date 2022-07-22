#include <stdio.h>
#include <stdlib.h>
        typedef struct arvore {
        int dados;
        int altura;
        struct ArvAVL *dir;
        struct ArvAVL *esq;
        } ArvAVL;
        
        typedef struct NO {
            int altura;
            struct ArvAVL *pesq;
            struct ArvAVL *pdir;
        }   NO; 



        ArvAVL *raiz;
        
    ArvAVL* cria_ArvAVL(ArvAVL *a){
        ArvAVL* a = (ArvAVL*) malloc(sizeof(ArvAVL));
        if(a != NULL)
            a = NULL;
        return a;
    }
   int ARV_altura(ArvAVL *raiz) {
       int pesq, pdir;                                  //Devia receber uma raiz ou um nó e calcular cada altura desses para o depois levar ao  FB
            if (raiz == NULL)
            return 0;
            if (raiz==NULL) 
            return 0;
            pesq = ARV_altura(&((*raiz)->esq));
            pdir = ARV_altura(&((*raiz)->dir));
            if ( pesq > pdir )
            return pesq + 1;
            else
            return  pdir + 1;
    }     

    int FB (ArvAVL *raiz){
        if (raiz == NULL){
            return 0;    }
            return altura_NO(raiz->esq) - altura_NO(raiz->dir);
    }

    void RotacaoSimplesaDireita(ArvAVL *raiz){                               
        struct ArvAVL *no;                                                      //nó que precisa ser balanceado é apontado por no auxiliar//    
        no=(ArvAVL* )malloc(sizeof(ArvAVL));
        no = raiz->esq;                                                                     
         raiz->esq = no->dir;                                                  //filho da esquerda recebe filho da direita//         
         no->dir = *raiz;                                                      //filho da direita recebe a raiz para realizar a rotação da nova raiz// 
         raiz->altura=max(altura_NO(raiz->esq),altura_NO(raiz->dir))+1;
         no->altura=max(altura_NO(no->pesq),raiz->altura)+1;
         *raiz=no;
    }
        int altura_NO(struct ArvAVL* no){
        if(no == NULL)
            return -1;
        else
        return no->altura;
        }

        int max(int a, int b){              //calcula o maior valor para o FB//
            if(a > b)
                return a;
            else
                return b;
        }
    
        
    void RotacaoSimplesaEsquerda (ArvAVL *raiz){
        struct ArvAVL *No ;
        No=(ArvAVL*)malloc(sizeof(ArvAVL));
        No=raiz->dir;
        raiz->dir= No->esq;
        No->esq = (*raiz);
        raiz->altura = max(altura_NO(raiz->esq), altura_NO(raiz->dir))+1;
        No->altura=max(altura_NO(No->dir), raiz->altura)+1;
        raiz=No;
    }
            void RotacaoLR(ArvAVL *raiz){      //Rotação dupla a direita
                RotacaoRR(&(*A)->esq);
                RotacaoLL(A);
            }

            void RotacaoRL(ArvAVL *raiz){      //Rotação dupla a esquerda
                RotacaoLL(&(*A)->dir);
                RotacaoRR(A);
            }

    int insere (ArvAVL *raiz, int valor){
    int aux;
    if(*raiz == NULL){
        struct ArvAVL *new;
        new = (struct NO*)malloc(sizeof(struct NO));
        if(new == NULL)
            return 0;

        new->dados = valor;
        new->altura = 0;
        new->esq = NULL;
        new->dir = NULL;
        *raiz = new;
        return 1;
    }
    struct ArvAVL *atual = raiz;
        if(valor < atual->dados){
            if((aux = insere(&(atual->esq), valor)) == 1){
                if(FB(atual) >= 2){
                    if(valor < (*raiz)->esq->dados ){
                        RotacaoSimplesaDireita(raiz);
                    }else{
                        RotacaoLR(raiz);
                    }
                }
            }
        }else{
            if(valor > atual->dados){
                if((aux = insere(&(atual->dir), valor)) == 1){
                    if(FB(atual) >= 2){
                        if((*raiz)->dir->dados < valor){
                            RotacaoSimplesaEsquerda(raiz);
                        }else{
                            RotacaoRL(raiz);
                        }
                    }
                }
            }else{
                printf("Valor duplicado!!\n");
                return 0;
            }
        }

        atual->altura = max(altura_NO(atual->esq),altura_NO(atual->dir)) + 1;

        return aux;
    }
    
    void lista (ArvAVL *raiz){
        if(*raiz != NULL){
            printf("%d\n", raiz->dados);
            lista(*raiz->esq);
            lista(*raiz->dir);
        }
    }


int main (){
int valor;
struct ARVAvl *arv; 
cria_ArvAVL (raiz);
printf("Digite um valor para inserir na sua arvore: ");
scanf("%d", &valor);
insere(arv, valor);
printf("\n-------------\n");
lista(arv);







    return 0;
}