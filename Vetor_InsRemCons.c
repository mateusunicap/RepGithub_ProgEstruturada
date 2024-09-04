#include <stdio.h>
/*
1-INPUT do usuario digitar o tamanho do vetor que ele deseja (3-50 elementos)

2-INPUT do usuario a quantidade de valores inteiro para preencher esse vetor*
    Já faz a INSERÇÃO ORDENADA

Mostrar o MENU:
    1-Imprimir todo o vetor (cuidado que o tamanho do vetor pode ser alterado por outras opções)
    2-Consultar (via busca binária) em que posição um elemento se encontra dentro do vetor (-1 para não encontrado)
    3-Remover um elemento (se não encontrar, não fazer nada, se encontrar, deslocar os elementos à direita para não ter nenhum posição vazia, e diminuir o tamanho do vetor)
    4-Inserir (apenas 1 valor) no vetor (lembrando que precisa estar dentro da capacidade do vetor que no máximo é 50) de forma ordenada e essa operação quando tem sucesso, aumenta o tamanho do vetor.
*/

int main(int val, int tam, int opc)
{
    // Tamanho do vetor
    int i, j, qtd;
    printf("Digite a quantidade de valores: ");
    scanf("%d", &qtd);

    int v[qtd];

    // Preencher o vetor
    for (i = 0; i < qtd; ++i)
    {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &val);

        for (j = i; j > 0 && v[j - 1] > val; --j)
        {
            v[j] = v[j - 1];
        }
        v[j] = val;
    }


    // MENU
    printf("\nDigite a opcao que deseja:\n");
    printf("1 - Imprimir todo o vetor\n");
    printf("2 - Consular em que posicao o elemento digitado esta.\n");
    printf("3 - Remover um elemento\n");
    printf("4 - Inserir +1 valor ao vetor\n");
    scanf("%i", &opc);

    if (opc == 1)
    {
        // Imprimir todo o vetor
        printf("Vetor completo:\n");
        for (int i = 0; i < qtd; ++i)
        {
            printf("%i;", v[i]);
        }
    }
    else if (opc == 2)
    {
        // Consular em que posição o elemento digitado está
        int i;
        printf("Digite o valor que deseja consultar: ");
        scanf("%i", &i);
    }
    else if (opc == 3)
    {
        // Remover um elemento
    }
    else if (opc == 4)
    {
        // Inserir +1 valor ao vetort
    }
    else
    {
        printf("Opcao invalida.");
    }
}
