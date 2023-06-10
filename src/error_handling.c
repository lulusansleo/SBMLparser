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
    if (ac == 2)
        return 0;
    for (int i = 2; av[i]; i++) {
        if (strcmp(av[i], "-i") == 0 && !av[i + 1]) {
            exit(0);
        }
        if (av[i][0] == '-' && !is_flag(av[i][1]))
            return 1;
    }
    return 0;
}
