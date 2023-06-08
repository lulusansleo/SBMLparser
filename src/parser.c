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

static node_t *get_attributes(char *line)
{
    node_t *head = NULL;

    for (size_t i = 0; i < strlen(line); i++) {
        if (isalnum(*line)) {
            head = add_node(head, &line);
        }
        ++line;
    }
    return head;
}

static tag_t *add_tag(tag_t *tags, char *line)
{
    tag_t *new_tag = malloc(sizeof(tag_t));
    tag_t *tmp = tags;
    char *cpy = line;

    new_tag->name = malloc(sizeof (char) * 50);
    new_tag->next = NULL;
    cpy = copy_name(cpy, new_tag->name);
    new_tag->attributes = get_attributes(cpy);
    if (tags == NULL)
        return new_tag;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new_tag;
    return tags;
}

tag_t *parser(char *str)
{
    tag_t *tags = NULL;
    char **lines = my_separator(str, '\n');

    for (int i = 0; lines[i] != NULL; i++) {
        if (strstr(lines[i], "/>") != NULL || strstr(lines[i], " >") != NULL) {
            tags = add_tag(tags, lines[i]);
        }
    }
    free_array(lines);
    return tags;
}
