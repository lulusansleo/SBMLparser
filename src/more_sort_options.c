/*
** EPITECH PROJECT, 2023
** SBML_parser
** File description:
** more list sort options
*/

#include "my.h"

tag_t *get_species(tag_t *head)
{
    tag_t *tmp = head;
    tag_t *tmp_head = head;
    tag_t *set_next = tmp;

    while (strcmp(tmp_head->name, "species") != 0)
        tmp_head = tmp_head->next;
    tmp = tmp_head;
    while (strcmp(tmp->name, "speciesReference") != 0) {
        tmp = tmp->next;
    }
    while (set_next->next != tmp)
        set_next = set_next->next;
    set_next->next = NULL;
    free_tags(tmp);
    return tmp_head;
}

tag_t *get_references(tag_t *head)
{
    tag_t *tmp = head;
    tag_t *tmp_head = head;
    tag_t *set_next = tmp;

    while (strcmp(tmp_head->name, "speciesReference") != 0)
        tmp_head = tmp_head->next;
    tmp = tmp_head;
    return tmp_head;
}

void sort_tags_special(tag_t *head, char *want)
{
    int swap_check = 0;
    tag_t *tmp;
    tag_t *previous = NULL;
    do {
        swap_check = 0;
        tmp = head;
        while (tmp->next != previous) {
            if (strcmp(what_attribute(want, tmp->attributes),
            what_attribute(want, tmp->next->attributes)) > 0) {
                swap(&tmp, &tmp->next);
                swap_check = 1;
            }
            tmp = tmp->next;
        }
        previous = tmp;
    } while (swap_check);
}
