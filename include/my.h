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

    void print_functions(tag_t *head, char **av);

    int check_id(tag_t *tag, char *to_check, char *category);

    char *what_attribute(char *want, node_t *head);

    void sort_tags_special(tag_t *head, char *want);

    void swap(tag_t **first, tag_t **second);

    tag_t *get_species(tag_t *head);

    void print_species(tag_t *head, char *to_check);

    void print_only_species(tag_t *head);

    void print_reactions(tag_t *head, char *to_check, int flag);
#endif /* !MY_H */
