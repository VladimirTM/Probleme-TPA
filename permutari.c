#include <stdio.h>

#define SIZE 100

int x[SIZE], n;

int verificare(int k)
{
    for (int i = 1; i < k; i++)
    {
        if (x[k] == x[i])
        {
            return 0;
        }
    }
    return 1;
}

int solutie(int k)
{
    return k == n;
}

void afisare()
{
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", x[i]);
    }
    printf("\n");
}

void permutari(int k)
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
                permutari(k + 1);
            }
        }
    }
}

int main(void)
{
    printf("Introdu numarul n: ");
    scanf("%d", &n);
    permutari(1);
    return 0;
}