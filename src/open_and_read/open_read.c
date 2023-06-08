/*
** EPITECH PROJECT, 2023
** SBML_parser
** File description:
** open_read_file
*/

#include "my.h"

char *read_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat st;
    char *str = NULL;

    if (fd == -1)
        return NULL;
    if (stat(filepath, &st) == -1)
        return NULL;
    str = malloc(sizeof (char) * (st.st_size + 1));
    if (!str)
        return NULL;
    if (read(fd, str, st.st_size) <= 0)
        return NULL;
    str[st.st_size] = '\0';
    close(fd);
    return str;
}
