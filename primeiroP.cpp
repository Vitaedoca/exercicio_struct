#include<stdio.h>
#include<string.h>
#include<windows.h>

struct dataNascimento {
    int dia, mes, ano;
};
struct Pessoa {
    dataNascimento dataNas;

    char nome[100];
   // int idade;
    char sexo[10];
};

int calcularIdade(int diaNascimento, int mesNascimento, int anoNascimento) {
    SYSTEMTIME st;
    GetLocalTime(&st);

    int idade = st.wYear - anoNascimento;

    if (mesNascimento > st.wMonth) {
        idade--;
    } else if (mesNascimento == st.wMonth) {
        if (diaNascimento > st.wDay) {
            idade--;
        }
    }
    return idade;
}
struct Pessoa vetorPessoas[5];


    int parar, i = 0, cont;

    int cadastrar() {
        if(cont > 50) {
            printf("Quantidade maxima de clientes cadastrados (50) clientes!!! \n");
        }else{

            printf("Digite o nome da pessoa: ");
            scanf("%s", vetorPessoas[i].nome);

           // printf("Digite a idade da pessoa: "); SE FOSSE PARA COLETAR A IDADE DA PESSOA
           // scanf("%d", &vetorPessoas[i].idade);

            printf("Digite a data de nacimento: ");
            scanf("%d %d %d", &vetorPessoas[i].dataNas.dia, &vetorPessoas[i].dataNas.mes, &vetorPessoas[i].dataNas.ano);

            printf("Digite sexo da pessoa: ");
            scanf("%s", &vetorPessoas[i].sexo);
            i++;
            cont = i;
            printf("\n");
        }
    }
    int imprimir() {
        for ( i = 0; i < cont; i++) {
            printf("LISTA DE CLIENTES\n");
            printf("Nome: %s \n", vetorPessoas[i].nome);
            printf("Idade: %d \n", calcularIdade(vetorPessoas[i].dataNas.dia, vetorPessoas[i].dataNas.mes, vetorPessoas[i].dataNas.ano));
            printf("Data: %02d/%02d/%04d \n", vetorPessoas[i].dataNas.dia, vetorPessoas[i].dataNas.mes,vetorPessoas[i].dataNas.ano);
            printf("Sexo: %s \n", vetorPessoas[i].sexo);
            printf("\n");
        }
    }

int main() {

        int menu;

        do{
            printf("1 Para cadastrar cliente: \n");
            printf("2 Listar cliente: \n");
            printf("0 Para Sair do pograma: \n");
            scanf("%d", &menu);
            if(menu == 1) {
                cadastrar();
            }else if(menu == 2) {
                if(cont < 1) {
                    printf("Voce ainda nao tem nenhum cliente cadastrados\n");
                }else{
                    imprimir();
                }
            }

        }while(menu != 0);




return 0;
}
