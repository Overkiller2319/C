#include <stdio.h>
#include <stdlib.h>

	
	typedef struct info {
	int num;
	struct info *prox;
	}INFO;

void insere(int x, INFO *y)
{
	INFO *nova;
	INFO *velho=y->prox;
	nova = malloc(sizeof(INFO));
	nova->num = x;
	y->prox = nova;
	nova->prox = velho;
	
}
void imprime (INFO *head)
{
	INFO *aux;
	if((aux=malloc(sizeof(INFO)))==NULL){
		printf ("ERRO EM IMPRIME");
		exit(1);
										}
	aux=head->prox;  //aux recebe primeoro elemento
	while(aux!=NULL){
		printf("%d\n", aux->num);
		aux=aux->prox;
					}
}

void insere_fim(int x, INFO *head)
{
	INFO *no;
	if((no=malloc(sizeof(INFO)))==NULL){
		printf ("ERRO EM INSERE_FIM");
		exit(1);
										}
	no->num=x;
	no->prox=NULL;
	
		if(head==NULL){head=no;}
		else{
			INFO *aux=head;
			while(aux->prox!=NULL){
				aux=aux->prox;
									}
				aux->prox=no;					
			}
}
void remova (INFO *head)
{		
		INFO *no=head;
		no=head->prox;
		head->prox=no->prox;
		free(no);
	
}
void remova_fim (INFO *head)
{		
		INFO *antigo, *no=head;
		while(no->prox!=NULL){
			antigo=no;
			no=no->prox;
							 }
			if(no==head){
				head=no->prox;
						}				 
			else{
				antigo->prox=no->prox;
				free(no);
				}				
}
void apaga_ele(int x, INFO * head)
{		
		INFO *no, *aux;
		no = head;
		aux = head->prox;
			while ((aux != NULL) && (aux->num != x)) {
				no = aux;
				aux = aux->prox;
								}
				if (aux != NULL) { 
				no->prox = aux->prox;
				free(aux);
								}
}
void busca(int x, INFO * head)
{		
		INFO *no, *aux;
		no = head;
		aux = head->prox;
			while ((aux != NULL) && (aux->num != x)) {
				no = aux;
				aux = aux->prox;
								}
				if (aux != NULL) { 
				no->prox = aux->prox;
				printf("Elemento encontrado: %d\n", no);
								}
				else{printf("Elemento não existe\n");	}		
}

int main(){
int x=0;
int caso=0;
INFO *lista;

lista=malloc(sizeof(INFO));
	if(lista== NULL){
	printf("Erro");
	exit(1);
							}

printf("1. Imprimir a lista\n2. Inserir um numero na primeira posição lista,\n3. Inserir um numero na ultima posição da\n4. Apagar o primeiro element da lista\n5. Apagar o ultimo elemento\n6. Apagar um elemento com base no seu numero.\n7. Buscar se um numero existe ou não na lista\n8. Terminar o programa.\n");
while(caso!=8){
scanf("%d",&caso);

switch (caso){
case 1:
	imprime(lista);
	break;
case 2:
	printf("Digite um número: ");
	scanf("%d", &x);
	insere(x,lista);
	break;
case 3:
	printf("Digite um número: ");
	scanf("%d", &x);
	insere_fim(x, lista);
	break;
case 4:
	printf("\n1 Elemento da lista apagado\n");
	remova(lista);
	break;
case 5:
	printf("\nÚltimo Elemento da lista apagado\n");
	remova_fim(lista);
	break;
case 6:
	printf("Numero a ser apagado:\n");
	scanf("%d", &x);
	apaga_ele(x,lista);
	break;
case 7:
	printf("Numero a ser procurado:\n");
	scanf("%d", &x);
	busca(x, lista);
	break;
case 8:
printf("\nVoce Desligou o programa");
	exit;
break;	

default:
	printf("Valor invalido");

}
}
return 0;
}
