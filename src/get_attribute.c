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

void print_react_no_e(tag_t *tmp, tag_t *head, char *to_check)
{
    printf("List of reactants of reaction %s\n", to_check);
    while (tmp != NULL) {
        if (strcmp(what_attribute("reaction", tmp->attributes), to_check) == 0
        && strcmp(what_attribute("reactant", tmp->attributes), "1") == 0)
            printf("--->%s\n", what_attribute("species", tmp->attributes));
        tmp = tmp->next;
    }
    printf("List of products of reaction %s\n", to_check);
    tmp = get_references(head);
    while (tmp != NULL) {
        if (strcmp(what_attribute("reaction", tmp->attributes), to_check) == 0
        && strcmp(what_attribute("reactant", tmp->attributes), "2") == 0)
            printf("--->%s\n", what_attribute("species", tmp->attributes));
        tmp = tmp->next;
    }
}

static void print_plus(int plus)
{
    if (plus == 1)
        printf(" + ");
}

static void second_part(tag_t *tmp, tag_t *head, char *to_check)
{
    int plus = 0;

    tmp = get_references(head);
    while (tmp != NULL) {
        if (strcmp(what_attribute("reaction", tmp->attributes), to_check) == 0
        && strcmp(what_attribute("reactant", tmp->attributes), "2") == 0) {
            print_plus(plus);
            plus = 1;
            printf("%s %s", what_attribute("stoichiometry", tmp->attributes),
            what_attribute("species", tmp->attributes));
        }
        tmp = tmp->next;
    }
    printf("\n");
}

void print_react_e(tag_t *tmp, tag_t *head, char *to_check, char *reversible)
{
    int rev = 0;
    int plus = 0;
    if (strcmp(reversible, "true") == 0)
        rev = 1;
    while (tmp != NULL) {
        if (strcmp(what_attribute("reaction", tmp->attributes), to_check) == 0
        && strcmp(what_attribute("reactant", tmp->attributes), "1") == 0) {
            print_plus(plus);
            plus = 1;
            printf("%s %s", what_attribute("stoichiometry", tmp->attributes),
            what_attribute("species", tmp->attributes));
        }
        tmp = tmp->next;
    }
    if (rev)
        printf(" <-> ");
    else
        printf(" -> ");
    second_part(tmp, head, to_check);
}
