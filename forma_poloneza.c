#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100 // dimensiunea stivei

void push(char *stack, char character, int *index)
{
    int i = *index;
    if (i == SIZE - 1)
    {
        // printf("Stiva este plina\n");
    }
    i = i + 1;
    stack[i] = character;
    *index = i;
}

char pop(char *stack, int *index)
{
    char character;
    int i = *index;
    if (i == -1)
    {
        // printf("Stiva este goala\n");
        return -1;
    }
    character = stack[i];
    i = i - 1;
    *index = i;
    return character;
}

int prioritate(char operator)
{
    switch (operator)
    {
    case '(':
    case ')':
    {
        return 0;
    }
    case '*':
    case '/':
    {
        return 1;
    }
    case '+':
    case '-':
    {
        return 2;
    }
    }
    return -1;
}

void printStack(char *stack, int index)
{
    int i;
    for (i = 0; i <= index; i++)
    {
        printf("%c", stack[i]);
    }
    printf("\n");
}

void swap(char *ch1, char *ch2)
{
    char aux;
    aux = *ch1;
    *ch1 = *ch2;
    *ch2 = aux;
}

void forma_poloneza(char *fp, char *st, int *sizefp, int *sizest)
{
    char character, poped_character, temporary_character, temporary_operator;
    int i, indexfp = *sizefp, indexst = *sizest;
    while ((character = getchar()) != '\n')
    {
        if (prioritate(character) == -1) // daca nu e operator
        {
            push(fp, character, &indexfp);
        }
        else // daca e operator
        {
            push(st, character, &indexst);
            if (prioritate(st[indexst - 1]) == prioritate(st[indexst])) // tratez cazul */ sau +-
            {
                swap(&st[indexst - 1], &st[indexst]);
                temporary_operator = pop(st, &indexst);
                push(fp, temporary_operator, &indexfp);
            }
            if (character == ')') // cazul in care se termina o expresie
            {
                pop(st, &indexst); // scoate ')'
                i = indexst;
                while (st[i] != '(')
                {
                    poped_character = pop(st, &indexst);
                    push(fp, poped_character, &indexfp);
                    i--;
                }
                pop(st, &indexst); // scoate '('
            }
            else
            {
                if (prioritate(character) == 2) // cazul in care avem +-
                {
                    temporary_character = pop(st, &indexst);
                    i = indexst;
                    while (prioritate(st[i]) == 1)
                    {
                        poped_character = pop(st, &indexst);
                        push(fp, poped_character, &indexfp);
                        i--;
                    }
                    push(st, temporary_character, &indexst);
                }
            }
        }
    }
    *sizefp = indexfp;
    *sizest = indexst;
}

void pushStiva(int *stack, int number, int *index)
{
    int i = *index;
    if (i == SIZE - 1)
    {
        // printf("Stiva este plina\n");
    }
    i = i + 1;
    stack[i] = number;
    *index = i;
}

int popStiva(int *stack, int *index)
{
    int number;
    int i = *index;
    if (i == -1)
    {
        // printf("Stiva este goala\n");
        return -1;
    }
    number = stack[i];
    i = i - 1;
    *index = i;
    return number;
}

void printStiva(int *stack, int index)
{
    int i;
    for (i = 0; i <= index; i++)
    {
        printf("%d", stack[i]);
    }
    printf("\n");
}

int calcul(int n1, int n2, char operator)
{
    switch (operator)
    {
    case '+':
    {
        return n1 + n2;
    }
    case '-':
    {
        return n1 - n2;
    }
    case '*':
    {
        return n1 * n2;
    }
    case '/':
    {
        return n1 / n2;
    }
    }
    return 0;
}

int calculExpresie(char *fp, int indexfp)
{
    int i, number, stiva[SIZE], index = -1, n1, n2, rezultat;
    char num[10];
    for (i = 0; i < indexfp; i++)
    {
        if (prioritate(fp[i]) == -1) // daca nu e operator
        {
            scanf("%9s", num);
            number = strtol(num, NULL, 10);
            pushStiva(stiva, number, &index);
        }
        else // daca e operator
        {
            n2 = popStiva(stiva, &index);
            n1 = popStiva(stiva, &index);
            rezultat = calcul(n1, n2, fp[i]);
            pushStiva(stiva, rezultat, &index);
        }
    }
    n2 = popStiva(stiva, &index);
    n1 = popStiva(stiva, &index);
    rezultat = calcul(n1, n2, fp[i]);
    return rezultat;
}

int main(void)
{
    char fp[SIZE], st[SIZE];
    int indexfp = -1, indexst = -1, rezultat;
    forma_poloneza(fp, st, &indexfp, &indexst);
    printStack(fp, indexfp);
    rezultat = calculExpresie(fp, indexfp);
    printf("%d\n", rezultat);
    return 0;
}