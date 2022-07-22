#include <stdio.h>
#include <stdlib.h>
                                    //1- Faça um programa que armazene as informações de várias pessoas.
                                    //O programa dever ser desenvolvido com o conceito de alocação dinâmica.
                                    //Além da opção de inserção, o programa deve possuir um menu que
                                    //permita listar todos os dados das pessoas inseridas e também a opção
                                    //excluir uma determinada pessoa pelo nome. Use a estrutura que segue:
                                    // typedef struct{ char nome[30]; int idade;int altura; }Pessoa;
 typedef   struct dados 
 {
        char nome [30];
        int numero;
        int idade;
        int altura;
 };
 
 int main (){
     struct dados alunos [30];
     int i=0, num_alu, key=0, num=0;
     char deleta[30];


    printf("Quantos alunos voce deseja inscrever? ");
    scanf("%d", &num_alu);

    for(i=0;i<=num_alu;i++){
        printf("\nDigite o nome do aluno [%d]: ", i);
        scanf("%s", &alunos[i].nome);
        printf("\nDigite o numero de cadastro [%d]: ", i);
        scanf("%d", &alunos[i].numero);
        printf("\nDigite a idade do aluno[%d]: ", i);
        scanf("%d", &alunos[i].idade);
        printf("\nDigite a altura do aluno [%d]: ", i);
        scanf("%d", &alunos[i].altura);
    }
    for(i=0;i<=num_alu;i++){
        printf("\nNome do aluno [%d]: %s",i, alunos[i].nome );
        printf("\nIdade do alano [%d]: %d", i, alunos[i].idade);
        printf("\nAltura do aluno [%d]: %d", i, alunos[i].altura);
        printf("\nNumero de cadastro: %d", alunos[i].numero);
    
    }
    printf("\nDigite 1 para deletar algum aluno ou 0 para acabar o programa? ");
    scanf("%d", &key);
        if (key==1){
                printf("\nDigite o nome da pessoa: ");
                scanf("%s", &deleta);
                printf("\nDigite o numero da pessoa: ");
                scanf("%d", &num);

                for(i=0;i<=num_alu;i++){
        if(num==alunos[i].numero){
                printf("Aluno %s\n FOI REMOVIDO", alunos[i].nome);
        }
                }


}
        else{
                printf("\n------CADASTRO FEITO COM SUCESSO-----");
            }




return 0;
 }