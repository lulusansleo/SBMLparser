/*
** EPITECH PROJECT, 2023
** SBML_parser
** File description:
** more print functs
*/

#include "my.h"

tag_t *get_reactions(tag_t *head)
{
    tag_t *tmp = head;
    tag_t *tmp_head = head;
    tag_t *set_next = tmp;

    while (strcmp(tmp_head->name, "reaction") != 0) {
        tmp_head = tmp_head->next;
    }
    tmp = tmp_head;
    while (strcmp(tmp->name, "sbml") != 0) {
        tmp = tmp->next;
    }
    while (set_next->next != tmp)
        set_next = set_next->next;
    set_next->next = NULL;
    free_tags(tmp);
    return tmp_head;
}

void print_only_species(tag_t *head)
{
    tag_t *tmp = get_species(head);

    sort_tags_special(tmp, "name");
    printf("List of species\n");
    while (tmp != NULL) {
        printf("%s\n", what_attribute("name", tmp->attributes));
        tmp = tmp->next;
    }
}

void print_species(tag_t *head, char *to_check)
{
    tag_t *tmp = get_reactions(head);

    sort_tags_special(tmp, "id");
    printf("List of reactions consuming species %s (quantities)\n", to_check);
    while (tmp != NULL) {
        if (check_id(tmp, to_check, "reaction"))
            printf("--->%s\n", what_attribute("id", tmp->attributes));
        tmp = tmp->next;
    }
}
