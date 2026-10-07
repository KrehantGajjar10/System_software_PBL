#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void lexicalAnalyzer()
{
    char input[200];
    int i = 0;

    char *keywords[] = {
        "int", "float", "char", "if", "else"
    };

    printf("\n--- LEXICAL ANALYZER ---\n");
    printf("Enter a statement: ");

    getchar();
    fgets(input, sizeof(input), stdin);

    printf("\n%-15s %-15s\n", "TOKEN", "TYPE");
    printf("--------------------------------\n");

    while (input[i] != '\0' && input[i] != '\n')
    {
        char token[50];
        int j = 0;
        int found = 0;

        /* Ignore spaces */
        if (input[i] == ' ' || input[i] == '\t')
        {
            i++;
            continue;
        }

        /* Identifier or Keyword */
        if (isalpha(input[i]) || input[i] == '_')
        {
            while (isalnum(input[i]) || input[i] == '_')
            {
                token[j++] = input[i];
                i++;
            }

            token[j] = '\0';

            for (int k = 0; k < 5; k++)
            {
                if (strcmp(token, keywords[k]) == 0)
                {
                    printf("%-15s %-15s\n", token, "Keyword");
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                printf("%-15s %-15s\n", token, "Identifier");
            }
        }

        /* Integer Constant */
        else if (isdigit(input[i]))
        {
            while (isdigit(input[i]))
            {
                token[j++] = input[i];
                i++;
            }

            token[j] = '\0';

            printf("%-15s %-15s\n", token, "Constant");
        }

        /* Operators */
        else if (input[i] == '+' ||
                 input[i] == '-' ||
                 input[i] == '*' ||
                 input[i] == '/' ||
                 input[i] == '=')
        {
            printf("%-15c %-15s\n",
                   input[i], "Operator");

            i++;
        }

        /* Special Symbols */
        else if (input[i] == ';' ||
                 input[i] == ',' ||
                 input[i] == '(' ||
                 input[i] == ')' ||
                 input[i] == '{' ||
                 input[i] == '}' ||
                 input[i] == '[' ||
                 input[i] == ']')
        {
            printf("%-15c %-15s\n",
                   input[i], "Special Symbol");

            i++;
        }

        /* Unknown character */
        else
        {
            printf("%-15c %-15s\n",
                   input[i], "Unknown");

            i++;
        }
    }
}


struct Symbol
{
    char name[20];
    char type[20];
    int value;
    int address;
};

void symbolTable()
{
    struct Symbol table[20];

    char input[200];
    char *token;

    int count = 0;

    printf("\n--- SYMBOL TABLE ---\n");
    printf("Enter data in this format:\n");
    printf("int a 10 float b 20\n\n");

    getchar();
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    token = strtok(input, " ");

    while (token != NULL && count < 20)
    {
        strcpy(table[count].type, token);

        token = strtok(NULL, " ");
        if (token == NULL)
            break;

        strcpy(table[count].name, token);

        token = strtok(NULL, " ");
        if (token == NULL)
            break;

        table[count].value = atoi(token);
        table[count].address = 1000 + count * 4;

        count++;

        token = strtok(NULL, " ");
    }

    printf("\n%-10s %-10s %-10s %-10s\n",
           "Name", "Type", "Value", "Address");

    printf("----------------------------------------\n");

    for (int i = 0; i < count; i++)
    {
        printf("%-10s %-10s %-10d %-10d\n",
               table[i].name,
               table[i].type,
               table[i].value,
               table[i].address);
    }
}