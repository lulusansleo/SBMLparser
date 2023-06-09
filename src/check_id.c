/*
** EPITECH PROJECT, 2023
** SBML_parser
** File description:
** check_id
*/

#include "my.h"

int check_id(tag_t *tag, char *to_check, char *category)
{
    node_t *tmp = tag->attributes;

    while (tmp != NULL) {
        if (strcmp(to_check, tmp->value) == 0 &&
        strcmp(category, tmp->name) == 0)
            return 1;
        tmp = tmp->next;
    }
    return 0;
}
