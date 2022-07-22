#include <stdio.h>
#include <stdlib.h>
#include <time.h>
                    insertionsort (int vet[], int n){
                        int tmp,i,j;
                        for (j=1; j<n; j++) {
                        i =j - 1;
                        tmp = vet[j];
                        while ( (i>=0) && (tmp < vet[i]) ) {
                        vet[i+1] = vet[i];
                        i--;
                        }//while
                        vet[i+1] = tmp;
                        }
                            for (i=0;i<n;i++){
                            printf("\nvetor insertion: %d", vet[i]); 
                            }
                            
                        }
                    selectionsort (int vet[], int n){
                            int menor , i, j , troca ;

                            for (i=0;i<n-1;i++){
                                menor = i;
                            for(j=i+1;j<n;j++){
                                if(vet[j]<vet[menor]){
                                    menor=j;
                                }
                                troca = vet[menor];
                                vet[menor]=vet[i];
                                vet[i]=troca;
                            }
                            }
                        for (i=0;i<n;i++){
                            printf("\nvetor selection: %d", vet[i]); 
                            }
                        printf("\n\n-----------------\n");
                    }




int main (){
int n, i;

printf("Digite o tamanho do seu vetor: ");
scanf("%d", &n);

int vet[n];
srand(time(NULL));
for (i=0;i<n;i++){
vet[i] = rand()%100;
}
selectionsort(vet, n);
insertionsort (vet, n);




    return 0;
}