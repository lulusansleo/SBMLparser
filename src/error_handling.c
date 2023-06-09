/*
** EPITECH PROJECT, 2023
** SBML_parser
** File description:
** error_handling
*/

#include "my.h"

static int is_flag(char c)
{
    if (c == 'i' || c == 'j' || c == 'e')
        return 1;
    return 0;
}

int error_handling(int ac, char **av)
{
    if (ac <= 1)
        return 1;
    for (int i = 0; av[i]; i++) {
        if (strcmp(av[i], "-i") == 0 && !av[i + 1])
            return 1;
        printf("%d\n", i);
        if (av[i][0] == '-' && !is_flag(av[i][1]))
            return 1;
    }
    return 0;
}
