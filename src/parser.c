/*
** EPITECH PROJECT, 2023
** SBML_parser
** File description:
** parser
*/

#include "my.h"

static char *copy_name(char *line, char *dest)
{
    int j = 0;

    while (!isalnum(*line))
        ++line;
    while (isalnum(*line)) {
        dest[j] = *line;
        j++;
        ++line;
    }
    dest[j] = '\0';
    return line;
}

static node_t *get_attributes(char *line, int react, char *reaction)
{
    node_t *head = NULL;

    for (size_t i = 0; i < strlen(line); i++) {
        if (isalnum(*line)) {
            head = add_node(head, &line);
        }
        ++line;
    }
    if (react != 0) {
        head = add_react(head, react, reaction);
    }
    return head;
}

static tag_t *add_tag(tag_t *tags, char *line, int react, char *reaction)
{
    tag_t *new_tag = malloc(sizeof(tag_t));
    tag_t *tmp = tags;
    char *cpy = line;

    new_tag->name = malloc(sizeof (char) * 50);
    new_tag->next = NULL;
    cpy = copy_name(cpy, new_tag->name);
    new_tag->attributes = get_attributes(cpy, react, reaction);
    sort_attributes(new_tag->attributes);
    if (tags == NULL)
        return new_tag;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new_tag;
    return tags;
}

static int is_list(char *str, int react)
{
    if (strstr(str, "listOfReactants") != NULL)
        react = 1;
    if (strstr(str, "listOfProducts") != NULL)
        react = 2;
    if (strstr(str, "/listOfReactants") != NULL ||
    strstr(str, "/listOfProducts") != NULL)
        react = 0;
    return react;
}

tag_t *parser(char *str)
{
    tag_t *tags = NULL;
    char **lines = my_separator(str, '\n');
    int react = 0;
    char *reaction = NULL;

    for (int i = 0; lines[i] != NULL; i++) {
        react = is_list(lines[i], react);
        reaction = get_reaction(lines[i], reaction);
        if (strstr(lines[i], "/>") != NULL || strstr(lines[i], " >") != NULL) {
            tags = add_tag(tags, lines[i], react, reaction);
        }
    }
    free_array(lines);
    sort_tags(tags);
    return tags;
}
