#include <stdio.h>

#define SIZE 100

int x[SIZE], n, k;

int verificare(int p)
{
    for (int i = 1; i < p; i++)
    {
        if (x[p] == x[i])
        {
            return 0;
        }
    }
    if(p > 1)
    {
        if(x[p] < x[p- 1])
        {
            return 0;
        }
    }
    return 1;
}

int solutie(int p)
{
    return p == k;
}

void afisare()
{
    for (int i = 1; i <= k; i++)
    {
        printf("%d ", x[i]);
    }
    printf("\n");
}

void combinari(int k)
{
    for (int i = 1; i <= n; i++)
    {
        x[k] = i;
        if (verificare(k))
        {
            if (solutie(k))
            {
                afisare();
            }
            else
            {
                combinari(k + 1);
            }
        }
    }
}

int main(void)
{
    printf("Introdu numarul n: ");
    scanf("%d", &n);
    printf("Introdu numarul k: ");
    scanf("%d", &k);
    combinari(1);
    return 0;
}