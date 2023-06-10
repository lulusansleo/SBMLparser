/*
** EPITECH PROJECT, 2023
** SBML_parser
** File description:
** sort list
*/

#include "my.h"

static void swap_attributes(node_t **first, node_t **second)
{
    char *tmp = (*first)->name;

    (*first)->name = (*second)->name;
    (*second)->name = tmp;
    tmp = (*first)->value;
    (*first)->value = (*second)->value;
    (*second)->value = tmp;
}

void swap(tag_t **first, tag_t **second)
{
    char *first_string = strdup((*first)->name);
    char *second_string = strdup((*second)->name);
    node_t *tmp = (*first)->attributes;

    free((*second)->name);
    free((*first)->name);
    (*first)->attributes = (*second)->attributes;
    (*second)->attributes = tmp;
    (*second)->name = first_string;
    (*first)->name = second_string;
}

void sort_tags(tag_t *head)
{
    int swap_check = 0;
    tag_t *tmp;
    tag_t *previous = NULL;

    do {
        swap_check = 0;
        tmp = head;
        while (tmp->next != previous) {
            if (strcmp(tmp->name, tmp->next->name) > 0) {
                swap(&tmp, &tmp->next);
                swap_check = 1;
            }
            tmp = tmp->next;
        }
        previous = tmp;
    } while (swap_check);
}

void sort_attributes(node_t *head)
{
    int swap_check = 0;
    node_t *tmp;
    node_t *previous = NULL;

    if (head == NULL)
        return;
    do {
        swap_check = 0;
        tmp = head;
        while (tmp->next != previous) {
            if (strcmp(tmp->name, tmp->next->name) > 0) {
                swap_attributes(&tmp, &tmp->next);
                swap_check = 1;
            }
            tmp = tmp->next;
        }
        previous = tmp;
    } while (swap_check);
}
