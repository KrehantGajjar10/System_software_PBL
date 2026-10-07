#include <stdio.h>
#include <string.h>

void macroProcessor()
{
    char macroName[30];
    char instructions[10][100];
    char argument[30];

    int count;

    printf("\n--- MACRO PROCESSOR ---\n");

    printf("Enter macro name: ");
    scanf("%s", macroName);

    printf("Enter number of instructions: ");
    scanf("%d", &count);

    getchar();

    printf("\nEnter macro instructions:\n");

    for (int i = 0; i < count; i++)
    {
        printf("%d: ", i + 1);
        fgets(instructions[i], sizeof(instructions[i]), stdin);

        instructions[i][strcspn(instructions[i], "\n")] = '\0';
    }

    printf("\nEnter argument: ");
    scanf("%s", argument);

    printf("\n===== MACRO EXPANSION =====\n");

    printf("Macro: %s\n", macroName);
    printf("Argument: %s\n\n", argument);

    for (int i = 0; i < count; i++)
    {
        char result[100];
        char *position;

        strcpy(result, instructions[i]);

        position = strstr(result, "&X");

        if (position != NULL)
        {
            char temp[100];

            *position = '\0';

            strcpy(temp, result);
            strcat(temp, argument);
            strcat(temp, position + 2);

            strcpy(result, temp);
        }

        printf("%s\n", result);
    }
}