/*
** EPITECH PROJECT, 2023
** SBML_parser
** File description:
** json
*/

int check_json(char *av, int flag)
{
    if (strcmp(av, "-json") == 0 && flag % 2 == 1)
        flag = 3;
    return flag;
}
