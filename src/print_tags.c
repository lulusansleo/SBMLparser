/*
** EPITECH PROJECT, 2023
** SBML_parser
** File description:
** print tags
*/

#include "my.h"

static void print_attributes(node_t *head)
{
    node_t *tmp = head;

    while (tmp != NULL) {
        printf("--->%s\n", tmp->name);
        tmp = tmp->next;
    }
}

void print_tags(tag_t *head)
{
    char *check = malloc(sizeof (char) * 100);
    tag_t *tmp = head;

    check[0] = 'a';
    while (tmp != NULL) {
        if (strcmp(check, tmp->name) != 0) {
            printf("%s\n", tmp->name);
            print_attributes(tmp->attributes);
        }
        check = strcpy(check, tmp->name);
        tmp = tmp->next;
    }
}