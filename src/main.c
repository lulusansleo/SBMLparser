/*
** EPITECH PROJECT, 2023
** SBML_parser
** File description:
** main
*/

#include "my.h"

static void print_usage(void)
{
    printf("USAGE\n\t./SBMLparser SBMLfile [-i ID [-e]] [-json]\n\n");
    printf("DESCRIPTION\n\tSBMLfile\tSBML file\n\t-i\tID id of the");
    printf("compartment, reaction or product to be extracted\n");
    printf("\t(ignored if uncorrect)\n\t-e\tprint the equation if a");
    printf("\treaction ID is given as argument\n\t(ignored otherwise)\n");
    printf("\t-json\ttransform the file into a JSON file\n");
}

int main(int ac, char **av)
{
    char *str = NULL;
    tag_t *tags = NULL;

    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        print_usage();
        return 0;
    }
    if (error_handling(ac, av)) {
        print_usage();
        return 84;
    }
    str = read_file(av[1]);
    tags = parser(str);
    print_tags(tags);
    free_tags(tags);
    free(str);
    return 0;
}
