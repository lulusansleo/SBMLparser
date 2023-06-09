/*
** EPITECH PROJECT, 2023
** SBML_parser
** File description:
** get_attribute
*/

#include "my.h"

char *what_attribute(char *want, node_t *head)
{
    node_t *tmp = head;

    while (tmp != NULL) {
        if (strcmp(want, tmp->name) == 0) {
            return tmp->value;
        }
        tmp = tmp->next;
    }
    return NULL;
}
