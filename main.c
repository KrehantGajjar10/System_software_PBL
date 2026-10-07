#include <stdio.h>

void lexicalAnalyzer();
void symbolTable();
void twoPassAssembler();
void macroProcessor();
void recursiveDescentParser();
void quadrupleGenerator();

int main()
{
    int choice;

    while (1)
    {
        printf("\n====================================\n");
        printf("      SYSTEM SOFTWARE TOOLKIT\n");
        printf("====================================\n");
        printf("1. Lexical Analyzer\n");
        printf("2. Symbol Table\n");
        printf("3. Two Pass Assembler\n");
        printf("4. Macro Processor\n");
        printf("5. Recursive Descent Parser\n");
        printf("6. Quadruple Generator\n");
        printf("7. Exit\n");
        printf("====================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                lexicalAnalyzer();
                break;

            case 2:
                symbolTable();
                break;

            case 3:
                twoPassAssembler();
                break;

            case 4:
                macroProcessor();
                break;

            case 5:
                recursiveDescentParser();
                break;

            case 6:
                quadrupleGenerator();
                break;

            case 7:
                printf("\nExiting System Software Toolkit...\n");
                return 0;

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}