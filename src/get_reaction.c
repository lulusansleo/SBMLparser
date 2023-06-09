/*
** EPITECH PROJECT, 2023
** SBML_parser
** File description:
** get_reaction
*/

#include "my.h"

char *get_reaction(char *str, char *reaction)
{
    char *ptr = strstr(str, "id=");
    int j = 0;

    if (strstr(str, "reaction") != NULL &&
    strstr(str, "/reaction") == NULL) {
        reaction = malloc(sizeof (char) * 100);
        while (*ptr != '=')
            ++ptr;
        ptr += 2;
        while (isalnum(*ptr)) {
            reaction[j] = *ptr;
            ++ptr;
            j++;
        }
        reaction[j] = '\0';
        return reaction;
    }
    if (strstr(str, "/reaction") != NULL)
        free(reaction);
    return reaction;
}

node_t *add_react(node_t *head, int react, char *reaction)
{
    node_t *tmp = head;
    node_t *new = malloc(sizeof (node_t));
    node_t *reactant = malloc(sizeof (node_t));
    char reacto[2] = "0";

    reacto[0] += react;
    reactant->name = strdup("reactant");
    reactant->value = strdup(reacto);
    new->name = strdup("reaction");
    new->value = strdup(reaction);
    new->next = reactant;
    reactant->next = NULL;
    if (head == NULL)
        return new;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    return head;
}

int shortener(tag_t *tmp, char *to_check, tag_t *head)
{
    if (strcmp(tmp->name, "species") == 0 &&
    check_id(tmp, to_check, "id")) {
        print_species(head, to_check);
        return 1;
    }
    return 0;
}
