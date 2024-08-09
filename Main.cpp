# include <stdio.h> //biblioteca de comunicação com o usuário
# include <stdlib.h> //biblioteca de alocação de espaço em memória
# include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel pelas strings

int registro() 
{
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o seu CPF: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf); //copiar os valores das strings no arquivo

    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w");
    fprintf(file, cpf); //salva o valor da variavel
    fclose(file); //fecha o arquivo

    file = fopen(arquivo, "a");
    fprintf(file, ", ");
    fclose(file);

    printf("Digite o seu nome: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ", ");
    fclose(file);

    printf("Digite o seu sobrenome: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ", ");
    fclose(file);

    printf("Digite o seu cargo: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);
}

int consulta()
{
    setlocale(LC_ALL, "");
    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if(file == NULL) {
        printf("CPF não foi localizado.\n");
    }

    while (fgets(conteudo, 200, file) != NULL) {
        printf("\nEssas são as informações do usuário: ");
        printf("%s", conteudo);
        printf("\n\n");
    }
    system("pause");
}

int deletar() 
{
    char cpf[40];

    printf("Digite o CPF a ser deletado : ");
    scanf("%s", cpf);
    remove(cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if(file == NULL) {
        printf("O usuário não existe.");
        system("pause");
    }
}

int main()
{
    int opcao = 0; //devo armazenar essa variável em 0 para que o computador não defina o valor dela aleatoriamente
    int laco = 1;

    for (laco=1;(laco=1);)
    {

        system("cls");
    
        setlocale(LC_ALL, ""); // Faz a máquina entender que estou usando a língua portuguesa

        printf("\t#### Cartório ####\n\n");
        printf("\tEscolha a opção desejada:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Sair do sistema\n");
        printf("Opção:");

        scanf("%d", &opcao); //%d significa que irei usar um input de tipo inteiro e o & indica que armazenarei o inteiro na variavel opcao
        system("cls"); //deleta o que estava no console

        switch(opcao)
        {
            case 1:
            registro();
            break;

            case 2:
            consulta();
            break;

            case 3:
            deletar();
            break;

            case 4:
            printf("Obrigado por utilizar o sistema!\n");
            return 0;
            break;

            default:
            printf("Essa opção não está disponível\n");
            printf("Volte para o menu: ");
            system("pause");
            break;
        }

    }
}