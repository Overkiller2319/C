#include <stdio.h>
#include <stdlib.h>

Insertionsort (int data[], int n) {
int tmp,i,j;
for (j=1; j<n; j++) {
i =j - 1;
tmp = data[j];
while ( (i>=0) && (tmp < data[i]) ) {
data[i+1] = data[i];
i--;
}//while
data[i+1] = tmp;
}//for
}//Insertionsort

int main (){
int a[5], n=5, i=0;

printf("Digite os valores para um vetor: \n");
for(i=0; i<n;i++)
{
    printf("Valor [%d]: ", i);
    scanf("%d", &a[i]);
}
Insertionsort(a[5], n);

for(i=0; i<n;i++){
printf("VALOR DO VETOR ORDENADO: %d\n", a[i]);
}



    return 0;
}