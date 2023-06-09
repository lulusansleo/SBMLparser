/*
** EPITECH PROJECT, 2023
** SBML_parser
** File description:
** main include file
*/

#ifndef MY_H
    #define MY_H

    #include <string.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <stdio.h>

    typedef struct node {
        char *name;
        char *value;
        struct node *next;
    } node_t;

    typedef struct tag {
        char *name;
        node_t *attributes;
        struct tag *next;
    } tag_t;

    //free_array
    void free_array(char **array);

    char *read_file(char const *filepath);

    char **my_separator(char *str, char sep);

    node_t *add_node(node_t *head, char **line);

    tag_t *parser(char *str);

    void free_tags(tag_t *head);

    void print_tags(tag_t *head);

    void sort_attributes(node_t *head);

    int error_handling(int ac, char **av);

    void sort_tags(tag_t *head);
#endif /* !MY_H */
