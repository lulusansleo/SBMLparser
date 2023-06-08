/*
** EPITECH PROJECT, 2023
** SBML_parser
** File description:
** str_sep
*/

#include "my.h"

static int is_not_sep(char c, char sep)
{
    if (c == sep || c == '\0')
        return 0;
    return 1;
}

static int count_words(char *str, char sep)
{
    int wcount = 0;
    int add = 0;
    int i;
    int len = strlen(str);

    for (i = 0; i < len; i++) {
        while (is_not_sep(str[i], sep)) {
            add = 1;
            i++;
        }
        wcount += add;
        add = 0;
    }
    return wcount;
}

char **my_separator(char *str, char sep)
{
    int len = count_words(str, sep);
    char **array = malloc(sizeof (char *) * (len + 1));
    char separator[2] = "*";

    separator[0] = sep;
    for (int i = 0; i < len; i++) {
        array[i] = strdup(strtok((i == 0 ? str : NULL), separator));
    }
    array[len] = NULL;
    return array;
}
