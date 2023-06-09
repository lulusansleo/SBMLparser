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

static void print_compartment(tag_t *head, char *to_check)
{
    tag_t *tmp = get_species(head);

    sort_tags_special(tmp, "name");
    printf("List of species in compartment %s\n", to_check);
    while (tmp != NULL) {
        if (check_id(tmp, to_check, "compartment"))
            printf("--->%s\n", what_attribute("name", tmp->attributes));
        tmp = tmp->next;
    }
}

static void print_i(tag_t *head, int flag, char *to_check)
{
    tag_t *tmp = head;

    while (tmp != NULL) {
        if (strcmp(tmp->name, "compartment") == 0 &&
        check_id(tmp, to_check, "id")) {
            print_compartment(tmp, to_check);
        }
        tmp = tmp->next;
    }
}

void print_functions(tag_t *head, char **av)
{
    int flag = 0;
    char *to_check;

    for (int i = 0; av[i]; i++) {
        if (strcmp(av[i], "-i") == 0) {
            to_check = strdup(av[i + 1]);
            flag += 1;
        }
        if (strcmp(av[i], "-e") == 0) {
            flag += 1;
        }
    }
    if (!flag)
        print_tags(head);
    else
        print_i(head, flag, to_check);
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
