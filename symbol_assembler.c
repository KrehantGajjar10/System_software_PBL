#include <stdio.h>
#include <string.h>

struct AsmSymbol
{
    char name[20];
    int address;
};

struct Instruction
{
    int address;
    char label[20];
    char opcode[20];
    char operand[20];
};

void twoPassAssembler()
{
    struct AsmSymbol symtab[20];
    struct Instruction instructions[50];

    char line[100];
    char part1[20], part2[20], part3[20];

    int symCount = 0;
    int instructionCount = 0;
    int location = 100;

    printf("\n--- TWO PASS ASSEMBLER ---\n");
    printf("Enter assembly code.\n");
    printf("Enter END to finish.\n\n");

    getchar();

    while (1)
    {
        printf("%d > ", location);

        fgets(line, sizeof(line), stdin);

        line[strcspn(line, "\n")] = '\0';

        if (strcmp(line, "END") == 0)
            break;

        part1[0] = '\0';
        part2[0] = '\0';
        part3[0] = '\0';

        int parts = sscanf(line, "%s %s %s",
                           part1, part2, part3);

        if (parts == 3)
        {
            strcpy(instructions[instructionCount].label, part1);
            strcpy(instructions[instructionCount].opcode, part2);
            strcpy(instructions[instructionCount].operand, part3);

            strcpy(symtab[symCount].name, part1);
            symtab[symCount].address = location;
            symCount++;
        }
        else if (parts == 2)
        {
            instructions[instructionCount].label[0] = '\0';
            strcpy(instructions[instructionCount].opcode, part1);
            strcpy(instructions[instructionCount].operand, part2);
        }
        else
        {
            instructions[instructionCount].label[0] = '\0';
            strcpy(instructions[instructionCount].opcode, part1);
            instructions[instructionCount].operand[0] = '\0';
        }

        instructions[instructionCount].address = location;

        instructionCount++;
        location++;
    }

    printf("\n===== PASS 1 : SYMBOL TABLE =====\n");

    printf("%-15s %-10s\n", "Symbol", "Address");
    printf("--------------------------\n");

    for (int i = 0; i < symCount; i++)
    {
        printf("%-15s %-10d\n",
               symtab[i].name,
               symtab[i].address);
    }

    printf("\n===== PASS 2 : MACHINE CODE =====\n");

    printf("%-10s %-15s %-15s %-10s\n",
           "Address", "Label", "Opcode", "Operand");

    printf("------------------------------------------------\n");

    for (int i = 0; i < instructionCount; i++)
    {
        int resolvedAddress = -1;

        for (int j = 0; j < symCount; j++)
        {
            if (strcmp(instructions[i].operand,
                       symtab[j].name) == 0)
            {
                resolvedAddress = symtab[j].address;
                break;
            }
        }

        if (resolvedAddress != -1)
        {
            printf("%-10d %-15s %-15s %d\n",
                   instructions[i].address,
                   instructions[i].label,
                   instructions[i].opcode,
                   resolvedAddress);
        }
        else
        {
            printf("%-10d %-15s %-15s %-10s\n",
                   instructions[i].address,
                   instructions[i].label,
                   instructions[i].opcode,
                   instructions[i].operand);
        }
    }
}