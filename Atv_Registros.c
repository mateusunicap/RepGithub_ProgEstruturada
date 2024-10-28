/*
Foi feita uma pesquisa nos 2 estados brasileiros para coletar dados sobre acidentes de trânsito e gerar algumas estatísticas. Em cada estado observaram-se os
seguintes aspectos: nome do estado, numero de veículos que circulam no estado (em
2007) e numero de acidentes de trânsito (em 2007). Faça um programa para:

OK - Coletar os dados dos 2 estados e armazenar em um vetor de estruturas.
    Para tal, construa um procedimento que irá solicitar ao usuário que informe os dados coletados de cada estado;
    -Nome do estado / numero de veículos que circulam no estado (em
    2007) / numero de acidentes de trânsito;

-Informar a maior e o menor numero de acidentes de trânsito e o nome dos estados
em que eles ocorreram. Para tal, construa um procedimento que receba como parâmetro o cadastro e tenha como parâmetros de saída (por referência) os índices (posição no cadastro) dos estados que possuem as características
solicitadas.A exibição dos dados deve ocorrer no programa principal.

-Informar o percentual de veículos envolvidos em acidentes de trânsito em cada
estado. Para tal, construa uma função que receba como parâmetro o cadastro e o
estado e retorne o percentual solicitado;

-Informar a media de acidentes no país. Para tal, construa uma função que receba
como parâmetro o cadastro e retorne a media solicitada. A exibição da media deve
ocorrer no programa principal;

-Informar o nome dos estados que estão acima da media de acidentes do país.
Para tal, construa um procedimento que receba como parâmetro o cadastro e a
media do pais e exiba os dados solicitados.
*/
#include <stdio.h>
#include <string.h>

#define TAM_MAX 50

struct dadosEstados
{
    char nomeDoEstado[TAM_MAX];
    int quantidadeDeCarrosCirculando;
    int numAcidentesTransito;
};

void lerStr(char *str, int tam);
int lerQtdCarrosCirculando();
int lerNumAcidentes();
void InformarAcidentes(struct dadosEstados listaDeEstados[], int tam);
float calcularPercentual(struct dadosEstados estado);
float calcularMediaAcidentes(struct dadosEstados listaDeEstados[], int tam);
void estadosAcimaMediaAcidentes(struct dadosEstados listaDeEstados[], int num, float mediaAcidentes);

int main()
{
    struct dadosEstados listaDeEstados[2];

    for (int i = 0; i < 2; ++i)
    {
        printf("----------------------------------------------------------------------------------------\n");

        printf("Digite o nome do estado: ");
        lerStr(listaDeEstados[i].nomeDoEstado, TAM_MAX);

        listaDeEstados[i].quantidadeDeCarrosCirculando = lerQtdCarrosCirculando();
        listaDeEstados[i].numAcidentesTransito = lerNumAcidentes();

        printf("----------------------------------------------------------------------------------------\n");
    }

    for (int i = 0; i < 2; ++i)
    {
        printf("Estado: %s, Carros: %d, Acidentes: %d\n",
               listaDeEstados[i].nomeDoEstado,
               listaDeEstados[i].quantidadeDeCarrosCirculando,
               listaDeEstados[i].numAcidentesTransito);
    }

    InformarAcidentes(listaDeEstados, 2);

    float mediaAcidentes = calcularMediaAcidentes(listaDeEstados, 2);
    printf("\nMedia de acidentes no país: %.2f\n", mediaAcidentes);

    for (int i = 0; i < 2; ++i)
    {
        float percentual = calcularPercentual(listaDeEstados[i]);
        printf("Percentual de acidentes no estado %s: %.2f%%\n", listaDeEstados[i].nomeDoEstado, percentual);
    }

    estadosAcimaMediaAcidentes(listaDeEstados, 2, mediaAcidentes);

    return 0;
}

void lerStr(char *str, int tam)
{
    fgets(str, tam, stdin);
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
}

int lerQtdCarrosCirculando()
{
    int qtd = 0;
    printf("Digite a quantidade de carros circulando no estado: ");
    scanf("%d", &qtd);
    while (getchar() != '\n')
        ;
    return qtd;
}

int lerNumAcidentes()
{
    int qtd = 0;
    printf("Digite a quantidade de acidentes: ");
    scanf("%d", &qtd);
    while (getchar() != '\n')
        ;
    return qtd;
}

void InformarAcidentes(struct dadosEstados listaDeEstados[], int tam)
{
    int maiorNumAcidentes = listaDeEstados[0].numAcidentesTransito;
    int menorNumAcidentes = listaDeEstados[0].numAcidentesTransito;
    char estadoMaior[TAM_MAX], estadoMenor[TAM_MAX];

    strcpy(estadoMaior, listaDeEstados[0].nomeDoEstado);
    strcpy(estadoMenor, listaDeEstados[0].nomeDoEstado);

    for (int j = 1; j < tam; ++j)
    {
        if (listaDeEstados[j].numAcidentesTransito < menorNumAcidentes)
        {
            menorNumAcidentes = listaDeEstados[j].numAcidentesTransito;
            strcpy(estadoMenor, listaDeEstados[j].nomeDoEstado);
        }
        if (listaDeEstados[j].numAcidentesTransito > maiorNumAcidentes)
        {
            maiorNumAcidentes = listaDeEstados[j].numAcidentesTransito;
            strcpy(estadoMaior, listaDeEstados[j].nomeDoEstado);
        }
    }

    printf("O menor numero de acidentes foi %d no estado %s\n", menorNumAcidentes, estadoMenor);
    printf("O maior numero de acidentes foi %d no estado %s\n", maiorNumAcidentes, estadoMaior);
}

float calcularPercentual(struct dadosEstados estado)
{
    if (estado.quantidadeDeCarrosCirculando == 0)
        return 0.0;
    return ((float)estado.numAcidentesTransito / estado.quantidadeDeCarrosCirculando) * 100;
}

float calcularMediaAcidentes(struct dadosEstados listaDeEstados[], int tam)
{
    int totalAcidentes = 0;
    for (int i = 0; i < tam; i++)
    {
        totalAcidentes += listaDeEstados[i].numAcidentesTransito;
    }
    return (float)totalAcidentes / tam;
}

// construa um procedimento que receba como parâmetro o cadastro e a
// media do pais
void estadosAcimaMediaAcidentes(struct dadosEstados listaDeEstados[], int tam, float mediaAcidentes)
{
    printf("Estados com numero de acidentes acima da media (%.2f):\n", mediaAcidentes);
    for (int i = 0; i < tam; i++)
    {
        if (listaDeEstados[i].numAcidentesTransito > mediaAcidentes)
        {
            printf("Estado: %s | Acidentes: %d\n", listaDeEstados[i].nomeDoEstado, listaDeEstados[i].numAcidentesTransito);
        }
    }
}
