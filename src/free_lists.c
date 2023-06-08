/*
** EPITECH PROJECT, 2023
** SBML_parser
** File description:
** free_lists
*/

#include "my.h"

static void free_nodes(node_t *head)
{
    node_t *tmp = head;

    while (tmp != NULL) {
        tmp = tmp->next;
        free(head->name);
        free(head->value);
        free(head);
        head = tmp;
    }
}

void free_tags(tag_t *head)
{
    tag_t *tmp = head;

    while (tmp != NULL) {
        tmp = tmp->next;
        free(head->name);
        free_nodes(head->attributes);
        free(head);
        head = tmp;
    }
}
