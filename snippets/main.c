#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "snippets.h"

const int func_cnt = 3;

int check_fargs(int argc, int threshold);

// Funcitons: add, delete, modify
// next steps: make an online version with js (node) that also has a database

int main(int argc, char **argv)
{
    check_fargs(argc, 2);
    
    if (argv[1][0] != '-' || argc < 2)
    {
        printf("Nothing to do.\n");
        return 1;
    }

    switch (argv[1][1])
    {
        case 'a':
            printf("add\n");
            check_fargs(argc, 4);

            snippet input;

            input.name = strcat(argv[2], "\n\n");
            input.content = strcat(argv[3],"\n\n");
            get_size(&input);

            printf("%s", input.content);

            add(input);

            break;
        case 'd':
            printf("delete\n");
            break;
        case 'm':
            printf("modify\n");
            break;
        
        default:
            printf("E: Not a official function.\n");
            break;
    }
    
}

int check_fargs(int argc, int threshold)
{
    if (argc < threshold)
    {
        printf("E: Insufficient function arguments.\n");
        return 1;
    }

    return 0;
}