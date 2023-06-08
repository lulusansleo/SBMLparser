/*
** EPITECH PROJECT, 2023
** SBML_parser
** File description:
** free_array
*/

#include "my.h"

void free_array(char **array)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}
