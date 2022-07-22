#include <stdio.h>
#include <stdlib.h>
#include <time.h>

    selectionsort(int arr[], int n)  
{  
    int i, j, small;  
      
    for (i = 0; i < n-1; i++)    // One by one move boundary of unsorted subarray  
    {  
        small = i; //minimum element in unsorted array  
          
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[small])  
            small = j;  
// Swap the minimum element with the first element  
    int temp = arr[small];  
    arr[small] = arr[i];  
    arr[i] = temp;  
    }  
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
for(i=0;i<n;i++){
printf("\nSelection[%d]: %d ", i, vet[i]);
}


return 0;
}