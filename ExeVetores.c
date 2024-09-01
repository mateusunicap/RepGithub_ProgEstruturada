#include <stdio.h>

int main()
{
    int QTD, i, j, valor;

    printf("Digite a quantidade de valores: ");
    scanf("%d", &QTD);

    int v[QTD];

    for (i = 0; i < QTD; ++i)
    {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &valor);

        for (j = i; j > 0 && v[j - 1] > valor; --j)
        {
            v[j] = v[j - 1];
        }
        v[j] = valor;
    }

    printf("Vetor: ");
    for (i = 0; i < QTD; ++i)
    {
        printf("%d ", v[i]);
    }

    return 0;
}
