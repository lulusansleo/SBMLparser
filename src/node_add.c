/*
** EPITECH PROJECT, 2023
** SBML_parser
** File description:
** node add
*/

#include "my.h"

static node_t *copy_attributes(node_t *head, char **line)
{
    int j = 0;

    while (**line != '=') {
        head->name[j] = **line;
        ++*line;
        j++;
    }
    head->name[j] = '\0';
    *line += 2;
    j = 0;
    while (**line != '\"') {
        head->value[j] = **line;
        ++*line;
        j++;
    }
    head->value[j] = 0;
    return head;
}

node_t *add_node(node_t *head, char **line)
{
    node_t *tmp = head;
    node_t *new = malloc(sizeof (node_t));

    new->name = malloc(sizeof(char) * 100);
    new->value = malloc(sizeof (char) * 100);
    new = copy_attributes(new, line);
    new->next = NULL;
    if (head == NULL)
        return new;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    return head;
}
