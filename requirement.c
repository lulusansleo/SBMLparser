/*
** EPITECH PROJECT, 2023
** SBML_parser
** File description:
** str_to_word_array
*/

#include <stdio.h>
#include <stdlib.h>

static int is_alpha_num(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    if (c >= 'a' && c <= 'z')
        return 1;
    if (c >= 'A' && c <= 'Z')
        return 1;
    return 0;
}

static int count_words(char const *str)
{
    int wcount = 0;
    int add = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        while (is_alpha_num(str[i])) {
            add = 1;
            i++;
        }
        wcount += add;
        add = 0;
    }
    return wcount;
}

static char *write_word(char const *str, int *i)
{
    int len = 0;
    char *word = NULL;
    int a = 0;

    for (int index = *i; is_alpha_num(str[index]); index++)
        len++;
    word = malloc(sizeof (char) * (len + 1));
    if (!word)
        return NULL;
    word[len] = '\0';
    while (is_alpha_num(str[*i])) {
        word[a] = str[*i];
        a++;
        *i += 1;
    }
    return word;
}

char **my_str_to_word_array_synthesis(char const *str)
{
    int wcount = count_words(str);
    char **array = NULL;
    int *i = malloc(sizeof (int));
    int j;
    int local_i = 0;

    array = malloc(sizeof (char *) * (wcount + 1));
    array[wcount] = NULL;
    for (*i = 0, j = 0; str[*i] != '\0'; *i += 1) {
        if (is_alpha_num(str[*i])) {
            array[j] = write_word(str, i);
            j++;
        }
        if (!array[j])
            return NULL;
    }
    return array;
}
