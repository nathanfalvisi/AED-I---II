// Projeto feito por: Joao Gabriel, Nathan, Victor e Wesley.

#include <stdio.h> // Usada para as funções padrões
#include <string.h> // Usada para manipular strings
#include <time.h> // Usada para a função time
#include <graphics.h> // Usada no modo gráfico
#define MAX 200 // Define uma faixa de 200 para "MAX".

typedef struct   // Struct com os dados que serão usados no cadastro do cliente
{
    char nome[50];
    char objetivo[20];
    float peso, altura;
    int matricula, opcao;
} dados; // Nome do tipo do Struct

void cadastro(dados p[], int numClientes)   // Função que usa o vetor "p" a partir do Struct do tipo "dados",em conjunto com a faixa numClientes.
{
    system("cls"); // Limpa as mensagens do prompt.
    char textoGraph[100]; // String auxiliar para mostrar a mensagem do número de matrícula
    char matriculaStr[10]; // String que irá mostrar o número de matrícula que foi gerado na janela gráfica

    initwindow(600,500,"Cadastro",450,180); // 500 e 400 são a altura e largura da janela, "Cadastro" é o nome da janela, e 400 e 180 suas coordenadas.
    setcolor(WHITE); // Define a cor do texto como branca.

    outtextxy(100, 50, "Digite as informacoes do cliente:"); // outtextxy exibe mensagens na tela em coordenadas x e y, como dito na própria função.
    outtextxy(100, 100, "Nome completo: "); // Texto escrito nas coordenadas x = 100 e y = 100.
    gets(p[numClientes].nome);
    sprintf(textoGraph, "%s", p[numClientes].nome);
    fflush(stdin); // Limpa o buffer do teclado, evitando problemas ao fazer várias entradas consecutivas de dados.
    outtextxy(250, 100, textoGraph);

    outtextxy(100, 120, "Altura: ");
    scanf("%f", &p[numClientes].altura); //  Lê os dados do usuário e armazena no campo "altura" da estrutura "dados".
    sprintf(textoGraph, "%.2f", p[numClientes].altura);
    fflush(stdin);
    outtextxy(250, 120, textoGraph);

    outtextxy(100, 140, "Peso: ");
    scanf("%f", &p[numClientes].peso);
    sprintf(textoGraph, "%.2f", p[numClientes].peso);
    fflush(stdin);
    outtextxy(250, 140, textoGraph);

    outtextxy(100, 160, "Objetivo: ");
    gets(p[numClientes].objetivo);
    sprintf(textoGraph, "%s", p[numClientes].objetivo);
    fflush(stdin);
    outtextxy(250, 160, textoGraph);

    p[numClientes].matricula = 0; // Atribui valor da variável em 0 para evitar problemas com lixo de memória.
    for (int i = 0; i < 6; i++)   // Repetição utilizada para obter o número de matrícula a partir de números aleatórios.
    {
        p[numClientes].matricula = p[numClientes].matricula * 10 + rand() % 10; // A cada iteração, o valor anterior de "matricula" é multiplicado por 10 e somando de 0 a 9.
    }

    sprintf(matriculaStr, "%d", p[numClientes].matricula); // sprintf foi usado para exibir as strings "matriculaStr" e "cliente", por ser uma função especializada para strings.
    sprintf(textoGraph, "Numero de matricula gerada para %s foi %d", p[numClientes].nome, p[numClientes].matricula);

    setcolor(WHITE);
    outtextxy(100, 200, textoGraph);

    int opcaoValida = 0; // Variável declarada para ser utilizada no switch-case, declarada com valor de 0 para remoção do lixo de memória.
    while (!opcaoValida)   // ! causa inversão lógica, logo sempre será executado quando "opcaoValida" for falso.
    {
        outtextxy(100, 240, "1. Plano Mensal");
        outtextxy(100, 260, "2. Plano Trimestral");
        outtextxy(100, 280, "3. Plano Semestral");
        outtextxy(100, 300, "4. Plano Anual");
        outtextxy(100, 340, "Digite uma das opcoes: ");
        scanf("%d", &p[numClientes].opcao);
        fflush(stdin);

        switch (p[numClientes].opcao)
        {
        case 1:
            outtextxy(100, 380, "Plano Mensal");
            opcaoValida = 1; // Caso executada, opcaoValida ganha valor de 1 e possibilita finalizar a execução do switch-case.
            break;
        case 2:
            outtextxy(100, 380, "Plano Trimestral");
            opcaoValida = 1;
            break;
        case 3:
            outtextxy(100, 380, "Plano Semestral");
            opcaoValida = 1;
            break;
        case 4:
            outtextxy(100, 380, "Plano Anual");
            opcaoValida = 1;
            break;
        default:
            outtextxy(100, 380, "Opcao invalida. Digite novamente.");
        }
    }

    closegraph(); // Fecha o modo gráfico.
}

void mostrarClientes(dados p[], int numClientes)   // Função que usa o registro tipo "dados" com o vetor "p", e a faixa numClientes.
{
    system("cls");
    printf("Clientes cadastrados:\n\n");
    for (int i = 0; i < numClientes; i++)   // A repetição acontece enquanto "i" for menor que o número de clientes registrados.
    {
        printf("Cliente %d\n\n",i + 1); // Identificação do número de registro do cliente, acrescenta +1 para cada repetição.
        printf("Nome: %s\n", p[i].nome); // Mostra os dados contidos no vetor "p" de índice "i" na variável "nome" da estrutura Struct.
        printf("Altura: %.2f\n", p[i].altura);
        printf("Peso: %.2f\n", p[i].peso);
        printf("Objetivo: %s\n", p[i].objetivo);
        printf("Matricula: %d\n", p[i].matricula);
        switch (p[i].opcao) //
        {
        case 1:
            printf("Plano: Mensal\n");
            break; // Sai do switch após a execução do bloco.
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

int main()
{
    dados pessoas[MAX]; // Struct do tipo dados, e uma variável do tipo pessoas foi atribuída, usando a faixa "MAX" definida com uma faixa de 200.
    int opcao, numClientes = 0; // "opcao" é usada no switch-case do menu principal, "numClientes" é usada no código todo para controlar os cadastros e registros.
    srand(time(NULL)); // Função usada para obter números aleatórios usando o horário do sistema.

    while (1)   // while com valor de 1 sempre fará com que o menu funcione
    {
        printf("1. Cadastrar novo cliente\n");
        printf("2. Mostrar clientes cadastrados\n");
        printf("3. Sair\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opcao);
        fflush(stdin);
        printf("\n"); // Quebra de linha para melhorar a leitura do código.

        system("cls");
        switch (opcao)
        {
        case 1:
            cadastro(pessoas, numClientes);
            numClientes++;
            break;
        case 2:
            mostrarClientes(pessoas, numClientes);
            break;
        case 3:
            printf("Encerrando o programa...\n");
            return 0; // Retorna 0, encerra o programa.
        default:
            printf("Opcao invalida! Digite novamente.\n");
        }
    } while (opcao != '3'); // Executa enquanto o valor definido para "opcao" for diferente de 3.
    return 0;
}
