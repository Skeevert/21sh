#include "sh21.h"
#include "builtins.h"

int     parse_echo_flags(char **argv, t_ec *echo_flags)
{
    int     i;
    int     j;

    i = 1;
    echo_flags->n = 0;
    echo_flags->e = 0;
    echo_flags->up_e = 0;
    while (argv[i] && argv[i][0] == '-')
    {
        j = 1;
        while (argv[i][j])
        {
            if (argv[i][j] == 'e')
                echo_flags->e = 1;
            else if (argv[i][j] == 'n')
                echo_flags->n = 1;
            else if (argv[i][j] == 'E')
                echo_flags->up_e = 1;
            else
                return (i);
            j++;
        }
        i++;
    }
    return (i);
}

void     write_back_sl(char c)
{
    if (c == 'a')
        write(1, "\a", 1);
    else if (c == 'b')
        write(1, "\b", 1);
    else if (c == 'f')
        write(1, "\f", 1);
    else if (c == 'n')
        write(1, "\n", 1);
    else if (c == 'r')
        write(1, "\r", 1);
    else if (c == 't')
        write(1, "\t", 1);
    else if (c == 'v')
        write(1, "\v", 1);
    else if (c == 'e')
        write(1, "\033", 1);
}

void     write_e_echo(char **argv, int i)
{
    int j;

    while (argv[i])
    {
        j = 0;
        while (argv[i][j])
        {
            if (argv[i][j] != '\\')
                write(1, &(argv[i][j]), 1);
            else
            {
                j++;
                write_back_sl(argv[i][j]);
            }
            j++;
        }
        i++;
        if (argv[i])
            write(1, " ", 1);
    }
}

void     write_text(char **argv, int i, t_ec *echo_flags)
{
    //printf("input str = %s\n", argv[i]);
    if (echo_flags->e && !echo_flags->up_e)
        write_e_echo(argv, i);
    else
    {
        while (argv[i])
        {
            write(1, argv[i], ft_strlen(argv[i]));
            i++;
            if (argv[i])
                write(1, " ", 1);
        }
    }
    if (!echo_flags->n)
        write(1, "\n", 1);
}

int     btin_echo(t_ltree *pos)
{
    t_ec    *echo_flags;
    int     i;

    echo_flags = ft_xmalloc(sizeof(t_ec *));
    i = parse_echo_flags(pos->ar_v, echo_flags);
    write_text(pos->ar_v, i, echo_flags);
    free(echo_flags);
    return (0);
}
