#include <stdio.h>
#include <string.h>

char input[100];
int position;
int error;

void E();
void T();
void F();

void E()
{
    T();

    if (error)
        return;

    if (input[position] == '+')
    {
        position++;

        if (input[position] == '\0')
        {
            error = 1;
            return;
        }

        E();
    }
}

void T()
{
    F();

    if (error)
        return;

    if (input[position] == '*')
    {
        position++;

        if (input[position] == '\0')
        {
            error = 1;
            return;
        }

        T();
    }
}

void F()
{
    if (input[position] == 'i')
    {
        position++;
    }
    else if (input[position] == '(')
    {
        position++;

        E();

        if (error)
            return;

        if (input[position] == ')')
        {
            position++;
        }
        else
        {
            error = 1;
        }
    }
    else
    {
        error = 1;
    }
}


/* ================= RECURSIVE DESCENT PARSER ================= */

void recursiveDescentParser()
{
    printf("\n--- RECURSIVE DESCENT PARSER ---\n");

    printf("\nGrammar:\n");
    printf("E -> T + E | T\n");
    printf("T -> F * T | F\n");
    printf("F -> (E) | i\n");

    printf("\nEnter expression using i, +, *, (, ): ");

    scanf("%s", input);

    position = 0;
    error = 0;

    E();

    if (position == strlen(input) && error == 0)
    {
        printf("\nExpression Accepted.\n");
    }
    else
    {
        printf("\nExpression Rejected.\n");
    }
}


/* ================= QUADRUPLE GENERATOR ================= */

struct Quadruple
{
    char op[5];
    char arg1[20];
    char arg2[20];
    char result[20];
};

void quadrupleGenerator()
{
    char postfix[100];
    char stack[50][20];

    int top = -1;
    int tempCount = 1;
    int quadCount = 0;

    struct Quadruple quad[50];

    printf("\n--- QUADRUPLE GENERATOR ---\n");

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char ch = postfix[i];

        /* Operand */
        if (ch >= 'a' && ch <= 'z')
        {
            char operand[2];

            operand[0] = ch;
            operand[1] = '\0';

            strcpy(stack[++top], operand);
        }

        /* Operator */
        else if (ch == '+' ||
                 ch == '-' ||
                 ch == '*' ||
                 ch == '/')
        {
            char arg1[20];
            char arg2[20];
            char result[20];

            strcpy(arg2, stack[top--]);
            strcpy(arg1, stack[top--]);

            sprintf(result, "t%d", tempCount++);

            quad[quadCount].op[0] = ch;
            quad[quadCount].op[1] = '\0';

            strcpy(quad[quadCount].arg1, arg1);
            strcpy(quad[quadCount].arg2, arg2);
            strcpy(quad[quadCount].result, result);

            quadCount++;

            strcpy(stack[++top], result);
        }
    }

    printf("\n===== QUADRUPLE TABLE =====\n");

    printf("%-10s %-10s %-10s %-10s\n",
           "Operator",
           "Arg1",
           "Arg2",
           "Result");

    printf("----------------------------------------\n");

    for (int i = 0; i < quadCount; i++)
    {
        printf("%-10s %-10s %-10s %-10s\n",
               quad[i].op,
               quad[i].arg1,
               quad[i].arg2,
               quad[i].result);
    }
}