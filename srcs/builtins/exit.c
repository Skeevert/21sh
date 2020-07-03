#include "sh21.h"
#include "builtins.h"

int				btin_exit(t_ltree *pos) //поправить
{
	int			status;

	ft_putendl_fd("exit", 1);
	destruct_globals();
	if (pos->ar_c > 1)
        status = ft_atoi(pos->ar_v[1]);
    else
        status = 0;
	exit(status);
}
