#include <stdio.h> 
#include <string.h> 
#include <time.h> 
#include <windows.h>
#define MAX 200 

typedef struct   
{
    char nome[50];
    char objetivo[20];
    float peso, altura;
    int matricula, opcao;
} dados; 

void cadastro(dados p[], int *NumClientes)   
{
    system("cls"); 

    printf("Digite as informacoes do cliente:\n"); 
    
    printf("Nome completo: \n"); 
    gets(p[*NumClientes].nome);
    fflush(stdin); 

    printf("Altura: \n");
    scanf("%f", &p[*NumClientes].altura); 
    fflush(stdin); 


    printf("Peso: \n");
    scanf("%f", &p[*NumClientes].peso);
    fflush(stdin);

    printf("Objetivo: \n");
    gets(p[*NumClientes].objetivo);
    fflush(stdin);

    p[*NumClientes].matricula = 0; 
    for (int i = 0; i < 6; i++)   
    {
        p[*NumClientes].matricula = p[*NumClientes].matricula * 10 + rand() % 10; 
    }

    int opcaoValida = 0; 
    while (!opcaoValida)   
    {
        printf("1. Plano Mensal\n");
        printf("2. Plano Trimestral\n");
        printf("3. Plano Semestral\n");
        printf("4. Plano Anual\n");
        printf("Digite uma das opcoes: ");
        scanf("%d", &p[*NumClientes].opcao);
        fflush(stdin);

        switch (p[*NumClientes].opcao)
        {
        case 1:
            printf("Plano Mensal\n");
            opcaoValida = 1; 
            break;
        case 2:
            printf("Plano Trimestral\n");
            opcaoValida = 1;
            break;
        case 3:
            printf("Plano Semestral\n");
            opcaoValida = 1;
            break;
        case 4:
            printf("Plano Anual\n");
            opcaoValida = 1;
            break;
        default:
            printf("Opcao invalida. Digite novamente.\n");
        }
    }
    *NumClientes += 1;
}

void mostrarClientes(dados p[], int NumClientes) 
{
    system("cls");
    printf("Clientes cadastrados:\n\n");
    for (int i = 0; i < NumClientes; i++)   
    {
        printf("Cliente %d\n\n",i + 1); 
        printf("Nome: %s\n", p[i].nome); 
        printf("Altura: %.2f\n", p[i].altura);
        printf("Peso: %.2f\n", p[i].peso);
        printf("Objetivo: %s\n", p[i].objetivo);
        printf("Matricula: %d\n", p[i].matricula);
        switch (p[i].opcao) //
        {
        case 1:
            printf("Plano: Mensal\n");
            break; 
        case 2:
            printf("Plano: Trimestral\n");
            break;
        case 3:
            printf("Plano: Semestral\n");
            break;
        case 4:
            printf("Plano: Anual\n");
            break;
        }
        printf("---------------------\n");
    }
}

main()
{
    dados pessoas[MAX]; 
    int opcao, NumClientes = 0; 
    srand(time(NULL)); 

    while (1)   
    {
        printf("1. Cadastrar novo cliente\n");
        printf("2. Mostrar clientes cadastrados\n");
        printf("3. Sair\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opcao);
        fflush(stdin);
        printf("\n"); 

        system("cls");
        switch (opcao)
        {
        case 1:
            cadastro(pessoas, &NumClientes);
            //*NumClientes++;
            break;
        case 2:
            mostrarClientes(pessoas, NumClientes);
            break;
        case 3:
            printf("Encerrando o programa...\n");
        default:
            printf("Opcao invalida! Digite novamente.\n");
        }
    } while (opcao != '3'); 
}
